#include "common/initprocess.h"
#include "common/updatesql.h"
#include "common/Sql_Setting.h"
#include <QApplication>
#include <QDebug>
#include <QThread>
#include "inputnew/frminputnew.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    frmInputNew::Instance()->init("bottom", "black", 12, 10, 700, 230, 20, 20, 6, 45);

    qDebug()<<"Main Thread:  "<<QThread::currentThreadId();
    Initprocess initStartProgress;

    initStartProgress.CreateSql();
    initStartProgress.ReadConfig();
    initStartProgress.CreateThread();
    initStartProgress.StartThread();
    initStartProgress.OpenSerialPort();
    initStartProgress.UpdateLocalSql();
    initStartProgress.ShowLoginPage();
    initStartProgress.OpenKey();



    a.connect(&initStartProgress, SIGNAL(destroyed()), &a, SLOT(quit()));
    return a.exec();
}
