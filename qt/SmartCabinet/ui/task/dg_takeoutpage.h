#ifndef DG_TAKEOUTPAGE_H
#define DG_TAKEOUTPAGE_H

#include <QObject>
#include "ui/task/dg_taskclass.h"

class Dg_TakeOutPage : public Dg_TaskClass
{
    Q_OBJECT
public:
    Dg_TakeOutPage();

private:

    void DownLoad_TaskList();
    void ShowExecuteWindow();

};

#endif // DG_TAKEOUTPAGE_H
