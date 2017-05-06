#include "dg_execclass.h"
#include "ui_dg_execclass.h"

#include "common/globalvariable.h"
#include "common/uart4stm.h"

#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlQuery>
#include <QDateTime>

#include <QMap>

Dg_ExecClass::Dg_ExecClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dg_ExecClass)
{
    ui->setupUi(this);
    this->showFullScreen();

    t_exec = new QSqlTableModel();
    query = new QSqlQuery;
    netCommunication = new NetCommunication();
    agetiaInfo = new Save_AgentiaInfo;


    /******initially******/
    save_drawer.clear();
    save_number.clear();
    save_position.clear();
    save_previousErrorPosition.clear();
    save_warningInfo.clear();
    save_outstripTimer.clear();
    save_needDel.clear();

    //变量初始化
    InitializeStruct();

   /*********************/
    count = 0;
    isContinueExecute = true;
    isPBjump = false;
    modelOptional = "";

    /*******************************/

    connect(this, SIGNAL(ControlTimer_SerialPort(bool)), \
            serialPortControl_G, SLOT(ControlTimer(bool)));

    connect(this, SIGNAL(TaskCommand_Send2MCU(int,int)), \
            serialPortControl_G, SLOT(Model_A(int,int)));


//    SetTitle("点验操作");
//    All_Control();
}

Dg_ExecClass::~Dg_ExecClass()
{
    delete ui;
    t_exec->deleteLater();
    netCommunication->deleteLater();
    delete query;
    delete agetiaInfo;
}

/******************************/
void Dg_ExecClass::All_Control()
{
    int status = -3;
    ControlTimer("close");
    ShowPage();

    if(CheckTable_haveData(tableName))
    {
        Control_GetDrawerInfo(modelOptional);
        Exec_Task(status);
    }

    UploadTask2Server();
    //
    waitTime(1000);
    //
    ControlTimer("open");
    ClosePage();
    Change_SQL_Table("在位");
}

void Dg_ExecClass::Exec_Task(int &status)
{
    while (NextTask()&&isContinueExecute)
    {
        ShowCurrentAgentiaInfo(count);
        Send_TaskCommandModelOptional(modelOptional);

        if (CheckTask_isSendSuccess())
        {
            Initiative_CheckLock();
            Scan_ShowMCUReply(status);
        }

        if (status == TASK_HAVENOTEXEC)
            HandleTask(haveNotExecTask_CLOSE);
        else if (status == TASK_OVER)
            HandleTask(havetaskOver_CLOSE);

        ShowCurrentAgentiaInfo(count);
        GetError();//异常上报
        FlagInit();
        count++;
        waitTime(100);
    }

    ShowCurrentAgentiaInfo(save_drawer.size());
}

void Dg_ExecClass::Scan_ShowMCUReply(int &status)
{
    while (CheckLock_isOpen())
    {
        status = CheckDrawerTaskStatus();

        if (status == TASK_ERROR)
        {
            HandleTask(haveErrorHandle);
        }
        else if (status == TASK_HAVENOTEXEC)
        {
            if (!isPBjump)
                HandleTask(haveNotExecTask);

            if (isPBjump && !Is_DrawerNo_Equal())
                TextMessageShowContent("", "请关闭抽屉");
            else if (isPBjump && Is_DrawerNo_Equal())
            {
                isPBjump = false;
                break;
            }

        }
        else if (status == TASK_OVER)
        {
            HandleTask(havetaskOver);

            if (!Is_DrawerNo_Equal())
                TextMessageShowContent("", "请关闭抽屉");
            else
                break;
        }

        if (!isContinueExecute)
        {
            while(CheckLock_isOpen())
                TextMessageShowContent("", "请关闭抽屉");

            break;
        }

        waitTime(100);
    }

    if (0 == currentLockStatus)
    {
        if (status == TASK_ERROR)
            HandleTask(haveErrorHandle_CLOSE);
    }
}

/*****************************/

bool Dg_ExecClass::Is_DrawerNo_Equal()
{
    if (count < save_drawer.size() -1 )
    {
        if (save_drawer[count] == save_drawer[count + 1])
            return true;
    }

    return false;
}

