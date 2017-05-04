#ifndef DG_REPLACE_H
#define DG_REPLACE_H

#include <QObject>
#include "ui/task/dg_taskclass.h"

class Dg_Replace : public Dg_TaskClass
{
public:
    Dg_Replace();

private:
    void DownLoad_TaskList();
    void ShowExecuteWindow();
};

#endif // DG_REPLACE_H
