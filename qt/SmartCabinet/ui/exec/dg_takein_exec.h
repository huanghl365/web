#ifndef DG_TAKEIN_EXEC_H
#define DG_TAKEIN_EXEC_H

#include <QObject>
#include "ui/exec/dg_execclass.h"

class Dg_TakeIn_Exec : public Dg_ExecClass
{
    Q_OBJECT
public:
    Dg_TakeIn_Exec();

private:
    void UploadTask2Server();
    void ShowPage();
};

#endif // DG_TAKEIN_EXEC_H
