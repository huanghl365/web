#include "globalvariable.h"

int NetWorkStatus = 0;
int userId = 0;
int userRole = 0;
int resetSignal = 0;
QString userName = "";
int SerialPortStatus = -1;
bool isQuitLoopRequestAgentiaStatus = false;
bool isClickReturnPB = false;
int groupId = 0;
QString CABINETNO = "AABBCCDD";
QString VERSION ;

/*******MCU COMMUNICATION*****************/
bool is_ARM_receivedReply_from_MCU = false;
bool is_OpenSerialPort = false;
int currentLockStatus = LOCK_CURRENT_STATUS_CLOSE;
int is_MCU_taskExecuteStatus = TASK_OFFWORKING;
int send_positionNo_G[64] = {0};
int cabinet_drawer_num = 0;


/*************************/
