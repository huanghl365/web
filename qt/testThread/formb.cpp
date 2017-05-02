#include "formb.h"
#include "ui_formb.h"

FormB::FormB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormB)
{
    ui->setupUi(this);
}

FormB::~FormB()
{
    delete ui;
}
