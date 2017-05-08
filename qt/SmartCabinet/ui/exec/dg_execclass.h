#ifndef DG_EXECCLASS_H
#define DG_EXECCLASS_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "network/netcommunication.h"

namespace Ui {
class Dg_ExecClass;
}

class Dg_ExecClass : public QWidget
{
    Q_OBJECT

public:
    explicit Dg_ExecClass(QWidget *parent = 0);
    ~Dg_ExecClass();

signals:
    void ControlTimer_SerialPort(bool _switch);
    void TaskCommand_Send2MCU(int DID, int send_ActNum);
    void Request_Lock(int drawer_ID);

private slots:
    void on_pB_sure_clicked();

    void on_CB_return_clicked();

    void on_pB_jump_clicked();

protected:
    QString tableName;// set SqlTable Name
    QString modelOptional;//have two model optional : "Mul" and "Single"

    //定义对应列表列数
    int s_drawerColumn;
    int s_positioinColumn;
    int s_judgeStatusColumn;
    int s_nameColumn;
    int s_agetiaIdColumn;
    int s_positionIdColumn;
    int s_orderColumn;
    int s_doseColumn;
    int s_agetiaTypeIdColumn;


    //设置标题
    void SetTitle(QString name);
    //程序总控
    void All_Control();
    void IsChangeInfo(QString model);
    //各个任务不同上报格式
    void TakeOut();
    void New_TakeIn();
    void Back_TakeIn();
    //显示格式
    void Show_TakeIn();
    void Show_TakeOut();
    void Show_BackTakeOut();
private:
    Ui::Dg_ExecClass *ui;
    QSqlTableModel *t_exec;
    QSqlQuery *query;
    NetCommunication *netCommunication;
    int count;

    bool isContinueExecute;
    bool isPBjump;


    enum{NetworkTask, Drawer_error, haveErrorHandle, haveNotExecTask, havetaskOver, PB_jump, PB_return,\
        haveErrorHandle_CLOSE, haveNotExecTask_CLOSE, havetaskOver_CLOSE,};

    QList <QString> save_needDel;
    QMap <int, int> save_position;
    QMap <int, int> save_number;
    QMap <int, int> save_previousErrorPosition;
    QMap <int, int> save_outstripTimer;
    QList <int> save_warningInfo;
    QList <int> save_drawer;

    struct Save_AgentiaInfo{
        int getC_agentiaId;
        int getC_position;
        QString getC_dose;
        QString getC_bottleCapacity;
        QString getC_expireDate;
        QString getC_judgeAttitude;
    };
    Save_AgentiaInfo *agetiaInfo;

    //检查数据库有无数据
    bool CheckTable_haveData(QString tableName);
    //检查锁状态
    bool CheckLock_isOpen();
    void Initiative_CheckLock();
    //检测是否是同一柜子
    bool Is_DrawerNo_Equal();
    //指令发送结果
    bool CheckTask_isSendSuccess();
    //任务状况
    int CheckDrawerTaskStatus();
    //显示界面，排序
    virtual void ShowPage();
    //上报任务信息
    virtual void UploadTask2Server();

    //显示任务信息
    void ShowCurrentAgentiaInfo(int i);
    //获取位置号
    void GetDrawerAndPosition_Singletaske();
    //mul get
    void GetPositionNum();
    void GetDrawer();
    //获取抽屉信息方式控制
    void Control_GetDrawerInfo(QString model);
    //任务下发
    void Send_TaskInfo2MCU_Single();
    void Send_TaskInfo2MCU_Mul();
    void Send_TaskCommandModelOptional(QString model);
    //等待
    void waitTime(int time);
    //下一条任务
    bool NextTask();
    //解析json
    bool UnpackageJson_Task(QJsonDocument str);
    //修改单元格内容
    void ChangeCellContent(int row, int column, QString content);
    void ChangeStatus_SingleTask(QString content);
    void ChangeStatus_MulTask(QString content);
    //设置提示框内容
    void TextMessageShowContent(QString colorType, QString content);
    //等待当前锁关闭
    void RequestLockStatus_Current();
    //存储数据库
    void WriteSQL_NetworkError();
    //读取异常信息
    void GetError();
    //初始化结构体
    void InitializeStruct();
    //上报任务信息
    void UploadWarning(QString json_str, QString warningContent, int model);
    void UploadDisableDrawerAndPosition();
    //离线本地修改状态
    void Change_SQL_Table(QString name);//"在位"  "借出"
    //检测错误是否存在
    void isSaveError(int goal);
    //设置输入格式
    void SetInputReg();
    //关闭界面
    void ClosePage();
    //控制定时器
    void ControlTimer(QString status);
    //处理任务状态
    void HandleTask(int order);
    //初始化标志位
    void FlagInit();
    //显示反馈
    void Scan_ShowMCUReply(int &status);
    //执行任务
    void Exec_Task(int &status);



};

#endif // DG_EXECCLASS_H
