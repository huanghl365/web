/********************************************************************************
** Form generated from reading UI file 'dg_execcheck.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_EXECCHECK_H
#define UI_DG_EXECCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dg_ExecCheck
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
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lB_volum;
    QLineEdit *lE_volum;
    QComboBox *CB_unit;
    QPushButton *pB_sure;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *textB_message;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pB_jump;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *Dg_ExecCheck)
    {
        if (Dg_ExecCheck->objectName().isEmpty())
            Dg_ExecCheck->setObjectName(QStringLiteral("Dg_ExecCheck"));
        Dg_ExecCheck->resize(744, 462);
        gridLayout_3 = new QGridLayout(Dg_ExecCheck);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        CB_return = new QCommandLinkButton(Dg_ExecCheck);
        CB_return->setObjectName(QStringLiteral("CB_return"));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(14);
        CB_return->setFont(font);

        horizontalLayout_2->addWidget(CB_return);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lB_title = new QLabel(Dg_ExecCheck);
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

        groupBox = new QGroupBox(Dg_ExecCheck);
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

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lB_volum = new QLabel(Dg_ExecCheck);
        lB_volum->setObjectName(QStringLiteral("lB_volum"));
        lB_volum->setFont(font2);

        horizontalLayout->addWidget(lB_volum);

        lE_volum = new QLineEdit(Dg_ExecCheck);
        lE_volum->setObjectName(QStringLiteral("lE_volum"));
        lE_volum->setFont(font2);

        horizontalLayout->addWidget(lE_volum);

        CB_unit = new QComboBox(Dg_ExecCheck);
        CB_unit->setObjectName(QStringLiteral("CB_unit"));
        CB_unit->setFont(font2);

        horizontalLayout->addWidget(CB_unit);

        pB_sure = new QPushButton(Dg_ExecCheck);
        pB_sure->setObjectName(QStringLiteral("pB_sure"));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(18);
        pB_sure->setFont(font3);

        horizontalLayout->addWidget(pB_sure);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(2, 2);

        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_2 = new QGroupBox(Dg_ExecCheck);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font4;
        font4.setFamily(QStringLiteral("Agency FB"));
        font4.setPointSize(12);
        groupBox_2->setFont(font4);
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

        pB_jump = new QPushButton(Dg_ExecCheck);
        pB_jump->setObjectName(QStringLiteral("pB_jump"));
        pB_jump->setFont(font2);

        verticalLayout_2->addWidget(pB_jump);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(Dg_ExecCheck);

        QMetaObject::connectSlotsByName(Dg_ExecCheck);
    } // setupUi

    void retranslateUi(QDialog *Dg_ExecCheck)
    {
        Dg_ExecCheck->setWindowTitle(QApplication::translate("Dg_ExecCheck", "Dialog", Q_NULLPTR));
        CB_return->setText(QApplication::translate("Dg_ExecCheck", "\351\200\200\345\207\272", Q_NULLPTR));
        lB_title->setText(QApplication::translate("Dg_ExecCheck", "\345\275\222\350\277\230\346\223\215\344\275\234", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dg_ExecCheck", "\346\211\247\350\241\214\344\273\273\345\212\241\346\241\206", Q_NULLPTR));
        lB_volum->setText(QApplication::translate("Dg_ExecCheck", "\345\211\251\344\275\231\345\256\271\347\247\257\357\274\232", Q_NULLPTR));
        CB_unit->clear();
        CB_unit->insertItems(0, QStringList()
         << QApplication::translate("Dg_ExecCheck", "ml", Q_NULLPTR)
         << QApplication::translate("Dg_ExecCheck", "g", Q_NULLPTR)
        );
        pB_sure->setText(QApplication::translate("Dg_ExecCheck", "\345\206\231\345\205\245", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Dg_ExecCheck", "\346\266\210\346\201\257\346\217\220\347\244\272\346\241\206", Q_NULLPTR));
        pB_jump->setText(QApplication::translate("Dg_ExecCheck", "\350\267\263\350\277\207", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dg_ExecCheck: public Ui_Dg_ExecCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_EXECCHECK_H