bool Dg_ExecClass::CheckTable_haveData(QString tableName)
{
    query->exec(QString("select * from %1").arg(tableName));
    query->last();
    int rowCount = query->at() + 1;

    if (0 < rowCount)
        return true;

    return false;
}

bool Dg_ExecClass::CheckLock_isOpen()
{


    if (currentLockStatus)
    {
        return true;
    }

    return false;
}

bool Dg_ExecClass::CheckTask_isSendSuccess()
{
    is_MCU_Completesendcommandtask = false;
    while(!is_MCU_Completesendcommandtask)
    {
        waitTime(50);
    }

    if (is_ARM_receivedReply_from_MCU)
        return true;

    return false;
}

bool Dg_ExecClass::UnpackageJson_Task(QJsonDocument str)
{
    QJsonValue s_json[1] = {0};
    bool s_success = false;
    QJsonObject analyze_Z = str.object();

    s_json[0] = analyze_Z["success"].toBool();
    s_success = s_json[0].toBool();

    if (s_success)
    {
        return true;
    }

    return false;
}

/*****************************/

int Dg_ExecClass::CheckDrawerTaskStatus()
{
    if(TASK_ERROR == is_MCU_taskExecuteStatus)
        return TASK_ERROR;
    else if (TASK_HAVENOTEXEC == is_MCU_taskExecuteStatus)
        return TASK_HAVENOTEXEC;
    else if (TASK_OVER == is_MCU_taskExecuteStatus)
        return TASK_OVER;
    else if (TASK_NOTREPLY == is_MCU_taskExecuteStatus)
        return TASK_NOTREPLY;
}



/*****************************/
void Dg_ExecClass::ShowPage()
{

}

void Dg_ExecClass::Initiative_CheckLock()
{
    is_MCU_CompleteCheckLockStatus = false;
    while(!is_MCU_CompleteCheckLockStatus)
    {
        waitTime(100);
    }
}

void Dg_ExecClass::ShowCurrentAgentiaInfo(int i)
{
    if (modelOptional == "Single")
    {
        QString num = "";
        if (i < save_number.size())
            num = QString::number(save_number[i]);
        else
            num = "";

        t_exec->setFilter(QString("id like '%%1%'").arg(num));//筛选结果
    }
    else if (modelOptional == "Mul")
    {
        QString num = "";
        if (i < save_drawer.size())
            num = QString::number(save_drawer[i]);
        else
            num = "";

        t_exec->setFilter(QString("drawerNo like '%%1%'").arg(num));//筛选结果

    }
}

void Dg_ExecClass::Control_GetDrawerInfo(QString model)
{
    if (model == "Single")
        GetDrawerAndPosition_Singletaske();
    else if (model == "Mul")
        GetDrawer();
}
//获取抽屉号和位置
void Dg_ExecClass::GetDrawerAndPosition_Singletaske()
{
    int rowCount = t_exec->rowCount();

    int currentDrawer = -1;
    int currentPosition = -1;
    int currentNumber = -1;

    for (int i = 0; i < rowCount; i++)
    {
        currentDrawer = t_exec->data(t_exec->index(i, s_drawerColumn)).toInt();
        currentPosition = t_exec->data(t_exec->index(i, s_positioinColumn)).toInt();
        currentNumber = t_exec->data(t_exec->index(i, s_orderColumn)).toInt();

        save_drawer.insert(i, currentDrawer);
        save_position.insert(i, currentPosition);
        save_number.insert(i, currentNumber);
    }
}

//获取抽屉号
void Dg_ExecClass::GetDrawer()
{
    save_drawer.clear();
    int rowCount = t_exec->rowCount();

    int currentDrawer = -1;
    int preDrawerNo = -1;

    for (int i = 0; i < rowCount; i++)
    {
        currentDrawer = t_exec->data(t_exec->index(i, s_drawerColumn)).toInt();

        if (preDrawerNo != currentDrawer)
        {
            preDrawerNo = currentDrawer;
            save_drawer.append(currentDrawer);
        }
    }
}

void Dg_ExecClass::GetPositionNum()
{
    int rowCount = t_exec->rowCount();
    int currentPosition = -1;
    save_position.clear();

    for (int i = 0; i < rowCount; i++)
    {
        currentPosition = t_exec->data(t_exec->index(i, s_positioinColumn)).toInt();
        save_position.insert(i, currentPosition);
    }
}

