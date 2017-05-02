#ifndef FORMB_H
#define FORMB_H

#include <QWidget>

namespace Ui {
class FormB;
}

class FormB : public QWidget
{
    Q_OBJECT

public:
    explicit FormB(QWidget *parent = 0);
    ~FormB();

private:
    Ui::FormB *ui;
};

#endif // FORMB_H
