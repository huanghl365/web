#include "dg_execcheck.h"
#include "ui_dg_execcheck.h"
#include "common/globalvariable.h"

#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlQuery>

#include <QMap>

Dg_ExecCheck::Dg_ExecCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_ExecCheck)
{
    ui->setupUi(this);

    this->showFullScreen();

    t_exec = new QSqlTableModel(this);
    query = new QSqlQuery;
    netCommunication = new NetCommunication(this);
    agetiaInfo = new Save_AgentiaInfo;


    /******initially******/
    save_drawer.clear();
    save_position.clear();
    save_number.clear();
    save_previousErrorPosition.clear();
    save_warningInfo.clear();
    save_needDel.clear();

    //变量初始化
    InitializeStruct();

    s_drawerColumn = 6;
    s_positioinColumn = 7;
    s_judgeStatusColumn = 2;
    s_nameColumn = 1;
    s_agetiaIdColumn = 10;
    s_positionIdColumn = 11;
    s_number = 0;
    s_dose = 5;

    /*********************/
    count = 0;
    tableName = "T_AgentiaReturnExecute";

    /*******************************/

    connect(this, SIGNAL(ControlTimer_SerialPort(bool)), \
            serialPortControl_G, SLOT(ControlTimer(bool)));

    connect(this, SIGNAL(TaskCommand_Send2MCU(int,int)), \
            serialPortControl_G, SLOT(Model_A(int,int)));




}

Dg_ExecCheck::~Dg_ExecCheck()
{
    delete ui;
}



/******************************/
bool Dg_ExecCheck::All_Control()
{
    ControlTimer("close");
    ShowPage();
    if(CheckTable_haveData(tableName))
    {
        GetDrawerAndPosition();
        while (NextTask())
        {
            ShowCurrentAgentiaInfo(count);
            Send_TaskInfo2MCU();
            waitTime(1000);
            if (CheckTask_isSendSuccess())
            {
                int status = CheckDrawerTaskStatus();

                while (CheckLock_isOpen())
                {
                    if (status == TASK_ERROR)
                        HandleTask(haveErrorHandle);
                    else if (status == TASK_HAVENOTEXEC)
                        HandleTask(haveNotExecTask);
                    else if (status == TASK_OVER)
                        HandleTask(havetaskOver);

                    waitTime(500);
                }

                if (!CheckLock_isOpen())
                {
                    if (status == TASK_ERROR)
                        HandleTask(haveErrorHandle_CLOSE);
                    else if (status == TASK_HAVENOTEXEC)
                        HandleTask(haveNotExecTask_CLOSE);
                    else if (status == TASK_OVER)
                        HandleTask(havetaskOver_CLOSE);
                }
            }

            GetError();//异常上报
        }

        TextMessageShowContent("", "任务完成，正在执行上报，请稍候");
        UploadTask2Server();
    }
    else
        ClosePage();

    ControlTimer("open");

}

/*****************************/
bool Dg_ExecCheck::CheckTable_haveData(QString tableName)
{

    query->exec(QString("select * from %1").arg(tableName));
    query->last();
    int rowCount = query->at() + 1;

    if (0 < rowCount)
        return true;

    return false;
}

bool Dg_ExecCheck::CheckLock_isOpen()
{
    if (currentLockStatus)
        return true;

    return false;
}

bool Dg_ExecCheck::CheckTask_isSendSuccess()
{
    if (is_ARM_receivedReply_from_MCU)
        return true;

    return false;
}

bool Dg_ExecCheck::UnpackageJson_Task(QJsonDocument str)
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

