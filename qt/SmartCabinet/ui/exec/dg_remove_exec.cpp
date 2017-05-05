#include "dg_remove_exec.h"

Dg_Remove_Exec::Dg_Remove_Exec()
{
    //定义对应列表列数
s_drawerColumn = 6;
s_positioinColumn = 7;
s_judgeStatusColumn = 2;
s_nameColumn = 1;
s_agetiaIdColumn = 10;
s_positionIdColumn = 11;
s_orderColumn = 0;
s_doseColumn = 5;


tableName = "T_AgentiaExecute";//T_AgentiaExecute
modelOptional = "Mul";
SetTitle("移出操作");

All_Control();
}

void Dg_Remove_Exec::UploadTask2Server()
{
TakeOut();
}

