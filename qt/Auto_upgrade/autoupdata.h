#ifndef AUTOUPDATA_H
#define AUTOUPDATA_H

#include <QMainWindow>

namespace Ui {
class AutoUpdata;
}

class AutoUpdata : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutoUpdata(QWidget *parent = 0);
    ~AutoUpdata();

private:
    Ui::AutoUpdata *ui;
};

#endif // AUTOUPDATA_H
