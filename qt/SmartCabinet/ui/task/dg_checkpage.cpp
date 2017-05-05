#include "dg_checkpage.h"
#include "common/globalvariable.h"
#include "ui/exec/dg_checkpage_exec.h"
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
    this->showMinimized();
    Dg_CheckPage_Exec *execTask = new Dg_CheckPage_Exec;
    resetSignal = HALTQUITPROCESS;

    connect(execTask, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed(QObject*)), execTask, SLOT(deleteLater()));

}


void Dg_CheckPage::DownLoad_TaskList()
{
    QSqlQuery query;

    query.exec(QString("DELETE from %1").arg(table_exec));

    updateSQL->GetAllAgentia(&userId);
    updateSQL->GetTaskList(&userId, -1);
}
