function [executeFlag, stDisNetCalMembers, stOutSdUnionSimData] = distri_network_strategy(stDisNetCalMembers, stInSuUnionSimData, cellNodeMapItemMap)
%distri_network_strategy  分布式网络算法，根据上行联合仿真数据计算得到下行联合仿真数据
%                  该函数首次调用时必须先执行 case eInteract_power_bus，然后进行后续操作，因此首次执行函数时，
%                  必须确保 stDisNetCalMembers.iterator_count = 0,且stDisNetCalMembers.b_is_first_handle_frequency = true，
%                  以及 stInSuUnionSimData 的个数为1。 
% 参数说明：
% stDisNetCalMembers : 包含字段：{'g_stPara','g_stState','g_stDgNodeArr','g_stUploadBusCommu','g_stDwloadBusCommu','iterator_count','b_is_first_handle_frequency'}；
%                            g_stPara：结构体，包含字段：{'B','L','D','Capacity','P_Demand','P_Realtime',
%                                                        'time','t_hold','step','beta','kappa','Freq','Kg'}；
%                            g_stState：结构体，包含字段：{'miu_pin','miu_trans_step','miu_hold_step','miu_previous_step',
%                                                        'flag_converge','flag_miu', 'miu_this_time','miu_previous_time'}；
%                            g_stDgNodeArr：结构体数组，个数5，每个结构体均包含字段：{'DG_NO','generation_value','simtime'}；    
%                            g_stUploadBusCommu：结构体，包含字段：{'PowerSimTime','PowerFrequency','BusNo',
%                                                                 'Startnode_ID','Destnode_ID','ErrorType','TimeDelay'}
%                            g_stDwloadBusCommu:结构体，包含字段和g_stUploadBusCommu相同。
%                            iterator_count：迭代次数，首次调用该函数时，此数值初始化为 0 
%                            b_is_first_handle_frequency：是否首次执行频率信息相关操作，初始化为 true
% stInSuUnionSimData       联合仿真上行数据，此为结构体，包含字段：
%                          { 'realtime','sim_time','comm_dat','power_dat'}
%                          其中，字段 comm_dat 也是一个结构体，包含字段：
%                          { 'src_id','dst_id', 'err_type','trans_delay'}
%                          而字段 power_dat 与上行数据的个数有关，如果传入的上行数据个数为 1，则
%                          power_dat 也是一个结构体，包含字段：{ 'bus_id',
%                          'power_sim_time','data_length','power_data_type','freq' }；
%                          否则，power_dat 是一个数值。
% cellNodeMapItemMap       读取的仿真应用配置中的电力配置信息中的节点映射信息，此参数为 m * 2 的元胞数组，格式为
%                          {NodeId, NodeMapItem}, NodeMapItem是一个结构体，包含三个字段：
%                              'power_bus_id', 电力母线编号
%                              'comm_src_id', 通信源节点编号
%                              'comm_dst_id', 通信目的节点编号
%                          该参数的数值为对 C++ 中的 _dw_node_map ：
%                          _sim_case_conf_info._power_conf_info._dw_node_map
%
%           
% stOutSdUnionSimData      联合仿真下行数据（出参），包含字段：
%                          { 'realtime',  'sim_time',  'comm_dat', 'power_dat'}
%                          comm_dat 字段对应一个结构体，包含字段：
%                               'src_id', 'dst_id', 'err_type','trans_delay'
%                          power_dat字段根据交互的类型不同，输出的内容不同，如下：
%                               1）EInteractType.eInteract_ctrl_to_power： stPowerDpNodeData
%                               2）EInteractType.eInteract_upload_bus：stPowerFreqInforData
%                               3）EInteractType.eIneract_ctrl_to_comm：data
% executeFlag               true：函数执行成功
%                           false：函数执行失败

