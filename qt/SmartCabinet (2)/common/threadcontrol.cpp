#include "threadcontrol.h"

ThreadControl::ThreadControl(QObject *parent) :
    QThread(parent)
{
    TC_timerUpdate = new TimerAndUpdate;
//    timerThread = new QThread;

    connect(TC_timerUpdate, SIGNAL(Timer_Task_Quit()), this, SIGNAL(Close_ALLPage()));
    connect(TC_timerUpdate, SIGNAL(Timer_Task_UpdateSQL()), this, SIGNAL(Update_SQL()));
}

void ThreadControl::ControlTimerThread(int order)
{

}

void ThreadControl::CreateThread()
{
//    TC_timerUpdate->moveToThread(timerThread);
}
