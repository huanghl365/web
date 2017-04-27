#include "dg_checkpage.h"
#include "common/globalvariable.h"
#include "ui/exec/dg_execcheck.h"
#include "ui/exec/dg_exectakein.h"
#include <QDebug>

Dg_CheckPage::Dg_CheckPage(QWidget *parent) :
    Dg_TaskClass(parent)
{
    //    table_exec = "T_AgentiaExecute";
    //    table_sea = "T_AgentiaSaving";

    //    DownLoad_TaskList();
    //    SetTitle("取界面");
    //    ShowUI();
    //    ShowSQL();

}

void Dg_CheckPage::ShowExecuteWindow()
{
    Dg_ExecCheck *execTask = new Dg_ExecCheck(this);
    execTask->show();
    this->hide();
    resetSignal = HALTQUITPROCESS;

    connect(execTask, SIGNAL(destroyed()), this, SLOT(deleteLater()));
}


void Dg_CheckPage::DownLoad_TaskList()
{
    qDebug() << "ddd";
}