void Dg_ExecClass::Send_TaskCommandModelOptional(QString model)
{
    if (model == "Mul")
        Send_TaskInfo2MCU_Mul();
    else if (model == "Single")
        Send_TaskInfo2MCU_Single();
}

void Dg_ExecClass::Send_TaskInfo2MCU_Single()
{
    int drawer_ID = save_drawer[count];
    int send_ActNum = 1;
    send_positionNo_G[0] = save_position[count];

    emit TaskCommand_Send2MCU(drawer_ID, send_ActNum);

}

void Dg_ExecClass::Send_TaskInfo2MCU_Mul()
{
    //获取位置
    GetPositionNum();
    for (int i = 0; i < 64; i++)
    {
        send_positionNo_G[0] = 0;
    }
    for (int i = 0; i < save_position.size(); i++)
    {
        send_positionNo_G[i] = save_position[i];
    }

    int drawer_ID = save_drawer[count];
    emit TaskCommand_Send2MCU(drawer_ID, save_position.size());
}

void Dg_ExecClass::on_CB_return_clicked()
{
    HandleTask(PB_return);
}

void Dg_ExecClass::on_pB_jump_clicked()
{
    HandleTask(PB_jump);
}

void Dg_ExecClass::on_pB_sure_clicked()
{
    if (count < save_drawer.size())
    {
        int volum_i = ui->lE_volum->text().toInt();
        QString unit = ui->CB_unit->currentText();
        QString volum = QString::number(volum_i);
        if (volum != "")
        {
            QString newVolum = volum + unit;

            t_exec->setData(t_exec->index(0, s_doseColumn), newVolum);
            t_exec->submitAll();
        }
    }
}

void Dg_ExecClass::waitTime(int time)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<time)
    {
        QCoreApplication::processEvents();
    }
}

void Dg_ExecClass::InitializeStruct()
{
    agetiaInfo->getC_agentiaId = 0;
    agetiaInfo->getC_bottleCapacity = "";
    agetiaInfo->getC_dose = "";
    agetiaInfo->getC_expireDate = "";
    agetiaInfo->getC_judgeAttitude = "";
    agetiaInfo->getC_position = 0;
}

bool Dg_ExecClass::NextTask()
{

    if ( count < save_drawer.size())
    {
        waitTime(500);
        return true;
    }

    return false;
}

void Dg_ExecClass::GetError()
{
    InitializeStruct();
    bool isSuccess = false;
    QString description = QString("用户： %1 , 有如下异常操作 抽屉号： %2 ,位置如下：").arg(userId).arg(save_drawer[count]);
    if (!save_warningInfo.empty())
    {
        for (int i = 0; i < save_warningInfo.size(); i++)
        {
            if (0 != save_warningInfo[i])
            {
                description += QString::number(save_warningInfo[i])+", ";
            }
            else
            {
                break;
            }
        }

        QString str = netCommunication->PackageJson_warningLog(userId, description);
        if (netCommunication->PostHttp("warningLog", str, 2))
        {
            if (UnpackageJson_Task(netCommunication->ServerReply))
            {
                isSuccess = true;
            }
            else
            {
                isSuccess = false;
            }
        }
        if (!isSuccess)
        {
            agetiaInfo->getC_judgeAttitude = "报警";
            agetiaInfo->getC_bottleCapacity = str;
            WriteSQL_NetworkError();
        }
    }

    save_warningInfo.clear();

}

void Dg_ExecClass::WriteSQL_NetworkError()
{
    query->exec("select * from T_WaitPostInfo");
    query->last();
    int rowCount = query->at() + 1;

    query->prepare("insert into T_WaitPostInfo (id,userId,agentiaId,\
                  positionId,dose,expireDate,bottleCapacity,judgeAttitude) \
                    values (?,?,?,?,?,?,?,?)");

    query->addBindValue(rowCount + 1);
    query->addBindValue(userId);
    query->addBindValue(agetiaInfo->getC_agentiaId);
    query->addBindValue(agetiaInfo->getC_position);
    query->addBindValue(agetiaInfo->getC_dose);
    query->addBindValue(agetiaInfo->getC_expireDate);
    query->addBindValue(agetiaInfo->getC_bottleCapacity);
    query->addBindValue(agetiaInfo->getC_judgeAttitude);
    query->exec();
}

