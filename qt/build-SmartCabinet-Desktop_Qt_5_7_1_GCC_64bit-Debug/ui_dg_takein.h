/********************************************************************************
** Form generated from reading UI file 'dg_takein.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_TAKEIN_H
#define UI_DG_TAKEIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dg_TakeIn
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QCommandLinkButton *CB_return;
    QSpacerItem *horizontalSpacer;
    QLabel *LB_title;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *TW_Exec;
    QVBoxLayout *verticalLayout;
    QPushButton *pB_exec;
    QSpacerItem *verticalSpacer;
    QPushButton *pB_delete;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *LE_search;
    QPushButton *pB_search;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *TW_Sea;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pB_apply;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Dg_TakeIn)
    {
        if (Dg_TakeIn->objectName().isEmpty())
            Dg_TakeIn->setObjectName(QStringLiteral("Dg_TakeIn"));
        Dg_TakeIn->resize(706, 460);
        gridLayout_3 = new QGridLayout(Dg_TakeIn);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        CB_return = new QCommandLinkButton(Dg_TakeIn);
        CB_return->setObjectName(QStringLiteral("CB_return"));
        CB_return->setMinimumSize(QSize(10, 40));
        CB_return->setMaximumSize(QSize(100, 40));

        gridLayout_2->addWidget(CB_return, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        LB_title = new QLabel(Dg_TakeIn);
        LB_title->setObjectName(QStringLiteral("LB_title"));

        gridLayout_2->addWidget(LB_title, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        TW_Exec = new QTableWidget(Dg_TakeIn);
        TW_Exec->setObjectName(QStringLiteral("TW_Exec"));

        horizontalLayout_3->addWidget(TW_Exec);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pB_exec = new QPushButton(Dg_TakeIn);
        pB_exec->setObjectName(QStringLiteral("pB_exec"));

        verticalLayout->addWidget(pB_exec);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pB_delete = new QPushButton(Dg_TakeIn);
        pB_delete->setObjectName(QStringLiteral("pB_delete"));

        verticalLayout->addWidget(pB_delete);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LE_search = new QLineEdit(Dg_TakeIn);
        LE_search->setObjectName(QStringLiteral("LE_search"));
        LE_search->setMinimumSize(QSize(150, 40));

        horizontalLayout_2->addWidget(LE_search);

        pB_search = new QPushButton(Dg_TakeIn);
        pB_search->setObjectName(QStringLiteral("pB_search"));
        pB_search->setMinimumSize(QSize(0, 40));

        horizontalLayout_2->addWidget(pB_search);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        TW_Sea = new QTableWidget(Dg_TakeIn);
        TW_Sea->setObjectName(QStringLiteral("TW_Sea"));

        horizontalLayout_4->addWidget(TW_Sea);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pB_apply = new QPushButton(Dg_TakeIn);
        pB_apply->setObjectName(QStringLiteral("pB_apply"));

        verticalLayout_2->addWidget(pB_apply);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Dg_TakeIn);

        QMetaObject::connectSlotsByName(Dg_TakeIn);
    } // setupUi

    void retranslateUi(QDialog *Dg_TakeIn)
    {
        Dg_TakeIn->setWindowTitle(QApplication::translate("Dg_TakeIn", "Dialog", Q_NULLPTR));
        CB_return->setText(QApplication::translate("Dg_TakeIn", "\350\277\224\345\233\236", Q_NULLPTR));
        LB_title->setText(QApplication::translate("Dg_TakeIn", "TextLabel", Q_NULLPTR));
        pB_exec->setText(QApplication::translate("Dg_TakeIn", "\346\211\247\350\241\214", Q_NULLPTR));
        pB_delete->setText(QApplication::translate("Dg_TakeIn", "\345\210\240\351\231\244", Q_NULLPTR));
        pB_search->setText(QApplication::translate("Dg_TakeIn", "\346\243\200\347\264\242", Q_NULLPTR));
        pB_apply->setText(QApplication::translate("Dg_TakeIn", "\347\224\263\350\257\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dg_TakeIn: public Ui_Dg_TakeIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_TAKEIN_H
