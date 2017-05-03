#include "initprocess.h"
#include "common/uart4stm.h"
#include "network/netcommunication.h"
#include "inputnew/frminputnew.h"
#include "common/timerandupdate.h"
#include "common/Sql_Setting.h"
#include "common/serialportworking.h"

#include <QDebug>
#include <QSqlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QProcess>
#include <QMessageBox>
#include <QThread>

Initprocess::Initprocess(QObject *parent) :
    QObject(parent)
{
    updateSQL = new UpdateSQL(this);
}

Initprocess::~Initprocess()
{

}

void Initprocess::ReadConfig()
{
    QSqlQuery query;
    query.exec(QString("select * from T_Version"));
    query.last();
    qDebug()<<query.value(0).toString();
    qDebug()<<query.value(1).toString();

    CABINETNO = query.value(1).toString();
    VERSION = query.value(0).toString();
}

void Initprocess::CreateSql()
{
    if(!createConnection())//创建数据库，注意测试阶段数据库一启动便会初始化具体Sql_Setting文件
    {
        qDebug()<<"data base already create";
    }
}

void Initprocess::StartSerialPortThread()
{
    SerialPortWorking *serialport = new SerialPortWorking;
    QThread *serialPort_thread = new QThread;
    serialport->moveToThread(serialPort_thread);
    serialPort_thread->start();

    emit CreateSerialPort();
    connect(this, SIGNAL(CreateSerialPort()), serialport, SLOT(CreateSerialPort()));

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
//    frmInputNew::Instance()->init("bottom", "black", 12, 10, 700, 230, 20, 20, 6, 45);
}

bool Initprocess::Upgrade()
{
    NetCommunication *network = new NetCommunication;
    QString armVersion = "";
    QString armUrl = "";

    QString json_str = network->PackageJson_version(CABINETNO);
    if (network->PostHttp("version", json_str, 2))
    {
        if (UnpackVersion(network->ServerReply, &armVersion, &armUrl))
        {
            if(armVersion != VERSION)
            {
                int ret = QMessageBox::warning(NULL,tr("更新"), tr("是否立即更新?"), \
                                               QMessageBox::Ok , QMessageBox::No);
                if (ret == QMessageBox::Ok)
                {
                    QProcess *proe = new QProcess;
                    proe->startDetached("./untitled4");
                    this->deleteLater();
                    return false;
                }
            }
        }
    }
    return true;
}

bool Initprocess::UnpackVersion(QJsonDocument jd , QString *armVersion, QString *armUrl)
{
    QJsonObject analyze_Z = jd.object();
    QJsonValue s_json[3] = {0};
    bool s_success = false;

    s_json[0] = analyze_Z["success"].toBool();
    s_success = s_json[0].toBool();

    if (s_success)
    {
        s_json[0] = analyze_Z["armVersion"].toString();
        *armVersion = s_json[0].toString();

        s_json[1] = analyze_Z["armDownload"].toString();
        *armUrl = s_json[1].toString();
    }
    else
        return false;

    return true;
}

void Initprocess::Start_Autoscan()
{
    TimerAndUpdate *timerAndUpdate = new TimerAndUpdate;

    connect(timerAndUpdate, SIGNAL(Timer_Task_Quit()), this, SLOT(Quit_Login()));
    connect(timerAndUpdate, SIGNAL(Timer_Task_UpdateSQL()), this, SLOT(UpdateLocalSql()));
}
