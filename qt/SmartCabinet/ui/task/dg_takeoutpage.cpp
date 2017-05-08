#include "dg_takeoutpage.h"
#include "ui/exec/dg_takeout_exec.h"
#include "common/globalvariable.h"

Dg_TakeOutPage::Dg_TakeOutPage()
{

    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    _Main("取用界面");
}

void Dg_TakeOutPage::ShowExecuteWindow()
{
    this->showMinimized();
    Dg_TakeOut_Exec *execTakeOut = new Dg_TakeOut_Exec;

    resetSignal = HALTQUITPROCESS;//停止自动退出功能
    connect(execTakeOut, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed(QObject*)), execTakeOut, SLOT(deleteLater()));
}

void Dg_TakeOutPage::DownLoad_TaskList()
{
    QSqlQuery query;

    query.exec(QString("DELETE from %1").arg(table_exec));

    updateSQL->GetAllAgentia(&userId);
    updateSQL->GetTaskList(&userId, TASKTYPE_TAKEOUT);
}
