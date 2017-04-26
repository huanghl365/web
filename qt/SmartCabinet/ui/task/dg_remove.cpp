#include "dg_remove.h"

Dg_Remove::Dg_Remove()
{
    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    DownLoad_TaskList();
    SetTitle("移出界面");
    ShowUI();
    ShowSQL();

}

void Dg_Remove::DownLoad_TaskList()
{
    qDebug()<< "remove";
}
