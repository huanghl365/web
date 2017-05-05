#include "dg_replace.h"
#include "ui/exec/dg_replace_exec.h"
#include "common/globalvariable.h"

Dg_Replace::Dg_Replace()
{
    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    _Main("替换界面");
}

void Dg_Replace::ShowExecuteWindow()
{
    this->showMinimized();
    Dg_Replace_Exec *execReplace = new Dg_Replace_Exec;

    resetSignal = HALTQUITPROCESS;//停止自动退出功能
    connect(execReplace, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed(QObject*)), execReplace, SLOT(deleteLater()));

}

void Dg_Replace::DownLoad_TaskList()
{
    QSqlQuery query;

    query.exec(QString("DELETE from %1").arg(table_exec));

    updateSQL->GetAllAgentia(&userId);
    updateSQL->GetTaskList(&userId, -1);
}
