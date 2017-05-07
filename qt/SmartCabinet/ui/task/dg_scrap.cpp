#include "dg_scrap.h"
#include "ui/exec/dg_scrap_exec.h"
#include "common/globalvariable.h"

Dg_Scrap::Dg_Scrap()
{
    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    _Main("报废界面");
}

void Dg_Scrap::ShowExecuteWindow()
{
    this->showMinimized();
    Dg_Scrap_Exec *execScrap = new Dg_Scrap_Exec;

    resetSignal = HALTQUITPROCESS;//停止自动退出功能
    connect(execScrap, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed(QObject*)), execScrap, SLOT(deleteLater()));
}

void Dg_Scrap::DownLoad_TaskList()
{
    QSqlQuery query;

    query.exec(QString("DELETE from %1").arg(table_exec));

    updateSQL->GetAllAgentia(&userId);
    updateSQL->GetTaskList(&userId, TASKTYPE_SCRAP);
}
