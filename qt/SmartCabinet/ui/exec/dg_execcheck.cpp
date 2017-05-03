#include "dg_execcheck.h"
#include "ui_dg_execcheck.h"

Dg_ExecCheck::Dg_ExecCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_ExecCheck)
{
    ui->setupUi(this);

}

Dg_ExecCheck::~Dg_ExecCheck()
{
    delete ui;
}




