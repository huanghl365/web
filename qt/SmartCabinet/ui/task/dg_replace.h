#ifndef DG_REPLACE_H
#define DG_REPLACE_H

#include <QObject>
#include "ui/task/dg_taskclass.h"

class Dg_Replace : public Dg_TaskClass
{
    Q_OBJECT

public:
    Dg_Replace();

private:
    void DownLoad_TaskList();
};

#endif // DG_REPLACE_H
