stDisNetCalMembers
{
	Para g_stPara;
	State g_stState;
	DG_Node g_stDgNodeArr[5];
	Bus_Info_Commu g_stUploadBusCommu;
	Bus_Info_Commu g_stDwloadBusCommu;
	int iterator_count;
	int b_is_first_handle_frequency;
}

const char* stDisNetCalMembers_fieldnames[] = {"g_stPara","g_stState","g_stDgNodeArr","g_stUploadBusCommu","g_stDwloadBusCommu","iterator_count","b_is_first_handle_frequency"};
stDisNetCalMembers_params = mxCreateStructMatrix(1, 1, 7, stDisNetCalMembers_fieldnames);  //创建二维架构mxArray,m为结构体对象个数，n为每个成员变量的数组数，nfields为成员变量的个数，fieldnames为成员变量名   

//Para g_stPara
const char* Para_fieldnames[] = {"B","L","D","Capacity","P_Demand","P_Realtime","time","t_hold","step","beta","kappa","Freq","Kg"};
Para_params = mxCreateStructMatrix(1, 1, 13, Para_fieldnames);  //创建二维架构mxArray,m为结构体对象个数，n为每个成员变量的数组数，nfields为成员变量的个数，fieldnames为成员变量名   
	  //B
	  mat_B = mxCreateDoubleMatrix(5, 5, mxREAL);
	  memcpy(mxGetPr(mat_B), &(members.B), 5 * 5 * sizeof(double));
      mxSetField(Para_params, 0, "B", mat_B);
	  //L
	  mat_L = mxCreateDoubleMatrix(5, 5, mxREAL);
	  memcpy(mxGetPr(mat_L), &(members.L), 5 * 5 * sizeof(double));
      mxSetField(Para_params, 0, "L", mat_L);
	  //D
	  mat_D = mxCreateDoubleMatrix(1, 5, mxREAL);
	  memcpy(mxGetPr(mat_D), &(members.D), 1 * 5 * sizeof(double));
      mxSetField(Para_params, 0, "D", mat_D);
	  //Capacity
	  mat_Capacity = mxCreateDoubleMatrix(1, 5, mxREAL);
	  memcpy(mxGetPr(mat_Capacity), &(members.Capacity), 1 * 5 * sizeof(double));
      mxSetField(Para_params, 0, "Capacity", mat_Capacity);
	  //P_Demand
	  mat_P_Demand = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_P_Demand), &(members.P_Demand), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "P_Demand", mat_P_Demand);
	  //P_Realtime
	  mat_P_Realtime = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_P_Realtime), &(members.P_Realtime), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "P_Realtime", mat_P_Realtime);
	  //time
	  mat_time = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_time), &(members.time), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "time", mat_time);
      //t_hold
	  mat_t_hold = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_t_hold), &(members.t_hold), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "t_hold", mat_t_hold);
      //step 步长
	  mat_step = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_step), &(members.step), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "step", mat_step);
      //beta 
	  mat_beta = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_beta), &(members.beta), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "beta", mat_beta);
      //kappa 
	  mat_kappa = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_kappa), &(members.kappa), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "kappa", mat_kappa);
      //Freq 电网频率
	  mat_Freq = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_Freq), &(members.Freq), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "Freq", mat_Freq);
      //Kg 调节系数
	  mat_Kg = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_Kg), &(members.Kg), 1 * 1 * sizeof(double));
      mxSetField(Para_params, 0, "Kg", mat_Kg);
mxSetField(stDisNetCalMembers_params, 0, "g_stPara", Para_params);