%2018年12月15日 create
%2019年3月3日 modify
 
    cur_time = datestr(now,29);
    file_name = ['distri_network_', cur_time, '-log.txt']; %根据当前的时间命名log日志文件
    clear_error(file_name);%此处用于清除exception_error(file_name, ErrorInfo)记录的异常信息
    
    retVal = isstruct(stInSuUnionSimData);
    if false == retVal
        stOutSdUnionSimData = struct([]); % 如果传入的参数不是一个结构体，则返回0*0的空结构数组
        executeFlag = false;
        record_log( 2, file_name, 'distri_network_strategy: 入参 stInSuUnionSimData 非结构体.' );
        return;
    end
    
    % 定义全局变量 %
    global NODE_NUM; % 节点个数
    NODE_NUM = 5;

    try
        [result, stDisNetCalMembers(1).b_is_first_handle_frequency, ...
         cellDataStream] = encap_power_simdata_to_stream(stDisNetCalMembers(1).b_is_first_handle_frequency, stInSuUnionSimData);
        if result == false
            executeFlag = false;
            record_log( 2, file_name, 'distri_network_strategy: 调用函数 encap_power_simdata_to_stream 执行失败.' );
            return;
        end

        iterator_count = stDisNetCalMembers(1).iterator_count;
        g_stState = stDisNetCalMembers(1).g_stState;
        g_stPara = stDisNetCalMembers(1).g_stPara;
        g_stDgNodeArr = stDisNetCalMembers(1).g_stDgNodeArr;
        g_stUploadBusCommu = stDisNetCalMembers(1).g_stUploadBusCommu;
        g_stDwloadBusCommu = stDisNetCalMembers(1).g_stDwloadBusCommu;
        
        type = cellDataStream{1,1}.data_type;
        count = cellDataStream{1,1}.sim_data_count;
        switch type
            case EInteractType.eInteract_power_bus
                % 各种结构体字段说明
