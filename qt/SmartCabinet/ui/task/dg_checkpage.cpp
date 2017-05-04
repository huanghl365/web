#include "dg_checkpage.h"
#include "common/globalvariable.h"
#include "ui/exec/dg_execcheck.h"
#include "ui/exec/dg_exectakein.h"
#include <QDebug>

Dg_CheckPage::Dg_CheckPage(QWidget *parent) :
    Dg_TaskClass(parent)
{
    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    _Main("点验界面");

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
