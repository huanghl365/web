#ifndef SERIALPORTWORKING_H
#define SERIALPORTWORKING_H

#include <QObject>
#include "network/netcommunication.h"

class SerialPortWorking : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortWorking(QObject *parent = 0);
    ~SerialPortWorking();

signals:

public slots:

private slots:
    void Model_A(int drawer_ID,int send_TaskNum);
    void Model_B();
    void ControlTimer(bool order);
    void CreateSerialPort();

private:
    NetCommunication *netCommunication;
    QTimer *timer;

    bool Juage_MCU_ReceivedCommand(int drawer_ID, int &send_TaskNum);
    bool OpenLock(int drawer_ID);

    int Request_LockStatus(int &lock_ID);

    void Save_Waring_to_SQL(QString json_str);
    void Save_Ban_to_SQL(QString json_str, QString ban_object);
    void WaitTimer(int time);
    void DrawerAbnormal(int &drawer_ID);
    void Request_DrawerAlarm(int &drawer_ID);
    void Received_MCU_TaskEndReply(int &drawerID);



};

#endif // SERIALPORTWORKING_H
