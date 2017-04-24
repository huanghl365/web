/********************************************************************************
** Form generated from reading UI file 'dg_returnpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_RETURNPAGE_H
#define UI_DG_RETURNPAGE_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dg_ReturnPage
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCommandLinkButton *CB_return;
    QSpacerItem *horizontalSpacer;
    QLabel *LB_title;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *TW_Exec;
    QVBoxLayout *verticalLayout;
    QPushButton *pB_Exec;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Dg_ReturnPage)
    {
        if (Dg_ReturnPage->objectName().isEmpty())
            Dg_ReturnPage->setObjectName(QStringLiteral("Dg_ReturnPage"));
        Dg_ReturnPage->resize(998, 592);
        gridLayout = new QGridLayout(Dg_ReturnPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CB_return = new QCommandLinkButton(Dg_ReturnPage);
        CB_return->setObjectName(QStringLiteral("CB_return"));
        CB_return->setMinimumSize(QSize(50, 40));
        CB_return->setMaximumSize(QSize(100, 40));

        horizontalLayout->addWidget(CB_return);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        LB_title = new QLabel(Dg_ReturnPage);
        LB_title->setObjectName(QStringLiteral("LB_title"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(14);
        LB_title->setFont(font);

        horizontalLayout->addWidget(LB_title);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(3, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        TW_Exec = new QTableWidget(Dg_ReturnPage);
        TW_Exec->setObjectName(QStringLiteral("TW_Exec"));

        horizontalLayout_2->addWidget(TW_Exec);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pB_Exec = new QPushButton(Dg_ReturnPage);
        pB_Exec->setObjectName(QStringLiteral("pB_Exec"));
        pB_Exec->setFont(font);

        verticalLayout->addWidget(pB_Exec);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Dg_ReturnPage);

        QMetaObject::connectSlotsByName(Dg_ReturnPage);
    } // setupUi

    void retranslateUi(QDialog *Dg_ReturnPage)
    {
        Dg_ReturnPage->setWindowTitle(QApplication::translate("Dg_ReturnPage", "Dialog", Q_NULLPTR));
        CB_return->setText(QApplication::translate("Dg_ReturnPage", "\350\277\224\345\233\236", Q_NULLPTR));
        LB_title->setText(QApplication::translate("Dg_ReturnPage", "\345\275\222\350\277\230\346\223\215\344\275\234", Q_NULLPTR));
        pB_Exec->setText(QApplication::translate("Dg_ReturnPage", "\346\211\247\350\241\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dg_ReturnPage: public Ui_Dg_ReturnPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_RETURNPAGE_H