void Dg_ExecClass::Change_SQL_Table(QString name)//"在位"  "借出"
{
    t_exec->select();

    int rowCount = t_exec->rowCount();
    for (int i = 0; i < rowCount; i++)
    {
        QString decision = t_exec->data(t_exec->index(i, s_judgeStatusColumn)).toString();
        if (decision == "完成" || decision == "审批完成")
        {
            QString name = t_exec->data(t_exec->index(i, s_nameColumn)).toString();
            save_needDel.append(name);
        }
    }

    //后期可以改为通过试剂ID
    for (int j = 0; j < save_needDel.size(); j++)
    {
        query->prepare(QString("update T_AgentiaSaving set judgeAttitude='%1',userDisplayName='%2' \
                               where agentiaName='%3'")
               .arg(name).arg("").arg(save_needDel[j]));
        query->exec();
    }
    save_needDel.clear();
}

void Dg_ExecClass::UploadTask2Server()
{

}

void Dg_ExecClass::UploadWarning(QString json_str, QString warningContent, int model)
{
    bool isSuccess = false;

    InitializeStruct();
    if (netCommunication->PostHttp("warningLog", json_str, 2))
    {
        if (UnpackageJson_Task(netCommunication->ServerReply))
        {
            TextMessageShowContent("green", warningContent);
            isSuccess = true;
        }
    }

    if (!isSuccess)
    {
        agetiaInfo->getC_judgeAttitude = "报警";

        if (model == NetworkTask)
        {
            int taskId = t_exec->data(t_exec->index(0, s_agetiaIdColumn)).toInt();
            agetiaInfo->getC_agentiaId = taskId;
        }
        agetiaInfo->getC_bottleCapacity = json_str;
        WriteSQL_NetworkError();
    }
}

void Dg_ExecClass::UploadDisableDrawerAndPosition()
{
    bool isSuccess = false;
    QString str = "";
    InitializeStruct();

    str = netCommunication->PackageJson_disablePosition(userId, CABINETNO, save_drawer[count],\
                                                        save_position[count]);
    agetiaInfo->getC_agentiaId = save_drawer[count];
    agetiaInfo->getC_position = save_position[count];
    agetiaInfo->getC_judgeAttitude = "禁用位置";

    if (netCommunication->PostHttp("disablePosition", str, 2))
    {
        if (UnpackageJson_Task(netCommunication->ServerReply))
        {
            isSuccess =  true;
            TextMessageShowContent("", "此抽屉异常，禁用状态");
        }
    }

    if (!isSuccess)
    {
        agetiaInfo->getC_bottleCapacity = str;
        WriteSQL_NetworkError();
    }
}

void Dg_ExecClass::TextMessageShowContent(QString colorType, QString content)
{
    if (colorType == "green")
        ui->textB_message->setTextColor(Qt::green);
    else if (colorType == "red")
        ui->textB_message->setTextColor(Qt::red);
    else if (colorType == "blue")
        ui->textB_message->setTextColor(Qt::blue);
    else if (colorType == "")
        ui->textB_message->setTextColor(Qt::black);

    ui->textB_message->setText(content);
    waitTime(100);
}

void Dg_ExecClass::isSaveError(int goal)
{
    int value = 0;

    if (!save_previousErrorPosition.empty())
    {
        for (int i = 0; i < save_previousErrorPosition.size(); i++)
        {
            if (goal == save_previousErrorPosition[i])
            {
                value = save_outstripTimer[goal];
                if (value >= 5)
                {
                    if (save_warningInfo.indexOf(goal) == -1)
                    {
                        save_warningInfo.append(goal);//预备上传内容
                    }
                    save_outstripTimer[goal] = 0;
                }
                save_outstripTimer[goal] = value + 1;
                break;
            }
        }
    }
}

