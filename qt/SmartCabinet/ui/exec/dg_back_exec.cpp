#include "dg_back_exec.h"

Dg_Back_Exec::Dg_Back_Exec()
{
    this->showFullScreen();
    //定义对应列表列数
    s_drawerColumn = 6;
    s_positioinColumn = 7;
    s_judgeStatusColumn = 2;
    s_nameColumn = 1;
    s_agetiaIdColumn = 10;
    s_positionIdColumn = 11;
    s_orderColumn = 0;
    s_doseColumn = 5;


    tableName = "T_AgentiaReturnExecute";
    modelOptional = "Single";
    SetTitle("归还操作");
    All_Control();
}

void Dg_Back_Exec::UploadTask2Server()
{
    Back_TakeIn();
}
