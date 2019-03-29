stInSuUnionSimData
{ 
	'realtime',
	'sim_time',
	'comm_dat',
	'power_dat'
}

/****************Co-Simulation-V2.0/Common/comm_data_def.h*********************/
typedef struct CommSimData{
    uint32_t src_id;                      //起点节点编号.
    uint32_t dst_id;                      //终点节点编号.
    int32_t err_type;                     //错误类型.
    long long trans_delay;                //传输时延.
}CommSimData;

typedef struct UnionSimData{
    double realtime;                      //物理时戳.
    double sim_time;                      //仿真时刻.
    //communication sim
    CommSimData comm_dat;                 //通信信息数据.
    //power sim data
    char power_dat[POWER_DATA_MAX_LEN];   //电力信息数据.
}UnionSimData;

const char* stInSuUnionSimData_fieldnames[] = {"realtime","sim_time","comm_dat","power_dat"};
stInSuUnionSimData_params = mxCreateStructMatrix(1, 1, 4, stInSuUnionSimData_fieldnames);  //创建二维架构mxArray,m为结构体对象个数，n为每个成员变量的数组数，nfields为成员变量的个数，fieldnames为成员变量名   

//realtime
mat_realtime = mxCreateDoubleMatrix(1, 1, mxREAL);
memcpy(mxGetPr(mat_realtime), &(members.realtime), 1 * 1 * sizeof(double));
mxSetField(stInSuUnionSimData_params, 0, "realtime", mat_realtime);
//sim_time
mat_sim_time = mxCreateDoubleMatrix(1, 1, mxREAL);
memcpy(mxGetPr(mat_sim_time), &(members.sim_time), 1 * 1 * sizeof(double));
mxSetField(stInSuUnionSimData_params, 0, "sim_time", mat_sim_time);
//comm_dat
const char* CommSimData_fieldnames[] = {"src_id","dst_id","err_type","trans_delay"};
CommSimData_params = mxCreateStructMatrix(1, 1, 4, CommSimData_fieldnames);  //创建二维架构mxArray,m为结构体对象个数，n为每个成员变量的数组数，nfields为成员变量的个数，fieldnames为成员变量名   
		//src_id
		mat_src_id = mxCreateDoubleMatrix(1, 1, mxREAL);
		memcpy(mxGetPr(mat_src_id), &(members.src_id), 1 * 1 * sizeof(double));
		mxSetField(CommSimData_params, 0, "src_id", mat_src_id);
		//dst_id
		mat_dst_id = mxCreateDoubleMatrix(1, 1, mxREAL);
		memcpy(mxGetPr(mat_dst_id), &(members.dst_id), 1 * 1 * sizeof(double));
		mxSetField(CommSimData_params, 0, "dst_id", mat_dst_id);
		//err_type
		mat_err_type = mxCreateDoubleMatrix(1, 1, mxREAL);
		memcpy(mxGetPr(mat_err_type), &(members.err_type), 1 * 1 * sizeof(double));
		mxSetField(CommSimData_params, 0, "err_type", mat_err_type);
		//trans_delay
		mat_trans_delay = mxCreateDoubleMatrix(1, 1, mxREAL);
		memcpy(mxGetPr(mat_trans_delay), &(members.trans_delay), 1 * 1 * sizeof(double));
		mxSetField(CommSimData_params, 0, "trans_delay", mat_trans_delay);
mxSetField(stInSuUnionSimData_params, 0, "comm_dat", CommSimData_params);	
//power_dat












		