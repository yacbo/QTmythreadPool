#ifndef DISTRI_NETWORK_DATA_DEF_H
#define DISTRI_NETWORK_DATA_DEF_H

#include "type_data_def.h"
#include "power_data_def.h"

#pragma pack(push)
#pragma pack(1)

#define NODE_NUM 5
#define MIU double
#define ActivePower double

const int MAX_ITER_COUNTS = 200;
const int DW_DATA_ITEM = 5;

//EPowerDataType
typedef enum EPowerDataType{
    ePowerData_businfor   = 0,
    ePowerData_poweroper  = 1,
    ePowerData_dpnode     = 2,
    ePowerData_freqinfor  = 3,
}EPowerDataType;

//FreqInfor
typedef struct PowerFreqInforData : public PowerSimUpStmData{
    EPowerDataType type;
    double freq;
}PowerFreqInforData;

//DpNode
typedef struct PowerDpNodeData : public PowerSimDwStmData{
    EPowerDataType type;
    double dp;
}PowerDpNodeData;

typedef enum EInteractType{
    eInteract_power_bus      = 0,
    eInteract_upload_bus     = 1,
    eInteract_download_bus   = 2,
    eIneract_ctrl_to_comm    = 3,
    eIneract_comm_to_ctrl    = 4,
    eInteract_ctrl_to_power  = 5,
}EInteractType;

/*********电力控制算法和通信接口******/

//通信软件与电力应用交互母线信息
typedef struct _Bus_Info_Commu{
    double PowerSimTime;         //仿真时刻
    double PowerFrequency;       //电网频率
    int BusNo;                   //母线节点编号
    int Startnode_ID;            //通信起点编号
    int Destnode_ID;             //通信终点编号
    int ErrorType;               //故障类型
    double TimeDelay;            //通信时延
}Bus_Info_Commu;

//通信软件下发至控制算法DG节点数据结构体
typedef struct Commu_Ctrl{
    double PowerSimTime;         //仿真时刻
    bool Converge_Flag;          //算法收敛标志
    int Startnode_ID;            //始发通信节点编号
    int Destnode_ID;             //通信终点编号
    double TimeDelay;            //通信时延
    int ErrorType;               //故障类型
    double data[16];             //节点迭代交换数据
}Commu_Ctrl;

//电力上传母线信息至电力控制算法
typedef struct _Bus_Info{
    double busno;
    double sampling_time;
    double freq;
}Bus_Info;

//电力软件上传至电力控制算法结构体
typedef struct DG_exchangedata{
    double DG_NO;
    double generation_value;
    double simtime;
}DG_Node;

//电力控制算法下发至电力软件结构体
typedef struct _Ctrl_to_Grid{
    double DG_node_ID;           //电力节点编号（DG）
    double PowerUpadateTime;     //更新时间
    double dP;                   //控制指令
}Ctrl_to_Grid;

typedef struct _state{
    MIU miu_pin;
    MIU miu_trans_step[NODE_NUM];
    MIU miu_hold_step[NODE_NUM];
    MIU miu_previous_step[NODE_NUM];
    bool flag_converge;
    bool flag_miu;
    MIU miu_this_time[NODE_NUM];
    MIU miu_previous_time[NODE_NUM];
}State;

typedef struct _para{
    int B[NODE_NUM][NODE_NUM];       //连接矩阵
    int L[NODE_NUM][NODE_NUM];
    int D[NODE_NUM];
    ActivePower Capacity[NODE_NUM];  //可调节能力
    ActivePower P_Demand;            //缺额功率
    ActivePower P_Realtime;          //迭代状态量
    double time;
    double t_hold;
    double step;                     //步长
    double beta;
    double kappa;
    double Freq;                     //电网频率
    double Kg;                       //调节系数
}Para;

#pragma pack(pop)

#endif // DISTRI_NETWORK_DATA_DEF_H