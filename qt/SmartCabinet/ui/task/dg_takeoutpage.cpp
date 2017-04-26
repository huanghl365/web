#include "dg_takeoutpage.h"
#include <QDebug>

Dg_TakeOutPage::Dg_TakeOutPage()
{
    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    DownLoad_TaskList();
    SetTitle("取界面");
    ShowUI();
    ShowSQL();
}


void Dg_TakeOutPage::DownLoad_TaskList()
{
    qDebug() << "takeout";
}