//State g_stState
const char* State_fieldnames[] = {"miu_pin","miu_trans_step","miu_hold_step","miu_previous_step","flag_converge","flag_miu","miu_this_time","miu_previous_time"};
State_params = mxCreateStructMatrix(1, 1, 8, State_fieldnames);  //创建二维架构mxArray,m为结构体对象个数，n为每个成员变量的数组数，nfields为成员变量的个数，fieldnames为成员变量名   
	  //miu_pin 
	  mat_miu_pin = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_miu_pin), &(members.miu_pin), 1 * 1 * sizeof(double));
      mxSetField(State_params, 0, "miu_pin", mat_miu_pin);
	  //miu_trans_step
	  mat_miu_trans_step = mxCreateDoubleMatrix(1, 5, mxREAL);
	  memcpy(mxGetPr(mat_miu_trans_step), &(members.miu_trans_step), 1 * 5 * sizeof(double));
      mxSetField(State_params, 0, "miu_trans_step", mat_miu_trans_step);
	  //miu_hold_step
	  mat_miu_hold_step = mxCreateDoubleMatrix(1, 5, mxREAL);
	  memcpy(mxGetPr(mat_miu_hold_step), &(members.miu_hold_step), 1 * 5 * sizeof(double));
      mxSetField(State_params, 0, "miu_hold_step", mat_miu_hold_step);
	  //miu_previous_step
	  mat_miu_previous_step = mxCreateDoubleMatrix(1, 5, mxREAL);
	  memcpy(mxGetPr(mat_miu_previous_step), &(members.miu_previous_step), 1 * 5 * sizeof(double));
      mxSetField(State_params, 0, "miu_previous_step", mat_miu_previous_step);
	  //flag_converge
	  mat_flag_converge = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_flag_converge), &(members.flag_converge), 1 * 1 * sizeof(double));
      mxSetField(State_params, 0, "flag_converge", mat_flag_converge);
	  //flag_miu
	  mat_flag_miu = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_flag_miu), &(members.flag_miu), 1 * 1 * sizeof(double));
      mxSetField(State_params, 0, "flag_miu", mat_flag_miu);
	  //miu_this_time
	  mat_miu_this_time = mxCreateDoubleMatrix(1, 5, mxREAL);
	  memcpy(mxGetPr(mat_miu_this_time), &(members.miu_this_time), 1 * 5 * sizeof(double));
      mxSetField(State_params, 0, "miu_this_time", mat_miu_this_time);
	  //miu_previous_time
	  mat_miu_previous_time = mxCreateDoubleMatrix(1, 5, mxREAL);
	  memcpy(mxGetPr(mat_miu_previous_time), &(members.miu_previous_time), 1 * 5 * sizeof(double));
      mxSetField(State_params, 0, "miu_previous_time", mat_miu_previous_time);
mxSetField(stDisNetCalMembers_params, 0, "g_stState", State_params); 
 
//DG_Node g_stDgNodeArr[5] 
const char* DG_Node_fieldnames[] = {"DG_NO","generation_value","simtime"};
DG_Node_params = mxCreateStructMatrix(1, 5, 3, DG_Node_fieldnames);  //创建二维架构mxArray,m为结构体对象个数，n为每个成员变量的数组数，nfields为成员变量的个数，fieldnames为成员变量名   
	  for(int i = 0;i<5;i++)
	  {
		  //DG_NO
		  mat_DG_NO = mxCreateDoubleMatrix(1, 1, mxREAL);
		  memcpy(mxGetPr(mat_DG_NO), &(members.g_stDgNodeArr[i].DG_NO), 1 * 1 * sizeof(double));
		  mxSetField(DG_Node_params, i, "DG_NO", mat_DG_NO);
		  //generation_value
		  mat_generation_value = mxCreateDoubleMatrix(1, 1, mxREAL);
		  memcpy(mxGetPr(mat_generation_value), &(members.g_stDgNodeArr[i].generation_value), 1 * 1 * sizeof(double));
		  mxSetField(DG_Node_params, i, "generation_value", mat_generation_value);
		  //simtime
		  mat_simtime = mxCreateDoubleMatrix(1, 1, mxREAL);
		  memcpy(mxGetPr(mat_simtime), &(members.g_stDgNodeArr[i].simtime), 1 * 1 * sizeof(double));
		  mxSetField(DG_Node_params, i, "simtime", mat_simtime);
	  } 	
mxSetField(stDisNetCalMembers_params, 0, "g_stDgNodeArr", DG_Node_params); 

