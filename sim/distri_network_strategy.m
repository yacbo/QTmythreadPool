function [executeFlag, stDisNetCalMembers, stOutSdUnionSimData] = distri_network_strategy(stDisNetCalMembers, stInSuUnionSimData, cellNodeMapItemMap)
%distri_network_strategy  �ֲ�ʽ�����㷨�������������Ϸ������ݼ���õ��������Ϸ�������
%                  �ú����״ε���ʱ������ִ�� case eInteract_power_bus��Ȼ����к�������������״�ִ�к���ʱ��
%                  ����ȷ�� stDisNetCalMembers.iterator_count = 0,��stDisNetCalMembers.b_is_first_handle_frequency = true��
%                  �Լ� stInSuUnionSimData �ĸ���Ϊ1�� 
% ����˵����
% stDisNetCalMembers : �����ֶΣ�{'g_stPara','g_stState','g_stDgNodeArr','g_stUploadBusCommu','g_stDwloadBusCommu','iterator_count','b_is_first_handle_frequency'}��
%                            g_stPara���ṹ�壬�����ֶΣ�{'B','L','D','Capacity','P_Demand','P_Realtime',
%                                                        'time','t_hold','step','beta','kappa','Freq','Kg'}��
%                            g_stState���ṹ�壬�����ֶΣ�{'miu_pin','miu_trans_step','miu_hold_step','miu_previous_step',
%                                                        'flag_converge','flag_miu', 'miu_this_time','miu_previous_time'}��
%                            g_stDgNodeArr���ṹ�����飬����5��ÿ���ṹ��������ֶΣ�{'DG_NO','generation_value','simtime'}��    
%                            g_stUploadBusCommu���ṹ�壬�����ֶΣ�{'PowerSimTime','PowerFrequency','BusNo',
%                                                                 'Startnode_ID','Destnode_ID','ErrorType','TimeDelay'}
%                            g_stDwloadBusCommu:�ṹ�壬�����ֶκ�g_stUploadBusCommu��ͬ��
%                            iterator_count�������������״ε��øú���ʱ������ֵ��ʼ��Ϊ 0 
%                            b_is_first_handle_frequency���Ƿ��״�ִ��Ƶ����Ϣ��ز�������ʼ��Ϊ true
% stInSuUnionSimData       ���Ϸ����������ݣ���Ϊ�ṹ�壬�����ֶΣ�
%                          { 'realtime','sim_time','comm_dat','power_dat'}
%                          ���У��ֶ� comm_dat Ҳ��һ���ṹ�壬�����ֶΣ�
%                          { 'src_id','dst_id', 'err_type','trans_delay'}
%                          ���ֶ� power_dat ���������ݵĸ����йأ����������������ݸ���Ϊ 1����
%                          power_dat Ҳ��һ���ṹ�壬�����ֶΣ�{ 'bus_id',
%                          'power_sim_time','data_length','power_data_type','freq' }��
%                          ����power_dat ��һ����ֵ��
% cellNodeMapItemMap       ��ȡ�ķ���Ӧ�������еĵ���������Ϣ�еĽڵ�ӳ����Ϣ���˲���Ϊ m * 2 ��Ԫ�����飬��ʽΪ
%                          {NodeId, NodeMapItem}, NodeMapItem��һ���ṹ�壬���������ֶΣ�
%                              'power_bus_id', ����ĸ�߱��
%                              'comm_src_id', ͨ��Դ�ڵ���
%                              'comm_dst_id', ͨ��Ŀ�Ľڵ���
%                          �ò�������ֵΪ�� C++ �е� _dw_node_map ��
%                          _sim_case_conf_info._power_conf_info._dw_node_map
%
%           
% stOutSdUnionSimData      ���Ϸ����������ݣ����Σ��������ֶΣ�
%                          { 'realtime',  'sim_time',  'comm_dat', 'power_dat'}
%                          comm_dat �ֶζ�Ӧһ���ṹ�壬�����ֶΣ�
%                               'src_id', 'dst_id', 'err_type','trans_delay'
%                          power_dat�ֶθ��ݽ��������Ͳ�ͬ����������ݲ�ͬ�����£�
%                               1��EInteractType.eInteract_ctrl_to_power�� stPowerDpNodeData
%                               2��EInteractType.eInteract_upload_bus��stPowerFreqInforData
%                               3��EInteractType.eIneract_ctrl_to_comm��data
% executeFlag               true������ִ�гɹ�
%                           false������ִ��ʧ��

