#ifndef DG_SCRAP_EXEC_H
#define DG_SCRAP_EXEC_H

#include <QObject>
#include "ui/exec/dg_execclass.h"

class Dg_Scrap_Exec : public Dg_ExecClass
{
    Q_OBJECT
public:
    Dg_Scrap_Exec();
private:
    void UploadTask2Server();

};

#endif // DG_SCRAP_EXEC_H