void Dg_ExecClass::SetInputReg()
{
    //正则表达
    QRegExp regx_bottleCapacity("[0-9]+$");//"[a-zA-Z0-9]+$" 长度7纯数字输入3.3格式
    QValidator *validator_bottleCapacity = new QRegExpValidator(regx_bottleCapacity,ui->lE_volum);
    ui->lE_volum->setValidator(validator_bottleCapacity);
}

void Dg_ExecClass::ChangeStatus_SingleTask(QString content)
{
    QString info = t_exec->data(t_exec->index(0, s_judgeStatusColumn)).toString();
    QString judge = "审批";

    if (info == "审批" )
    {
        ChangeCellContent(0, s_judgeStatusColumn, judge+content);
    }
    else
    {
        ChangeCellContent(0, s_judgeStatusColumn, content);
    }

    t_exec->submitAll();
    qDebug()<< t_exec->data(t_exec->index(0, s_judgeStatusColumn)).toString();
}

void Dg_ExecClass::ChangeStatus_MulTask(QString content)
{
    int rowCount = t_exec->rowCount();
    if (content == "跳过")
    {
        if (0 != Alarm_No[2][0])
        {
            for (int i = 0; i < 64; i++)
            {
                if (0 != Alarm_No[2][i])
                {
                    for(int i = 0; i < rowCount; i++)
                    {
                        int position = t_exec->data(t_exec->index(i, s_positioinColumn)).toInt();
                        if (position == Alarm_No[2][i])
                        {
                            QString info = t_exec->data(t_exec->index(i, s_judgeStatusColumn)).toString();

                            if (info == "审批" )
                            {
                                t_exec->setData(t_exec->index(i, s_judgeStatusColumn), "审批跳过");
                            }
                            else
                            {
                                t_exec->setData(t_exec->index(i, s_judgeStatusColumn), "跳过");
                            }

                            t_exec->submitAll();
                        }
                    }
                }
            }
        }
    }
    else if (content == "完成")
    {
        for (int i = 0; i < rowCount; i++)
        {
            ChangeCellContent(i, s_judgeStatusColumn, "完成");
        }
    }
    t_exec->submitAll();
}

void Dg_ExecClass::ChangeCellContent(int row, int column, QString content)
{
    t_exec->setData(t_exec->index(row, column), content);
    t_exec->submitAll();
}

void Dg_ExecClass::ControlTimer(QString status)
{
    if (status == "open")
        emit ControlTimer_SerialPort(true);
    else if (status == "close")
        emit ControlTimer_SerialPort(false);
}

void Dg_ExecClass::ClosePage()
{
    this->deleteLater();
}

void Dg_ExecClass::FlagInit()
{
    isPBjump = false;
}

void Dg_ExecClass::SetTitle(QString name)
{
    ui->lB_title->setText(name);
}

