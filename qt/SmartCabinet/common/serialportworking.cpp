#include "serialportworking.h"
#include "globalvariable.h"
#include "common/uart4stm.h"

#include <QThread>
#include <QElapsedTimer>
#include <QDebug>
#include <QSqlQuery>
#include <QTimer>

SerialPortWorking::SerialPortWorking(QObject *parent) : QObject(parent)
{
    netCommunication = new NetCommunication;


}

SerialPortWorking::~SerialPortWorking()
{
    delete timer;
    delete netCommunication;
    closeSerialPort();
    this->deleteLater();
}

/*************MODEL_A**********************************/
//处理ARM执行指令
void SerialPortWorking::Model_A(int drawer_ID, int send_TaskNum)
{
    qDebug()<<"Model_A   "<<QThread::currentThreadId();
    bool isContinueExecute_S = false;
    int lockStaut_frequency = 0;

    Received_MCU_TaskEndReply(drawer_ID);

    if (Juage_MCU_ReceivedCommand(drawer_ID, send_TaskNum))
    {

        OpenLock(drawer_ID);
        int status_Lock = Request_LockStatus(drawer_ID);
        if (LOCK_CURRENT_STATUS_CLOSE == status_Lock)
            isContinueExecute_S = false;
        else if (LOCK_CURRENT_STATUS_OPEN == status_Lock)
            isContinueExecute_S = true;
        else if (LOCK_CURRENT_STATUS_FAIL == status_Lock)
            DrawerAbnormal(drawer_ID);

        while (isContinueExecute_S)
        {
            Request_DrawerAlarm(drawer_ID);
            WaitTimer(500);
            if (lockStaut_frequency > 9)
            {
                if (LOCK_CURRENT_STATUS_CLOSE == Request_LockStatus(drawer_ID))
                {
                    break;

                }
            }
            else
            {
                lockStaut_frequency++;
            }
        }
    }
    else
        DrawerAbnormal(drawer_ID);


    Received_MCU_TaskEndReply(drawer_ID);

}

/*************MODEL_B***********************************/
//自扫描()
void SerialPortWorking::Model_B()
{
    qDebug()<<"serialPort thread:  "<< QThread::currentThreadId();
    qDebug() << "working---scan device";

//    for (int i = 0; i > cabinet_drawer_num; i++)
//    {
//        if (LOCK_CURRENT_STATUS_CLOSE != Request_LockStatus(i))
//        {
//            DrawerAbnormal(i);
//        }
//    }

}

/************************************************************************/
bool SerialPortWorking::Juage_MCU_ReceivedCommand(int drawer_ID, int &send_TaskNum)
{
    is_ARM_receivedReply_from_MCU = false;

    int mcu_receivedReply = wait4SetAct(drawer_ID, send_TaskNum, send_positionNo_G);

    if (0 == mcu_receivedReply)
    {
        is_ARM_receivedReply_from_MCU = true;
        return true;
    }
    return false;
}

bool SerialPortWorking::OpenLock(int drawer_ID)
{
    int taskStatus = IntoDrawer(drawer_ID);

    if (0 == taskStatus)
    {
        return true;
    }

    return false;
}


/****************/

int SerialPortWorking::Request_LockStatus(int &lock_ID)
{
    int lockStatus = RequestDrawerLock(lock_ID);

    if (LOCK_CURRENT_STATUS_OPEN == lockStatus)
    {
        currentLockStatus = LOCK_CURRENT_STATUS_OPEN;
        return LOCK_CURRENT_STATUS_OPEN;
    }
    else if (LOCK_CURRENT_STATUS_CLOSE == lockStatus)
    {
        currentLockStatus = LOCK_CURRENT_STATUS_CLOSE;
        return LOCK_CURRENT_STATUS_CLOSE;
    }

    currentLockStatus = LOCK_CURRENT_STATUS_FAIL;
    return LOCK_CURRENT_STATUS_FAIL;
}
/******************/

void SerialPortWorking::Request_DrawerAlarm(int &drawer_ID)
{
    int status = wait4Alarm(drawer_ID);

    if (TASK_ERROR == status)
        is_MCU_taskExecuteStatus = TASK_ERROR;
    else if (TASK_HAVENOTEXEC == status)
        is_MCU_taskExecuteStatus = TASK_HAVENOTEXEC;
    else if (TASK_OVER == status)
        is_MCU_taskExecuteStatus = TASK_OVER;
    else if (TASK_NOTREPLY == status)
        is_MCU_taskExecuteStatus = TASK_NOTREPLY;

}

void SerialPortWorking::Save_Waring_to_SQL(QString json_str)
{
    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM T_WaitPostInfo");
    query->last();
    int rowCount = query->at() + 1;

    query->prepare("insert into T_WaitPostInfo (id,bottleCapacity,judgeAttitude) \
                    values (?,?,?)");

    query->addBindValue(rowCount + 1);
    query->addBindValue(json_str);
    query->addBindValue(QString("报警"));
    query->exec();
}

void SerialPortWorking::Save_Ban_to_SQL(QString json_str, QString ban_object)
{
    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM T_WaitPostInfo");
    query->last();
    int rowCount = query->at() + 1;

    query->prepare("insert into T_WaitPostInfo (id,bottleCapacity,judgeAttitude) \
                    values (?,?,?)");

    query->addBindValue(rowCount + 1);
    query->addBindValue(json_str);
    query->addBindValue(ban_object);
    query->exec();
}

void SerialPortWorking::ControlTimer(bool order)
{
    qDebug() << order;
    if (true == order)
        timer->start();

    else
        timer->stop();
}

void SerialPortWorking::WaitTimer(int time)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<time)
    {
        QCoreApplication::processEvents();
    }
}

void SerialPortWorking::DrawerAbnormal(int &drawer_ID)
{
    QString json_str_warning = netCommunication->PackageJson_warningLog\
            (QString("抽屉异常，编号：%1").arg(drawer_ID));

    QString json_str_ban = netCommunication->PackageJson_disablePosition\
            (userId, CABINETNO, drawer_ID);

    Save_Waring_to_SQL(json_str_warning);
    Save_Ban_to_SQL(json_str_ban, "禁用抽屉");//禁用抽屉**禁用位置
}

void SerialPortWorking::Received_MCU_TaskEndReply(int &drawerID)
{
    //ActMode 暂时为0即可：任务完成
    wait4SendAct(drawerID, 0);

}

void SerialPortWorking::CreateSerialPort()
{
    is_OpenSerialPort = false;
    timer = new QTimer;
    timer->start(SERIALLOOP_TIMER);
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(Model_B()));


    qDebug()<<"serialPort thread:  "<< QThread::currentThreadId();
    qDebug()<<"00----------00----------00";

    if((createSerialPort(38400)))//打开串口38400
        is_OpenSerialPort = true;
}

void SerialPortWorking::ARM_Request_LockStatus(int drawer_ID)
{
    Request_DrawerAlarm(drawer_ID);
}

