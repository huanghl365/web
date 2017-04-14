#include "control.h"
#include "globalvariable.h"

#include <QCoreApplication>
#include <QElapsedTimer>
#include <QFile>
#include <QDebug>
#include <QProcess>
#include <QHBoxLayout>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>


Control::Control(QWidget *parent) : QWidget(parent)
{
    netcommunication = new NetCommunication;
    setBrowser = new QTextBrowser;
    info_output = "";

    QHBoxLayout *hBox = new QHBoxLayout;
    hBox->addWidget(setBrowser);
    setLayout(hBox);

    this->show();
    GetVersion();

}

void Control::GetVersion()
{
    ShowExecStep("获取下载地址....");
    QString armVersion = "";
    QString armUrl = "";
    QString json_str = netcommunication->PackageJson_version(CABINETNO);
    if (netcommunication->PostHttp("version", json_str, 2))
    {
        if (UnpackVersion(netcommunication->ServerReply, &armVersion, &armUrl))
        {
#ifdef TEST
            qDebug()<< armVersion;
#endif
            ShowExecStep("下载地址获取成功，正在下载...");
            WaitTaskInfo(5);
            Download_shell_del_down(armUrl);

            ShowExecStep("正在解压...");
            WaitTaskInfo(5);
            Decompression("Test");
            ShowExecStep("解压成功");

            ShowExecStep("安装中请稍后...");
            WaitTaskInfo(5);
            InstallExe("Test");
            ShowExecStep("安装完成");

        }
        else
            ShowExecStep("获取失败，关闭下载程序");
    }
    else
        ShowExecStep("获取失败,关闭下载程序");
}

//    system("wget -P/home/x/SmartCabinet -c http://121.43.159.215:3000/download/arm_test.tar"); //download url demo
void Control::Download_shell_del_down(QString name)
{
    system("rm -rf /home/x/SmartCabinet/arm_test.tar");

    QString url_download = QString("wget -P/home/x/SmartCabinet -c http://121.43.159.215:3000%1").arg(name);
    qDebug()<<"----"<<url_download;
    QByteArray ba = url_download.toLatin1();
    const char *c_str2 = ba.data();
    system(c_str2);
}

void Control::Decompression(QString file)
{
    qDebug()<<"---"<<"Now system Decompression "<<file<<" task, please wait for a little";
    system("rm -rf /home/x/SmartCabinet/build-untitled-Desktop_Qt_5_7_1_GCC_64bit-Debug");
    system("tar -xf /home/x/SmartCabinet/arm_test.tar -C /home/x/SmartCabinet");
    system("rm -rf /home/x/SmartCabinet/arm_test.tar");
}

void Control::InstallExe(QString exeName)
{
#ifdef TEST
    qDebug()<<"----"<<"Now install "<<exeName<<" exec, please wait for a little";
#endif
    QProcess *proe = new QProcess;
    proe->start("/home/x/SmartCabinet/build-untitled-Desktop_Qt_5_7_1_GCC_64bit-Debug/untitled");
    this->deleteLater();
}

bool Control::UnpackVersion(QJsonDocument jd , QString *armVersion, QString *armUrl)
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

void Control::ShowExecStep(QString info)
{
    QString newLine = "\n";
    info_output += newLine + info;
    setBrowser->setText(info_output);
}

void Control::WaitTaskInfo(int tim)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<tim)
    {
        QCoreApplication::processEvents();
    }
}
