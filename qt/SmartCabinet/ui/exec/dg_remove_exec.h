#ifndef DG_REMOVE_EXEC_H
#define DG_REMOVE_EXEC_H

#include <QObject>
#include "ui/exec/dg_execclass.h"

class Dg_Remove_Exec : public Dg_ExecClass
{
    Q_OBJECT
public:
    Dg_Remove_Exec();
private:
    void UploadTask2Server();

};

#endif // DG_REMOVE_EXEC_H
