#ifndef DG_REPLACE_EXEC_H
#define DG_REPLACE_EXEC_H

#include <QObject>
#include "ui/exec/dg_execclass.h"

class Dg_Replace_Exec : public Dg_ExecClass
{
    Q_OBJECT
public:
    Dg_Replace_Exec();

private:
    void UploadTask2Server();
};

#endif // DG_REPLACE_EXEC_H
