#ifndef DG_REMOVE_H
#define DG_REMOVE_H

#include <QObject>
#include "ui/task/dg_taskclass.h"

class Dg_Remove : public Dg_TaskClass
{
public:
    Dg_Remove();

private:
    void DownLoad_TaskList();
};

#endif // DG_REMOVE_H
