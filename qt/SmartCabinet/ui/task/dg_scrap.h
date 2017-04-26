#ifndef DG_SCRAP_H
#define DG_SCRAP_H

#include <QObject>
#include "ui/task/dg_taskclass.h"

class Dg_Scrap : public Dg_TaskClass
{
    Q_OBJECT
public:
    Dg_Scrap();

private:
    void DownLoad_TaskList();
};

#endif // DG_SCRAP_H