void Dg_ExecClass::HandleTask(int order)
{
    switch (order) {
    case haveErrorHandle:
    {
        if (0 != Alarm_No[0][0])
        {
            QString warning = "有错误操作，记录位置：";
            for (int i = 0; i < 64; i++)
            {
                if (0 != Alarm_No[0][i])
                {
                    warning += QString::number(Alarm_No[0][i])+", ";
                    isSaveError(Alarm_No[0][i]);
                }
                else
                {
                    break;
                }
            }
            warning = warning + "    请纠正";
            ui->textB_message->setText(warning);
        }

        save_previousErrorPosition.clear();
        for (int i = 0; i < 64; i++)
        {
            if (0 != Alarm_No[0][i])
            {
                save_previousErrorPosition[i] = Alarm_No[0][i];
            }
            else
                break;
        }

        break;
    }
    case haveNotExecTask:
    {
        if (0 != Alarm_No[2][0])
        {
            QString warning = "有未完成，位置为： ";
            for (int i = 0; i < 64; i++)
            {
                if (0 != Alarm_No[2][i])
                {
                    warning += QString::number(Alarm_No[2][i])+", ";
                }
                else
                {
                    break;
                }
            }
            warning = warning + "   可点击按钮跳过";
            TextMessageShowContent("", warning);
        }

        break;
    }
    case havetaskOver:
    {
//        TextMessageShowContent("", "任务完成，正在执行上报，请稍候");
        break;
    }
    case haveErrorHandle_CLOSE:
    {
        isContinueExecute = false;
        QString str = netCommunication->PackageJson_warningLog(userId,QString("非法操作，机柜编号:%1  抽屉编号编号：%2").arg(CABINETNO).arg(save_drawer[count]));
        UploadWarning(str, QString("非法操作，机柜编号:%1  抽屉编号编号：%2").arg(CABINETNO).arg(save_drawer[count]), Drawer_error);
        UploadDisableDrawerAndPosition();

        break;
    }
    case haveNotExecTask_CLOSE:
    {
        if (modelOptional == "Mul")
            ChangeStatus_MulTask("跳过");
        else if (modelOptional == "Single")
            ChangeStatus_SingleTask("跳过");
        break;
    }
    case havetaskOver_CLOSE:
    {
        if (modelOptional == "Mul")
            ChangeStatus_MulTask("完成");
        else if (modelOptional == "Single")
            ChangeStatus_SingleTask("完成");
        break;
    }
    case PB_jump:
    {
        isPBjump = true;

        break;
    }
    case PB_return:
    {
        isContinueExecute = false;

        break;
    }
    default:
        break;
    }
}
//show
/***************************************/
void Dg_ExecClass::Show_TakeIn()
{
    t_exec->setTable(QString("%1").arg(tableName));
    t_exec->select();

    t_exec->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    t_exec->setHeaderData(1, Qt::Horizontal, QObject::tr("试剂名"));
    t_exec->setHeaderData(2, Qt::Horizontal, QObject::tr("状态"));
    t_exec->setHeaderData(3, Qt::Horizontal, QObject::tr("抽屉号"));
    t_exec->setHeaderData(4, Qt::Horizontal, QObject::tr("位置号"));
    t_exec->setHeaderData(6, Qt::Horizontal, QObject::tr("剩余容积"));

    t_exec->setEditStrategy(QSqlTableModel::OnManualSubmit);
    t_exec->sort(4, Qt::AscendingOrder);

    ui->TV_exec->setModel(t_exec);

//    ui->TV_exec->setColumnHidden(5,true);
//    ui->TV_exec->setColumnHidden(7,true);
//    ui->TV_exec->setColumnHidden(8,true);
//    ui->TV_exec->setColumnHidden(9,true);

    ui->TV_exec->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TV_exec->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TV_exec->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->TV_exec->sortByColumn(s_drawerColumn, Qt::AscendingOrder);
}

void Dg_ExecClass::Show_TakeOut()
{
    t_exec->setTable(QString("%1").arg(tableName));
    t_exec->select();

    t_exec->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    t_exec->setHeaderData(1, Qt::Horizontal, QObject::tr("试剂名"));
    t_exec->setHeaderData(2, Qt::Horizontal, QObject::tr("状态"));
    t_exec->setHeaderData(5, Qt::Horizontal, QObject::tr("剩余容积"));
    t_exec->setHeaderData(6, Qt::Horizontal, QObject::tr("抽屉号"));
    t_exec->setHeaderData(7, Qt::Horizontal, QObject::tr("位置号"));

    t_exec->setEditStrategy(QSqlTableModel::OnManualSubmit);
    t_exec->sort(4, Qt::AscendingOrder);

    ui->TV_exec->setModel(t_exec);

    ui->TV_exec->setColumnHidden(3,true);
    ui->TV_exec->setColumnHidden(4,true);
    ui->TV_exec->setColumnHidden(8,true);
    ui->TV_exec->setColumnHidden(9,true);
    ui->TV_exec->setColumnHidden(10,true);
    ui->TV_exec->setColumnHidden(11,true);
    ui->TV_exec->setColumnHidden(12,true);
    ui->TV_exec->setColumnHidden(13,true);
    ui->TV_exec->setColumnHidden(14,true);
    ui->TV_exec->setColumnHidden(15,true);


    ui->TV_exec->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TV_exec->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TV_exec->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    //降序
    ui->TV_exec->sortByColumn(6, Qt::AscendingOrder);
}

