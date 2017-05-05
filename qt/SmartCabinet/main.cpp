#include "common/initprocess.h"
#include "common/updatesql.h"
#include "common/Sql_Setting.h"
#include <QApplication>
#include <QDebug>
#include <QThread>



int main(int argc, char *argv[])
 {
    QApplication a(argc, argv);
    qDebug()<<"Main Thread:  "<<QThread::currentThreadId();


    Initprocess initStartProgress;

    //之后会讲配置信息重新改写
    initStartProgress.CreateSql();
    initStartProgress.ReadConfig();
    if (initStartProgress.Upgrade())
    {
        initStartProgress.StartSerialPortThread();
        initStartProgress.Start_Autoscan();
        initStartProgress.UpdateLocalSql();
        initStartProgress.ShowLoginPage();
        initStartProgress.OpenKey();        
    }

    a.connect(&initStartProgress, SIGNAL(destroyed()), &a, SLOT(quit()));
    return a.exec();
}
