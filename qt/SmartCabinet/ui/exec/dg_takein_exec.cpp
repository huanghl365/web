#include "dg_takein_exec.h"

Dg_TakeIn_Exec::Dg_TakeIn_Exec()
{
    this->showFullScreen();
    //定义对应列表列数
    s_drawerColumn = 3;
    s_positioinColumn = 4;
    s_judgeStatusColumn = 2;
    s_doseColumn = 6;
    s_orderColumn = 0;
    s_nameColumn = 1;
    s_agetiaTypeIdColumn = 8;
    s_agetiaIdColumn = 8;
    s_positionIdColumn = 9;



    tableName = "T_PutInExec";
    modelOptional = "Single";
    IsChangeInfo("notchange");
    SetTitle("入柜操作");
    All_Control();
}

void Dg_TakeIn_Exec::UploadTask2Server()
{
    New_TakeIn();
}

void Dg_TakeIn_Exec::ShowPage()
{
    Show_TakeIn();
}