void Dg_ExecClass::Show_BackTakeOut()
{
    t_exec->setTable(QString("%1").arg(tableName));
    t_exec->select();

    t_exec->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    t_exec->setHeaderData(1, Qt::Horizontal, QObject::tr("试剂名"));
    t_exec->setHeaderData(2, Qt::Horizontal, QObject::tr("状态"));
    t_exec->setHeaderData(5, Qt::Horizontal, QObject::tr("剩余容积"));
    t_exec->setHeaderData(6, Qt::Horizontal, QObject::tr("抽屉号"));
    t_exec->setHeaderData(7, Qt::Horizontal, QObject::tr("位置号"));

    t_exec->setEditStrategy(QSqlTableModel::OnManualSubmit);
    t_exec->sort(4, Qt::AscendingOrder);

    ui->TV_exec->setModel(t_exec);

    ui->TV_exec->setColumnHidden(3,true);
    ui->TV_exec->setColumnHidden(4,true);
    ui->TV_exec->setColumnHidden(8,true);
    ui->TV_exec->setColumnHidden(9,true);
    ui->TV_exec->setColumnHidden(10,true);
    ui->TV_exec->setColumnHidden(11,true);
    ui->TV_exec->setColumnHidden(12,true);
    ui->TV_exec->setColumnHidden(13,true);
    ui->TV_exec->setColumnHidden(14,true);
    ui->TV_exec->setColumnHidden(15,true);

    ui->TV_exec->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TV_exec->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TV_exec->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->TV_exec->sortByColumn(6, Qt::AscendingOrder);

}

/***************************************/
//upload database
void Dg_ExecClass::TakeOut()
{
    QString json_str = "";
    int taskId = -1;
    QString decision = "";

    t_exec->select();

    int rowCount = t_exec->rowCount();
    for (int i = 0; i < rowCount; i++)
    {
        bool isSuccess = false;
        InitializeStruct();
        decision = t_exec->data(t_exec->index(i, s_judgeStatusColumn)).toString();

        if ("审批完成" == decision)
        {
            taskId = t_exec->data(t_exec->index(i, s_agetiaIdColumn)).toInt();
            json_str = netCommunication->PackageJson_taskComplete(userId, taskId);

            if (netCommunication->PostHttp("taskComplete", json_str, 2))
            {
                if (UnpackageJson_Task(netCommunication->ServerReply))
                {
                    ChangeCellContent(i, s_judgeStatusColumn, "上传成功");
                    isSuccess = true;
                }
            }

            if (isSuccess)
            {
                TextMessageShowContent("blue", "上传失败，已存储");
                agetiaInfo->getC_judgeAttitude = "任务";
                agetiaInfo->getC_agentiaId = taskId;

                WriteSQL_NetworkError();
            }

        }

        else if ("完成" == decision)
        {
            int positionId = t_exec->data(t_exec->index(i, s_positionIdColumn)).toInt();
            int agetiaId = t_exec->data(t_exec->index(i, s_agetiaIdColumn)).toInt();

            json_str = netCommunication->PackageJson_takeOut(userId, agetiaId,\
                                                             positionId);
            //上传成功
            if (netCommunication->PostHttp("takeOut", json_str, 2))
            {
                if (UnpackageJson_Task(netCommunication->ServerReply))
                {
                    ChangeCellContent(i, 2, "上传成功");
                    isSuccess = true;
                }
            }

            if (!isSuccess)
            {
                TextMessageShowContent("blue", "上传失败，已存储");
                agetiaInfo->getC_judgeAttitude = "取用";
                agetiaInfo->getC_agentiaId = agetiaId;
                agetiaInfo->getC_position = positionId;

                WriteSQL_NetworkError();
            }
        }
    }
}