int Dg_ExecCheck::CheckDrawerTaskStatus()
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
void Dg_ExecCheck::ShowPage()
{
    t_exec->setTable("T_AgentiaExecute");
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

void Dg_ExecCheck::ShowCurrentAgentiaInfo(int i)
{
    QString num = "";
    if (i < save_number.size())
        num = QString::number(save_number[i]);
    else
        num = "";

    t_exec->setFilter(QString("id like '%%1%'").arg(num));//筛选结果
}

void Dg_ExecCheck::GetDrawerAndPosition()
{
    int rowCount = t_exec->rowCount();

    int currentDrawer = -1;
    int currentPosition = -1;
    int currentNumber = -1;

    for (int i = 0; i < rowCount; i++)
    {
        currentDrawer = t_exec->data(t_exec->index(i, s_drawerColumn)).toInt();
        currentPosition = t_exec->data(t_exec->index(i, s_positioinColumn)).toInt();
        currentNumber = t_exec->data(t_exec->index(i, s_number)).toInt();

        save_drawer.insert(i, currentDrawer);
        save_position.insert(i, currentPosition);
        save_number.insert(i, currentNumber);
    }
}

void Dg_ExecCheck::Send_TaskInfo2MCU()
{
    int drawer_ID = save_drawer[count];
    int send_ActNum = 1;
    send_positionNo_G[0] = save_position[count];

    emit TaskCommand_Send2MCU(drawer_ID, send_ActNum);

}

void Dg_ExecCheck::on_CB_return_clicked()
{
    HandleTask(PB_return);
}

void Dg_ExecCheck::on_pB_jump_clicked()
{
    HandleTask(PB_jump);
}

void Dg_ExecCheck::on_pB_sure_clicked()
{
    if (count < save_drawer.size())
    {
        int volum_i = ui->lE_volum->text().toInt();
        QString unit = ui->CB_unit->currentText();
        QString volum = QString::number(volum_i);
        if (volum != "")
        {
            QString newVolum = volum + unit;

            t_exec->setData(t_exec->index(0, s_dose), newVolum);
            t_exec->submitAll();
        }
    }
}

void Dg_ExecCheck::waitTime(int time)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<time)
    {
        QCoreApplication::processEvents();
    }
}

void Dg_ExecCheck::InitializeStruct()
{
    agetiaInfo->getC_agentiaId = 0;
    agetiaInfo->getC_bottleCapacity = "";
    agetiaInfo->getC_dose = "";
    agetiaInfo->getC_expireDate = "";
    agetiaInfo->getC_judgeAttitude = "";
    agetiaInfo->getC_position = 0;
}

bool Dg_ExecCheck::NextTask()
{
    count++;

    if ( count < save_drawer.size())
    {
        waitTime(500);
        return true;
    }

    return false;
}

void Dg_ExecCheck::GetError()
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

void Dg_ExecCheck::WriteSQL_NetworkError()
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

void Dg_ExecCheck::Change_SQL_Table()
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
               .arg("在位").arg("").arg(save_needDel[j]));
        query->exec();
    }
    save_needDel.clear();
}

void Dg_ExecCheck::UploadTask2Server()
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
            QString dose = t_exec->data(t_exec->index(i, s_dose)).toString();

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
    TextMessageShowContent("", "请退出");
}

void Dg_ExecCheck::UploadWarning(QString json_str, QString warningContent, int model)
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

void Dg_ExecCheck::UploadDisableDrawerAndPosition()
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

void Dg_ExecCheck::TextMessageShowContent(QString colorType, QString content)
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
}

void Dg_ExecCheck::isSaveError(int goal)
{
    if (!save_previousErrorPosition.empty())
    {
        for (int i = 0; i < save_previousErrorPosition.size(); i++)
        {
            if (goal == save_previousErrorPosition[i])
            {
                save_warningInfo.append(goal);//预备上传内容
                break;
            }
        }
    }
}

void Dg_ExecCheck::SetInputReg()
{
    //正则表达
    QRegExp regx_bottleCapacity("[0-9]+$");//"[a-zA-Z0-9]+$" 长度7纯数字输入3.3格式
    QValidator *validator_bottleCapacity = new QRegExpValidator(regx_bottleCapacity,ui->lE_volum);
    ui->lE_volum->setValidator(validator_bottleCapacity);
}

void Dg_ExecCheck::ChangeStatus(QString content)
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

void Dg_ExecCheck::ChangeCellContent(int row, int column, QString content)
{
    t_exec->setData(t_exec->index(row, column), content);
    t_exec->submitAll();
}

void Dg_ExecCheck::ControlTimer(QString status)
{
    if (status == "open")
        emit ControlTimer_SerialPort(true);
    else if (status == "close")
        emit ControlTimer_SerialPort(false);
}

void Dg_ExecCheck::ClosePage()
{


    this->deleteLater();
}

void Dg_ExecCheck::HandleTask(int order)
{
    switch (order) {
    case haveErrorHandle:

        break;
    case haveNotExecTask:

        break;

    case havetaskOver:

        break;

    case haveErrorHandle_CLOSE:

        break;

    case haveNotExecTask_CLOSE:

        break;

    case havetaskOver_CLOSE:

        break;

    case PB_jump:

        break;

    case PB_return:

        break;

    default:
        break;
    }
}
