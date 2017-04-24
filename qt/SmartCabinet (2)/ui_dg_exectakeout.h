/********************************************************************************
** Form generated from reading UI file 'dg_exectakeout.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_EXECTAKEOUT_H
#define UI_DG_EXECTAKEOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dg_ExecTakeOut
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCommandLinkButton *CB_return;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lB_title;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *TV_exec;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *textB_message;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pB_jump;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *Dg_ExecTakeOut)
    {
        if (Dg_ExecTakeOut->objectName().isEmpty())
            Dg_ExecTakeOut->setObjectName(QStringLiteral("Dg_ExecTakeOut"));
        Dg_ExecTakeOut->resize(984, 563);
        gridLayout_3 = new QGridLayout(Dg_ExecTakeOut);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        CB_return = new QCommandLinkButton(Dg_ExecTakeOut);
        CB_return->setObjectName(QStringLiteral("CB_return"));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(14);
        CB_return->setFont(font);

        horizontalLayout_2->addWidget(CB_return);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lB_title = new QLabel(Dg_ExecTakeOut);
        lB_title->setObjectName(QStringLiteral("lB_title"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(28);
        lB_title->setFont(font1);

        horizontalLayout_2->addWidget(lB_title);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox = new QGroupBox(Dg_ExecTakeOut);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(20);
        groupBox->setFont(font2);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TV_exec = new QTableView(groupBox);
        TV_exec->setObjectName(QStringLiteral("TV_exec"));

        gridLayout->addWidget(TV_exec, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(2, 2);

        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_2 = new QGroupBox(Dg_ExecTakeOut);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(12);
        groupBox_2->setFont(font3);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textB_message = new QTextBrowser(groupBox_2);
        textB_message->setObjectName(QStringLiteral("textB_message"));

        gridLayout_2->addWidget(textB_message, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        pB_jump = new QPushButton(Dg_ExecTakeOut);
        pB_jump->setObjectName(QStringLiteral("pB_jump"));
        pB_jump->setFont(font2);

        verticalLayout_2->addWidget(pB_jump);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 2);

        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(Dg_ExecTakeOut);

        QMetaObject::connectSlotsByName(Dg_ExecTakeOut);
    } // setupUi

    void retranslateUi(QDialog *Dg_ExecTakeOut)
    {
        Dg_ExecTakeOut->setWindowTitle(QApplication::translate("Dg_ExecTakeOut", "Dialog", Q_NULLPTR));
        CB_return->setText(QApplication::translate("Dg_ExecTakeOut", "\351\200\200\345\207\272", Q_NULLPTR));
        lB_title->setText(QApplication::translate("Dg_ExecTakeOut", "\345\217\226\346\223\215\344\275\234", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dg_ExecTakeOut", "\346\211\247\350\241\214\344\273\273\345\212\241\346\241\206", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Dg_ExecTakeOut", "\346\266\210\346\201\257\346\217\220\347\244\272\346\241\206", Q_NULLPTR));
        pB_jump->setText(QApplication::translate("Dg_ExecTakeOut", "\350\267\263\350\277\207", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dg_ExecTakeOut: public Ui_Dg_ExecTakeOut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_EXECTAKEOUT_H
