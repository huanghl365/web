#include "initprocess.h"
#include "common/uart4stm.h"
#include <QDebug>
#include <QSqlQuery>

Initprocess::Initprocess(QObject *parent) :
    QObject(parent)
{
    init_threadControl = new ThreadControl(this);
    updateSQL = new UpdateSQL(this);
    connect(init_threadControl, SIGNAL(Update_SQL()), this, SLOT(UpdateLocalSql()));
    connect(init_threadControl, SIGNAL(Close_ALLPage()), this, SLOT(Quit_Login()));
}


void Initprocess::ReadConfig()
{
    updateSQL->GetCabinetPowerList();
    if (updateSQL->GetVersion())
    {

        QSqlQuery query;
        query.exec("select * from T_temporary");
        query.first();


    }

}

void Initprocess::CreateSql()
{
    if(!createConnection())//创建数据库，注意测试阶段数据库一启动便会初始化具体Sql_Setting文件
    {
        qDebug()<<"data base already create";
    }
}

void Initprocess::OpenSerialPort()
{

}

void Initprocess::CreateThread()
{
    init_threadControl->CreateThread();
}

void Initprocess::StartThread()
{
    init_threadControl->ControlTimerThread(OPEN_THREAD);
}

void Initprocess::ShowLoginPage()
{
    init_loginPage = new Dg_LoginPage;
    init_loginPage->show();
    connect(init_loginPage, SIGNAL(destroyed()), this, SLOT(deleteLater()));
}

void Initprocess::UpdateLocalSql()
{
    updateSQL->GetCabinetPowerList();
//    updateSQL->GetReagentStatusList(&userId);
}

void Initprocess::Quit_Login()
{
    init_loginPage->Close_ActivePage();
}

void Initprocess::OpenKey()
{
}