void Dg_ExecClass::New_TakeIn()
{
    QString json_str = "";
    int taskId = -1;
    QString decision = "";

    t_exec->select();

    int rowCount = t_exec->rowCount();
    for (int i = 0; i < rowCount; i++)
    {
        bool isSuccess = false;
        InitializeStruct();
        decision = t_exec->data(t_exec->index(i, s_judgeStatusColumn)).toString();

        if ("审批完成" == decision)
        {
            taskId = t_exec->data(t_exec->index(i, s_agetiaTypeIdColumn)).toInt();
            json_str = netCommunication->PackageJson_taskComplete(userId, taskId);

            if (netCommunication->PostHttp("taskComplete", json_str, 2))
            {
                if (UnpackageJson_Task(netCommunication->ServerReply))
                {
                    ChangeCellContent(i, 2, "上传成功");
                    isSuccess = true;
                }
            }

            if (isSuccess)
            {
                TextMessageShowContent("blue", "上传失败，已存储");
                agetiaInfo->getC_judgeAttitude = "任务";
                agetiaInfo->getC_agentiaId = taskId;

                WriteSQL_NetworkError();
            }


        }

        else if ("完成" == decision)
        {
            int positionId = t_exec->data(t_exec->index(i, s_positionIdColumn)).toInt();
            int agetiaId = t_exec->data(t_exec->index(i, s_agetiaTypeIdColumn)).toInt();
            QString dose = t_exec->data(t_exec->index(i, s_doseColumn)).toString();
            QString bottle = t_exec->data(t_exec->index(i, 5)).toString();
            QString data = t_exec->data(t_exec->index(i, 7)).toString();

            json_str = netCommunication->PackageJson_putIn(userId, agetiaId, bottle, dose, data, positionId);
            //上传成功
            if (netCommunication->PostHttp("putIn", json_str, 2))
            {
                if (UnpackageJson_Task(netCommunication->ServerReply))
                {
                    ChangeCellContent(i, s_judgeStatusColumn, "上传成功");
                    isSuccess = true;
                }
            }

            if (!isSuccess)
            {
                TextMessageShowContent("blue", "上传失败，已存储");
                agetiaInfo->getC_judgeAttitude = "入柜";
                agetiaInfo->getC_agentiaId = agetiaId;
                agetiaInfo->getC_position = positionId;
                agetiaInfo->getC_dose = dose;
                agetiaInfo->getC_bottleCapacity = bottle;
                agetiaInfo->getC_expireDate = data;

                WriteSQL_NetworkError();
            }
        }
    }
}

void Dg_ExecClass::Back_TakeIn()
{
    QString json_str = "";
    int taskId = -1;
    QString decision = "";

    t_exec->select();

    int rowCount = t_exec->rowCount();
    for (int i = 0; i < rowCount; i++)
    {
        bool isSuccess = false;
        InitializeStruct();
        decision = t_exec->data(t_exec->index(i, s_judgeStatusColumn)).toString();

        if ("审批完成" == decision)
        {
            taskId = t_exec->data(t_exec->index(i, s_agetiaIdColumn)).toInt();
            json_str = netCommunication->PackageJson_taskComplete(userId, taskId);

            if (netCommunication->PostHttp("taskComplete", json_str, 2))
            {
                if (UnpackageJson_Task(netCommunication->ServerReply))
                {
                    ChangeCellContent(i, s_judgeStatusColumn, "上传成功");
                    isSuccess = true;
                }
            }

            if (isSuccess)
            {
                TextMessageShowContent("blue", "上传失败，已存储");
                agetiaInfo->getC_judgeAttitude = "任务";
                agetiaInfo->getC_agentiaId = taskId;

                WriteSQL_NetworkError();
            }


        }

        else if ("完成" == decision)
        {
            int positionId = t_exec->data(t_exec->index(i, s_positionIdColumn)).toInt();
            int agetiaId = t_exec->data(t_exec->index(i, s_agetiaIdColumn)).toInt();
            QString dose = t_exec->data(t_exec->index(i, s_doseColumn)).toString();

            json_str = netCommunication->PackageJson_giveBack(userId, agetiaId,\
                                                              dose, positionId);
            //上传成功
            if (netCommunication->PostHttp("giveBack", json_str, 2))
            {
                if (UnpackageJson_Task(netCommunication->ServerReply))
                {
                    ChangeCellContent(i, s_judgeStatusColumn, "上传成功");
                    isSuccess = true;
                }
            }

            if (!isSuccess)
            {
                TextMessageShowContent("blue", "上传失败，已存储");
                agetiaInfo->getC_judgeAttitude = "归还";
                agetiaInfo->getC_agentiaId = agetiaId;
                agetiaInfo->getC_position = positionId;
                agetiaInfo->getC_dose = dose;

                WriteSQL_NetworkError();
            }
        }
    }
}
