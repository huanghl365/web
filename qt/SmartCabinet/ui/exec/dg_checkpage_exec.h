#ifndef DG_CHECKPAGE_EXEC_H
#define DG_CHECKPAGE_EXEC_H

#include <QObject>
#include "ui/exec/dg_execclass.h"

class Dg_CheckPage_Exec : public Dg_ExecClass
{
    Q_OBJECT
public:
    Dg_CheckPage_Exec();
private:
    void UploadTask2Server();

};

#endif // DG_CHECKPAGE_EXEC_H