//Bus_Info_Commu g_stUploadBusCommu
const char* Bus_Info_Commu_up_fieldnames[] = {"upPowerSimTime","upPowerFrequency","upBusNo","upStartnode_ID","upDestnode_ID","upErrorType","upTimeDelay"};
Bus_Info_Commu_up_params = mxCreateStructMatrix(1, 1, 7, Bus_Info_Commu_up_fieldnames);  //创建二维架构mxArray,m为结构体对象个数，n为每个成员变量的数组数，nfields为成员变量的个数，fieldnames为成员变量名 
	  //upPowerSimTime
	  mat_upPowerSimTime= mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_upPowerSimTime), &(members.g_stUploadBusCommu.upPowerSimTime), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_up_params, 0, "upPowerSimTime", mat_upPowerSimTime);
	  //upPowerFrequency
	  mat_upPowerFrequency = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_upPowerFrequency), &(members.g_stUploadBusCommu.upPowerFrequency), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_up_params, 0, "upPowerFrequency", mat_upPowerFrequency);
	  //upBusNo
	  mat_upBusNo = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_upBusNo), &(members.g_stUploadBusCommu.upBusNo), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_up_params, 0, "upBusNo", mat_upBusNo);
	  //upStartnode_ID
	  mat_upStartnode_ID = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_upStartnode_ID), &(members.g_stUploadBusCommu.upStartnode_ID), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_up_params, 0, "upStartnode_ID", mat_upStartnode_ID);
	  //upDestnode_ID
	  mat_upDestnode_ID = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_upDestnode_ID), &(members.g_stUploadBusCommu.upDestnode_ID), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_up_params, 0, "upDestnode_ID", mat_upDestnode_ID);
	  //upErrorType
	  mat_upErrorType = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_upErrorType), &(members.g_stUploadBusCommu.upErrorType), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_up_params, 0, "upErrorType", mat_upErrorType);
	  //upTimeDelay
	  mat_upTimeDelay = mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_upTimeDelay), &(members.g_stUploadBusCommu.upTimeDelay), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_up_params, 0, "upTimeDelay", mat_upTimeDelay);
mxSetField(stDisNetCalMembers_params, 0, "g_stUploadBusCommu", Bus_Info_Commu_up_params); 

//Bus_Info_Commu g_stDwloadBusCommu
const char* Bus_Info_Commu_down_fieldnames[] = {"dwPowerSimTime","dwPowerFrequency","dwBusNo","dwStartnode_ID","dwDestnode_ID","dwErrorType","dwTimeDelay"};
Bus_Info_Commu_down_params = mxCreateStructMatrix(1, 1, 7, Bus_Info_Commu_down_fieldnames);  //创建二维架构mxArray,m为结构体对象个数，n为每个成员变量的数组数，nfields为成员变量的个数，fieldnames为成员变量名 
	  //dwPowerSimTime
	  mat_dwPowerSimTime= mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_dwPowerSimTime), &(members.g_stDwloadBusCommu.dwPowerSimTime), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_down_params, 0, "dwPowerSimTime", mat_dwPowerSimTime);
	  //dwPowerFrequency
	  mat_dwPowerFrequency= mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_dwPowerFrequency), &(members.g_stDwloadBusCommu.dwPowerFrequency), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_down_params, 0, "dwPowerFrequency", mat_dwPowerFrequency);
	  //dwBusNo
	  mat_dwBusNo= mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_dwBusNo), &(members.g_stDwloadBusCommu.dwBusNo), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_down_params, 0, "dwBusNo", mat_dwBusNo);
	  //dwStartnode_ID
	  mat_dwStartnode_ID= mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_dwStartnode_ID), &(members.g_stDwloadBusCommu.dwStartnode_ID), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_down_params, 0, "dwStartnode_ID", mat_dwStartnode_ID);
	  //dwDestnode_ID
	  mat_dwDestnode_ID= mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_dwDestnode_ID), &(members.g_stDwloadBusCommu.dwDestnode_ID), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_down_params, 0, "dwDestnode_ID", mat_dwDestnode_ID);
	  //dwErrorType
	  mat_dwErrorType= mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_dwErrorType), &(members.g_stDwloadBusCommu.dwErrorType), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_down_params, 0, "dwErrorType", mat_dwErrorType);
	  //dwTimeDelay
	  mat_dwTimeDelay= mxCreateDoubleMatrix(1, 1, mxREAL);
	  memcpy(mxGetPr(mat_dwTimeDelay), &(members.g_stDwloadBusCommu.dwTimeDelay), 1 * 1 * sizeof(double));
      mxSetField(Bus_Info_Commu_down_params, 0, "dwTimeDelay", mat_dwTimeDelay);
mxSetField(stDisNetCalMembers_params, 0, "g_stDwloadBusCommu", Bus_Info_Commu_down_params); 

//int iterator_count
 mat_iterator_count= mxCreateDoubleMatrix(1, 1, mxREAL);
 memcpy(mxGetPr(mat_iterator_count), &(members.iterator_count), 1 * 1 * sizeof(double));
 mxSetField(stDisNetCalMembers_params, 0, "iterator_count", mat_iterator_count);
 
//int b_is_first_handle_frequency
 mat_b_is_first_handle_frequency= mxCreateDoubleMatrix(1, 1, mxREAL);
 memcpy(mxGetPr(mat_b_is_first_handle_frequency), &(members.b_is_first_handle_frequency), 1 * 1 * sizeof(double));
 mxSetField(stDisNetCalMembers_params, 0, "b_is_first_handle_frequency", mat_b_is_first_handle_frequency);   