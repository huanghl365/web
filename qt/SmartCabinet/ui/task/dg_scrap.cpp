#include "dg_scrap.h"

Dg_Scrap::Dg_Scrap()
{
    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    DownLoad_TaskList();
    SetTitle("报废界面");
    ShowUI();
    ShowSQL();

}

void Dg_Scrap::DownLoad_TaskList()
{
    qDebug()<<"scrap";
}
