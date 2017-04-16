#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QElapsedTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QProcess *proc = new QProcess;
//    proc->start("/home/x/SmartCabinet/build-untitled4-Desktop_Qt_5_7_1_GCC_64bit-Debug/untitled4");
//system("/home/x/SmartCabinet/build-untitled4-Desktop_Qt_5_7_1_GCC_64bit-Debug/untitled4");
    //    proc->waitForFinished();
    qDebug()<<"OK ---------";

    proc->startDetached("/home/x/SmartCabinet/build-untitled4-Desktop_Qt_5_7_1_GCC_64bit-Debug/untitled4");

//    waitTaskInfo(5000);
    exit(0);
//    this->close();
}

void MainWindow::waitTaskInfo(int tim)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<tim)
    {
        QCoreApplication::processEvents();
    }
}