%2018��12��15�� create
%2019��3��3�� modify
 
    cur_time = datestr(now,29);
    file_name = ['distri_network_', cur_time, '-log.txt']; %���ݵ�ǰ��ʱ������log��־�ļ�
    clear_error(file_name);%�˴��������exception_error(file_name, ErrorInfo)��¼���쳣��Ϣ
    
    retVal = isstruct(stInSuUnionSimData);
    if false == retVal
        stOutSdUnionSimData = struct([]); % �������Ĳ�������һ���ṹ�壬�򷵻�0*0�Ŀսṹ����
        executeFlag = false;
        record_log( 2, file_name, 'distri_network_strategy: ��� stInSuUnionSimData �ǽṹ��.' );
        return;
    end
    
    % ����ȫ�ֱ��� %
    global NODE_NUM; % �ڵ����
    NODE_NUM = 5;

    try
        [result, stDisNetCalMembers(1).b_is_first_handle_frequency, ...
         cellDataStream] = encap_power_simdata_to_stream(stDisNetCalMembers(1).b_is_first_handle_frequency, stInSuUnionSimData);
        if result == false
            executeFlag = false;
            record_log( 2, file_name, 'distri_network_strategy: ���ú��� encap_power_simdata_to_stream ִ��ʧ��.' );
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
                % ���ֽṹ���ֶ�˵��
%                 g_stState = struct('miu_pin',{0},'miu_trans_step',{0},'miu_hold_step',{0},'miu_previous_step',{0},...
%                                   'flag_converge',{0},'flag_miu',{0}, 'miu_this_time',{0},'miu_previous_time',{0});
%                 g_stPara = struct('B',{0},'L',{0},'D',{0},'Capacity',{0},'P_Demand',{0},'P_Realtime',{0},...
%                                    'time',{0},'t_hold',{0},'step',{0},'beta',{0},'kappa',{0},'Freq',{0},'Kg',{0});
%                 dgNodeCell = {0};
%                 dgNode5Cell = repmat(dgNodeCell, 1, 5);
%                 g_stDgNodeArr = struct('DG_NO',dgNode5Cell,'generation_value',dgNode5Cell,'simtime',dgNode5Cell);
%                 % ͨ����������Ӧ�ý���ĸ����Ϣ
%                 g_stUploadBusCommu = struct('PowerSimTime',{0},'PowerFrequency',{0},'BusNo',{0},...
%                                              'Startnode_ID',{0},'Destnode_ID',{0},'ErrorType',{0},'TimeDelay',{0});
                
                [g_stState, g_stPara, g_stDgNodeArr] = initialize_env();

                % ��ʼ��ȫ��ͨ�������Ӧ�ý���ĸ����Ϣ
                stBusInfo = cellDataStream{1,2};
                [g_stUploadBusCommu] = generate_upload_sample_freq(stBusInfo, g_stUploadBusCommu);    

                stOutDataStreamHeader = struct('data_type',{0},'sim_data_count',{0});
                stOutDataStreamHeader.data_type = EInteractType.eInteract_upload_bus;
                stOutDataStreamHeader.sim_data_count = 1;
                % ͨ������·��������㷨DG�ڵ����ݽṹ��
                stBusCommuUpload = g_stUploadBusCommu; % ���ﲻ�ı�g_stUploadBusCommuԭ�е�ֵ
                stOutSdUnionSimDataCell = {stOutDataStreamHeader, stBusCommuUpload};

            case EInteractType.eInteract_download_bus   
                stBusInfoCommu = cellDataStream{1,2};
                [g_stState, g_stPara, g_stDwloadBusCommu] = config_param_state(g_stState, g_stPara, stBusInfoCommu);
                % stSendDGCommuCtrlArr
                % ���ﶨ��ṹ�ֶε�ֵ����Ϊ�գ�����ʼ��ʱû�и����ݣ�ͨ������ĺ���Generate_Upload_Iterator_data
                % ����
                stSendDGCommuCtrlArr = struct('PowerSimTime',{},'Converge_Flag',{},'Startnode_ID',{},'Destnode_ID',{},...
                                              'TimeDelay',{},'ErrorType',{},'data',{});
                [stOutSdUnionSimDataCell, iterator_count] = Generate_Upload_Iterator_data(g_stState, g_stPara, iterator_count,...
                                                                                          stSendDGCommuCtrlArr);
            case EInteractType.eIneract_comm_to_ctrl
                cellUnitCommuCtrl = {0};
                cellCommuCtrl = repmat(cellUnitCommuCtrl, 1, count);
                % ��ʼ�����յ�ͨ���������㷨DG�ڵ����ݣ�����Ϊcount
                stRcvCommuCtrlArr = struct('PowerSimTime',cellCommuCtrl,'Converge_Flag',cellCommuCtrl,'Startnode_ID',cellCommuCtrl,...
                                           'Destnode_ID',cellCommuCtrl,'TimeDelay',cellCommuCtrl,...
                                           'ErrorType',cellCommuCtrl,'data',cellCommuCtrl);
                stCommuCtrlTemp = cellDataStream{1,2};
                for id = 1 : count
                    stRcvCommuCtrlArr(id) = stCommuCtrlTemp(id);
                end

                cellUnitCtrlToGrid = {0};
                cellCtrlToGrid = repmat(cellUnitCtrlToGrid, 1, 5);
                % ���������㷨�·�����������ṹ��
                stCtrlToGridArr = struct('DG_node_ID',cellCtrlToGrid,'PowerUpadateTime',cellCtrlToGrid,'dP',cellCtrlToGrid);
                
                [flag,g_stState, g_stPara,stCtrlToGridArr,...
                 stRcvCommuCtrlArr] = iterator_calculate(g_stState,g_stPara, g_stDgNodeArr,stRcvCommuCtrlArr, stCtrlToGridArr);
      
                if flag  % ����
                    [stOutSdUnionSimDataCell] = Generate_Iterator_Converge_data(stCtrlToGridArr, 5);
                else
                    % stSendDGCommuCtrlArr
                    % ���ﶨ��ṹ�ֶε�ֵ����Ϊ�գ�����ʼ��ʱû�и����ݣ�ͨ������ĺ���Generate_Upload_Iterator_data
                    % ����
                    stSendDGCommuCtrlArr = struct('PowerSimTime',{},'Converge_Flag',{},'Startnode_ID',{},'Destnode_ID',{},...
                                                  'TimeDelay',{},'ErrorType',{},'data',{});
                    [stOutSdUnionSimDataCell, iterator_count] = Generate_Upload_Iterator_data(g_stState, g_stPara, iterator_count, stSendDGCommuCtrlArr);
                end
            otherwise
                executeFlag = true;
                record_log( 1, file_name, 'distri_network_strategy: û�п�ִ�е�case��Ĭ�Ϸ���true.' );
                return;
        end

        [executRes, iterator_count, stOutSdUnionSimData] = parse_power_stream_to_simdata(stOutSdUnionSimDataCell, iterator_count, cellNodeMapItemMap );
        if executRes == false
            executeFlag = false;
            record_log( 2, file_name, 'distri_network_strategy: ���ú��� parse_power_stream_to_simdata ִ��ʧ��.' );
            return;
        end
        
        stDisNetCalMembers(1).iterator_count = iterator_count;
        stDisNetCalMembers(1).g_stState = g_stState;
        stDisNetCalMembers(1).g_stPara = g_stPara;
        stDisNetCalMembers(1).g_stDgNodeArr = g_stDgNodeArr;
        stDisNetCalMembers(1).g_stUploadBusCommu = g_stUploadBusCommu;
        stDisNetCalMembers(1).g_stDwloadBusCommu = g_stDwloadBusCommu;
        executeFlag = true;
    catch ErrorInfo  % ���񵽵Ĵ�����һ��MException����
         exception_error(file_name, ErrorInfo);  
         throw(ErrorInfo);
    end
    
    record_log( 0, file_name, 'The distri_network_strategy function runs success!' );
end