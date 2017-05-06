#ifndef DG_TAKEOUT_EXEC_H
#define DG_TAKEOUT_EXEC_H

#include "ui/exec/dg_execclass.h"

class Dg_TakeOut_Exec : public Dg_ExecClass
{
    Q_OBJECT
public:
    Dg_TakeOut_Exec();

private:
    void UploadTask2Server();
    void ShowPage();

};

#endif // DG_TAKEOUT_EXEC_H
