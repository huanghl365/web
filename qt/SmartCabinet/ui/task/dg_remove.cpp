#include "dg_remove.h"
#include "ui/exec/dg_remove_exec.h"
#include "common/globalvariable.h"

Dg_Remove::Dg_Remove()
{
    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    _Main("移除界面");
}

void Dg_Remove::ShowExecuteWindow()
{
    this->showMinimized();
    Dg_Remove_Exec *execRemove = new Dg_Remove_Exec;

    resetSignal = HALTQUITPROCESS;//停止自动退出功能
    connect(execRemove, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed(QObject*)), execRemove, SLOT(deleteLater()));
}

void Dg_Remove::DownLoad_TaskList()
{
    QSqlQuery query;

    query.exec(QString("DELETE from %1").arg(table_exec));

    updateSQL->GetAllAgentia(&userId);
    updateSQL->GetTaskList(&userId, -1);
}
