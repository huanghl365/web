#include "dg_functionoptpage.h"
#include "ui_dg_functionoptpage.h"
#include "common/globalvariable.h"
#include "ui/task/dg_takeoutpage.h"
#include "ui/task/dg_checkpage.h"
#include "ui/task/dg_returnpage.h"
#include "ui/task/dg_takein.h"
#include "ui/task/dg_remove.h"
#include "ui/task/dg_scrap.h"
#include "ui/task/dg_replace.h"

#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>
#include <QCoreApplication>


Dg_FunctionOptPage::Dg_FunctionOptPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_FunctionOptPage)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->start(2000);
    connect(timer, SIGNAL(timeout()), SLOT(Auto_freshen()));

#ifndef TEST
    this->showFullScreen();
#endif

    Auto_freshen();


}

Dg_FunctionOptPage::~Dg_FunctionOptPage()
{
    delete ui;
}

void Dg_FunctionOptPage::on_pB_quit_clicked()
{
    emit KillProgram();
    this->deleteLater();
}

void Dg_FunctionOptPage::Auto_freshen()
{

#ifdef TEST
    qDebug()<<" AUTO_GET NETWORKSTATUS";
    qDebug()<<NetWorkStatus << "  NetWorkStatus";
#endif

    if (NETWORK_ONLINE == NetWorkStatus)
    {
        if (USER_SUPER == userRole)
        {
            UpGUI(ONLINE_ADMIN);
        }
        else if (USER_ADMIN == userRole || USER_GUEST == userRole)
        {
            UpGUI(ONLINE_ADMIN);
        }
//        else if (USER_GUEST == userRole)
//        {
//            UpGUI(ONLINE_GUEST);
//        }
    }
    else if (NETWORK_OFFLINE == NetWorkStatus)
    {
        UpGUI(OFFLINE_MODL);
    }
}

//界面刷新
void Dg_FunctionOptPage::UpGUI(int order)
{
    switch (order) {
    case OFFLINE_MODL:
    {
        ui->pB_check->hide();
        ui->pB_remove->hide();
        ui->pB_replace->hide();
        ui->pB_return->show();
        ui->pB_scrap->hide();
        ui->pB_takeIn->hide();
        ui->pB_takeOut->show();
        break;
    }
    case ONLINE_ADMIN:
    {
        ui->pB_check->show();
        ui->pB_remove->show();
        ui->pB_replace->show();
        ui->pB_return->show();
        ui->pB_scrap->show();
        ui->pB_takeIn->show();
        ui->pB_takeOut->show();
        break;
    }
    case ONLINE_GUEST:
    {
        ui->pB_check->hide();
        ui->pB_remove->hide();
        ui->pB_replace->hide();
        ui->pB_return->show();
        ui->pB_scrap->hide();
        ui->pB_takeIn->show();
        ui->pB_takeOut->show();
        break;
    }
    case ONLINE_SUPER:
    {
        ui->pB_check->show();
        ui->pB_remove->show();
        ui->pB_replace->show();
        ui->pB_return->show();
        ui->pB_scrap->show();
        ui->pB_takeIn->show();
        ui->pB_takeOut->show();
        break;
    }
    default:
        break;
    }
}

void Dg_FunctionOptPage::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        resetSignal = RESETTIMER;
    }
}

void Dg_FunctionOptPage::ClosePage()
{
    this->hide();
    waitTime(500);//delay
    timer->stop();
}

void Dg_FunctionOptPage::ShowFunctionPage()
{
    this->show();
    resetSignal = RESETTIMER;//重新开始自退出
}

void Dg_FunctionOptPage::waitTime(int time)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<time)
    {
        QCoreApplication::processEvents();
    }
}

void Dg_FunctionOptPage::on_pB_takeOut_clicked()
{
    Dg_TakeOutPage *task_TakeOut = new Dg_TakeOutPage;

    task_TakeOut->show();
    ClosePage();
    connect(task_TakeOut, SIGNAL(destroyed()), this, SLOT(ShowFunctionPage()));
    connect(task_TakeOut, SIGNAL(destroyed()), timer, SLOT(start()));
    connect(this, SIGNAL(KillProgram()), task_TakeOut, SLOT(deleteLater()));
}


void Dg_FunctionOptPage::on_pB_return_clicked()
{
    Dg_ReturnPage *task_Return = new Dg_ReturnPage;
    task_Return->show();
    ClosePage();
    connect(task_Return, SIGNAL(destroyed()), this, SLOT(ShowFunctionPage()));
    connect(task_Return, SIGNAL(destroyed()), timer, SLOT(start()));
    connect(this, SIGNAL(KillProgram()), task_Return, SLOT(deleteLater()));

}

void Dg_FunctionOptPage::on_pB_check_clicked()
{
    Dg_CheckPage *task_Check = new Dg_CheckPage;
    task_Check->show();
    ClosePage();
    connect(task_Check, SIGNAL(destroyed()), this, SLOT(ShowFunctionPage()));
    connect(task_Check, SIGNAL(destroyed()), timer, SLOT(start()));    
    connect(this, SIGNAL(KillProgram()), task_Check, SLOT(deleteLater()));

}

void Dg_FunctionOptPage::on_pB_takeIn_clicked()
{
    Dg_TakeIn *task_takeIn = new Dg_TakeIn;
    task_takeIn->show();
    ClosePage();
    connect(task_takeIn, SIGNAL(destroyed()), this, SLOT(ShowFunctionPage()));
    connect(task_takeIn, SIGNAL(destroyed()), timer, SLOT(start()));
    connect(this, SIGNAL(KillProgram()), task_takeIn, SLOT(deleteLater()));

}

void Dg_FunctionOptPage::on_pB_remove_clicked()
{
    Dg_Remove *task_remove = new Dg_Remove;
    task_remove->show();
    ClosePage();
    connect(task_remove, SIGNAL(destroyed()), this, SLOT(ShowFunctionPage()));
    connect(task_remove, SIGNAL(destroyed()), timer, SLOT(start()));
    connect(this, SIGNAL(KillProgram()), task_remove, SLOT(deleteLater()));
}

void Dg_FunctionOptPage::on_pB_scrap_clicked()
{
    Dg_Scrap *task_scrap = new Dg_Scrap;
    task_scrap->show();
    ClosePage();
    connect(task_scrap, SIGNAL(destroyed()), this, SLOT(ShowFunctionPage()));
    connect(task_scrap, SIGNAL(destroyed()), timer, SLOT(start()));
    connect(this, SIGNAL(KillProgram()), task_scrap, SLOT(deleteLater()));
}

void Dg_FunctionOptPage::on_pB_replace_clicked()
{
    Dg_Replace *task_replace = new Dg_Replace;
    task_replace->show();
    ClosePage();
    connect(task_replace, SIGNAL(destroyed()), this, SLOT(ShowFunctionPage()));
    connect(task_replace, SIGNAL(destroyed()), timer, SLOT(start()));
    connect(this, SIGNAL(KillProgram()), task_replace, SLOT(deleteLater()));
}

