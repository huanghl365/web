#include "dg_takeoutpage.h"
#include "ui/exec/dg_exectakeout.h"

Dg_TakeOutPage::Dg_TakeOutPage()
{

    table_exec = "T_AgentiaExecute";
    table_sea = "T_AgentiaSaving";

    DownLoad_TaskList();
    SetTitle("取界面");
    ShowUI();
    ShowSQL();

}

void Dg_TakeOutPage::ShowExecuteWindow()
{
    Dg_ExecTakeOut *execTakeOut = new Dg_ExecTakeOut(this);
    execTakeOut->show();
    this->hide();
    resetSignal = HALTQUITPROCESS;//停止自动退出功能

    connect(execTakeOut, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), execTakeOut, SLOT(deleteLater()));
}

void Dg_TakeOutPage::DownLoad_TaskList()
{
    QSqlQuery query;

    query.exec(QString("DELETE from %1").arg(table_exec));

    updateSQL->GetAllAgentia(&userId);
    updateSQL->GetTaskList(&userId, -1);
}
