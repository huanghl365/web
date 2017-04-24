#include "timerandupdate.h"
#include "network/netcommunication.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>

TimerAndUpdate::TimerAndUpdate(QObject *parent) :
    QTimer(parent)
{
    timer_10s = new QTimer;
    accessManager = new QNetworkAccessManager(this);

    timeCount_returnAndUpdate = 0;
    timeCount_sendNeedInfo = 0;

    SetTimer(10000);

    connect(timer_10s, SIGNAL(timeout()), this, SLOT(dealTask()));
    connect(accessManager, SIGNAL(finished(QNetworkReply*)), this,\
            SLOT(replyFinished(QNetworkReply*)));


}

void TimerAndUpdate::TestThread()
{
  qDebug()<<"Timer Thread : "<<QThread::currentThreadId();
}

void TimerAndUpdate::SetTimer(unsigned int time)
{
    timer_10s->start(time);
}

void TimerAndUpdate::dealTask()
{

    if (HALTQUITPROCESS != resetSignal)//没有进入执行界面
    {
        qDebug()<<QStringLiteral("timer started");

        GetHttp();

        if (resetSignal == RESETTIMER)
        {
            timeCount_returnAndUpdate = 0;
            timeCount_sendNeedInfo = 0;
        }


        timeCount_returnAndUpdate++;
        timeCount_sendNeedInfo++;

        if (POSTINFO2SERVER == timeCount_sendNeedInfo)
        {

            timeCount_sendNeedInfo = 0;
        }

        if (QUITOPTPAGE == timeCount_returnAndUpdate)
        {
            emit Timer_Task_Quit();
        }
        else if (UPDATEDATA == timeCount_returnAndUpdate)
        {
            emit Timer_Task_UpdateSQL();
            StartUpgradeProgram();
            timeCount_returnAndUpdate = 0;

        }
    }
    else
    {
        qDebug()<<QStringLiteral("timer stopped");
    }

#ifdef TEST
    qDebug() << "timeCount_returnAndUpdate: " << timeCount_returnAndUpdate;
    qDebug() << "timeCount_sendNeedIndo = 0 " << timeCount_sendNeedInfo;
#endif

}

void TimerAndUpdate::GetHttp()
{
    QNetworkRequest *request = new QNetworkRequest;
    request->setUrl(QUrl(QString("http://121.43.159.215:3000/arm/heartBeating")));
    accessManager->get(*request);

#ifdef TEST
    qDebug() << QThread::currentThreadId() <<"  Get-----workThread";
#endif
}

void TimerAndUpdate::replyFinished(QNetworkReply *reply)
{
#ifdef TEST
    qDebug() << QThread::currentThreadId() << " Reply-----workThread";
#endif

    if (reply->error() == QNetworkReply::NoError)
    {
        NetWorkStatus = NETWORK_ONLINE;
        qDebug() << NetWorkStatus << " NETWORKSTATUS";
    }
    else
    {
        NetWorkStatus = NETWORK_OFFLINE;
        qDebug() << NetWorkStatus << " NETWORKSTATUS";
    }

    reply->deleteLater();
}

void TimerAndUpdate::StartUpgradeProgram()
{
    NetCommunication *netWork = new NetCommunication;
    QString str = netWork->PackageJson_version(CABINETNO);
    if (netWork->PostHttp("version", str, 2))
    {
        if (Unpackage(netWork->ServerReply))
        {
            system()
        }
    }
}

bool TimerAndUpdate::Unpackage(QJsonDocument jd)
{
    QJsonObject analyze_Z = jd.object();
    QJsonValue s_json[5] = {0};
    bool s_success = false;
    QString armVersion = "";
    QString armDownLoad = "";

    s_json[0] = analyze_Z["success"].toBool();
    s_success = s_json[0].toBool();

    if (s_success)
    {
        QSqlQuery query;
        query.exec(QString("DELETE from T_temporary"));

        s_json[0] = analyze_Z["armVersion"].toString();
        armVersion = s_json[0].toString();

        s_json[1] = analyze_Z["armDownload"].toString();
        armDownLoad = s_json[1].toString();

        query.prepare("insert into T_temporary (versionNo,address)\
                values (?,?)");
        query.addBindValue(armVersion);
        query.addBindValue(armDownLoad);
        query.exec();


    }
    else
        return false;

    return true;
}