%                 g_stState = struct('miu_pin',{0},'miu_trans_step',{0},'miu_hold_step',{0},'miu_previous_step',{0},...
%                                   'flag_converge',{0},'flag_miu',{0}, 'miu_this_time',{0},'miu_previous_time',{0});
%                 g_stPara = struct('B',{0},'L',{0},'D',{0},'Capacity',{0},'P_Demand',{0},'P_Realtime',{0},...
%                                    'time',{0},'t_hold',{0},'step',{0},'beta',{0},'kappa',{0},'Freq',{0},'Kg',{0});
%                 dgNodeCell = {0};
%                 dgNode5Cell = repmat(dgNodeCell, 1, 5);
%                 g_stDgNodeArr = struct('DG_NO',dgNode5Cell,'generation_value',dgNode5Cell,'simtime',dgNode5Cell);
%                 % 通信软件与电力应用交互母线信息
%                 g_stUploadBusCommu = struct('PowerSimTime',{0},'PowerFrequency',{0},'BusNo',{0},...
%                                              'Startnode_ID',{0},'Destnode_ID',{0},'ErrorType',{0},'TimeDelay',{0});
                
                [g_stState, g_stPara, g_stDgNodeArr] = initialize_env();

                % 初始化全局通信与电力应用交互母线信息
                stBusInfo = cellDataStream{1,2};
                [g_stUploadBusCommu] = generate_upload_sample_freq(stBusInfo, g_stUploadBusCommu);    

                stOutDataStreamHeader = struct('data_type',{0},'sim_data_count',{0});
                stOutDataStreamHeader.data_type = EInteractType.eInteract_upload_bus;
                stOutDataStreamHeader.sim_data_count = 1;
                % 通信软件下发至控制算法DG节点数据结构体
                stBusCommuUpload = g_stUploadBusCommu; % 这里不改变g_stUploadBusCommu原有的值
                stOutSdUnionSimDataCell = {stOutDataStreamHeader, stBusCommuUpload};

            case EInteractType.eInteract_download_bus   
                stBusInfoCommu = cellDataStream{1,2};
                [g_stState, g_stPara, g_stDwloadBusCommu] = config_param_state(g_stState, g_stPara, stBusInfoCommu);
                % stSendDGCommuCtrlArr
                % 这里定义结构字段的值必须为空，即初始化时没有该数据，通过下面的函数Generate_Upload_Iterator_data
                % 生成
                stSendDGCommuCtrlArr = struct('PowerSimTime',{},'Converge_Flag',{},'Startnode_ID',{},'Destnode_ID',{},...
                                              'TimeDelay',{},'ErrorType',{},'data',{});
                [stOutSdUnionSimDataCell, iterator_count] = Generate_Upload_Iterator_data(g_stState, g_stPara, iterator_count,...
                                                                                          stSendDGCommuCtrlArr);
            case EInteractType.eIneract_comm_to_ctrl
                cellUnitCommuCtrl = {0};
                cellCommuCtrl = repmat(cellUnitCommuCtrl, 1, count);
                % 初始化接收的通信至控制算法DG节点数据，个数为count
                stRcvCommuCtrlArr = struct('PowerSimTime',cellCommuCtrl,'Converge_Flag',cellCommuCtrl,'Startnode_ID',cellCommuCtrl,...
                                           'Destnode_ID',cellCommuCtrl,'TimeDelay',cellCommuCtrl,...
                                           'ErrorType',cellCommuCtrl,'data',cellCommuCtrl);
                stCommuCtrlTemp = cellDataStream{1,2};
                for id = 1 : count
                    stRcvCommuCtrlArr(id) = stCommuCtrlTemp(id);
                end

                cellUnitCtrlToGrid = {0};
                cellCtrlToGrid = repmat(cellUnitCtrlToGrid, 1, 5);
                % 电力控制算法下发至电力软件结构体
                stCtrlToGridArr = struct('DG_node_ID',cellCtrlToGrid,'PowerUpadateTime',cellCtrlToGrid,'dP',cellCtrlToGrid);
                
                [flag,g_stState, g_stPara,stCtrlToGridArr,...
                 stRcvCommuCtrlArr] = iterator_calculate(g_stState,g_stPara, g_stDgNodeArr,stRcvCommuCtrlArr, stCtrlToGridArr);
      
                if flag  % 收敛
                    [stOutSdUnionSimDataCell] = Generate_Iterator_Converge_data(stCtrlToGridArr, 5);
                else
                    % stSendDGCommuCtrlArr
                    % 这里定义结构字段的值必须为空，即初始化时没有该数据，通过下面的函数Generate_Upload_Iterator_data
                    % 生成
                    stSendDGCommuCtrlArr = struct('PowerSimTime',{},'Converge_Flag',{},'Startnode_ID',{},'Destnode_ID',{},...
                                                  'TimeDelay',{},'ErrorType',{},'data',{});
                    [stOutSdUnionSimDataCell, iterator_count] = Generate_Upload_Iterator_data(g_stState, g_stPara, iterator_count, stSendDGCommuCtrlArr);
                end
            otherwise
                executeFlag = true;
                record_log( 1, file_name, 'distri_network_strategy: 没有可执行的case，默认返回true.' );
                return;
        end

        [executRes, iterator_count, stOutSdUnionSimData] = parse_power_stream_to_simdata(stOutSdUnionSimDataCell, iterator_count, cellNodeMapItemMap );
        if executRes == false
            executeFlag = false;
            record_log( 2, file_name, 'distri_network_strategy: 调用函数 parse_power_stream_to_simdata 执行失败.' );
            return;
        end
        
        stDisNetCalMembers(1).iterator_count = iterator_count;
        stDisNetCalMembers(1).g_stState = g_stState;
        stDisNetCalMembers(1).g_stPara = g_stPara;
        stDisNetCalMembers(1).g_stDgNodeArr = g_stDgNodeArr;
        stDisNetCalMembers(1).g_stUploadBusCommu = g_stUploadBusCommu;
        stDisNetCalMembers(1).g_stDwloadBusCommu = g_stDwloadBusCommu;
        executeFlag = true;
    catch ErrorInfo  % 捕获到的错误是一个MException对象
         exception_error(file_name, ErrorInfo);  
         throw(ErrorInfo);
    end
    
    record_log( 0, file_name, 'The distri_network_strategy function runs success!' );
end