#include "autoupdata.h"
#include "ui_autoupdata.h"

AutoUpdata::AutoUpdata(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutoUpdata)
{
    ui->setupUi(this);
}

AutoUpdata::~AutoUpdata()
{
    delete ui;
}
