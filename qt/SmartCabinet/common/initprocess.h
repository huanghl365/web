#ifndef INITPROCESS_H
#define INITPROCESS_H

#include <QObject>

#include <QDebug>
#include <QMessageBox>

#include "ui/common/dg_loginpage.h"
#include "network/netcommunication.h"
#include "common/updatesql.h"


class Initprocess : public QObject
{
    Q_OBJECT
public:
    explicit Initprocess(QObject *parent = 0);
    ~Initprocess();

    void ReadConfig();
    void CreateSql();
    void StartSerialPortThread();
    void Start_Autoscan();
    bool Upgrade();
    void ShowLoginPage();
    void OpenKey();

signals:
    void CreateSerialPort();

public slots:
    void UpdateLocalSql();
    void Quit_Login();
private:
    NetCommunication *init_http_updateSheet;
    Dg_LoginPage *init_loginPage;
    UpdateSQL *updateSQL;

    bool UnpackVersion(QJsonDocument jd, QString *armVersion, QString *armUrl);



};

#endif // INITPROCESS_H
