#ifndef DG_FUNCTIONOPTPAGE_H
#define DG_FUNCTIONOPTPAGE_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class Dg_FunctionOptPage;
}

class Dg_FunctionOptPage : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_FunctionOptPage(QWidget *parent = 0);
    ~Dg_FunctionOptPage();

private slots:
    void on_pB_quit_clicked();
    void Auto_freshen();
    void on_pB_takeOut_clicked();

    void on_pB_return_clicked();
    void ShowFunctionPage();

    void on_pB_check_clicked();

    void on_pB_takeIn_clicked();

    void on_pB_remove_clicked();

    void on_pB_scrap_clicked();

    void on_pB_replace_clicked();

signals:
    void KillProgram();

private:
    Ui::Dg_FunctionOptPage *ui;
    QTimer *timer;
    void UpGUI(int order);
    void ClosePage();
    void mousePressEvent(QMouseEvent *event);
    void waitTime(int time);
};

#endif // DG_FUNCTIONOPTPAGE_H
