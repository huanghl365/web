#ifndef DG_BACK_EXEC_H
#define DG_BACK_EXEC_H

#include <QObject>
#include "ui/exec/dg_execclass.h"


class Dg_Back_Exec : public Dg_ExecClass
{
    Q_OBJECT
public:
    Dg_Back_Exec();

private:
    void UploadTask2Server();
};

#endif // DG_BACK_EXEC_H
