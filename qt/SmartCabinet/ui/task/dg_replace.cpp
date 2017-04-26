#include "dg_replace.h"

Dg_Replace::Dg_Replace()
{
    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    DownLoad_TaskList();
    SetTitle("替换界面");
    ShowUI();
    ShowSQL();

}

void Dg_Replace::DownLoad_TaskList()
{
    qDebug()<<" replace";
}
