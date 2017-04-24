/********************************************************************************
** Form generated from reading UI file 'dg_functionoptpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_FUNCTIONOPTPAGE_H
#define UI_DG_FUNCTIONOPTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dg_FunctionOptPage
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_userName;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pB_takeOut;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pB_return;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pB_scrap;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pB_takeIn;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pB_remove;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pB_replace;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pB_check;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pB_quit;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_8;

    void setupUi(QDialog *Dg_FunctionOptPage)
    {
        if (Dg_FunctionOptPage->objectName().isEmpty())
            Dg_FunctionOptPage->setObjectName(QStringLiteral("Dg_FunctionOptPage"));
        Dg_FunctionOptPage->resize(674, 410);
        gridLayout = new QGridLayout(Dg_FunctionOptPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(Dg_FunctionOptPage);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(24);
        label->setFont(font);

        horizontalLayout_5->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        label_userName = new QLabel(Dg_FunctionOptPage);
        label_userName->setObjectName(QStringLiteral("label_userName"));

        horizontalLayout_5->addWidget(label_userName);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pB_takeOut = new QPushButton(Dg_FunctionOptPage);
        pB_takeOut->setObjectName(QStringLiteral("pB_takeOut"));

        horizontalLayout->addWidget(pB_takeOut);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        pB_return = new QPushButton(Dg_FunctionOptPage);
        pB_return->setObjectName(QStringLiteral("pB_return"));

        horizontalLayout->addWidget(pB_return);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        pB_scrap = new QPushButton(Dg_FunctionOptPage);
        pB_scrap->setObjectName(QStringLiteral("pB_scrap"));

        horizontalLayout->addWidget(pB_scrap);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        pB_takeIn = new QPushButton(Dg_FunctionOptPage);
        pB_takeIn->setObjectName(QStringLiteral("pB_takeIn"));

        horizontalLayout_2->addWidget(pB_takeIn);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        pB_remove = new QPushButton(Dg_FunctionOptPage);
        pB_remove->setObjectName(QStringLiteral("pB_remove"));

        horizontalLayout_2->addWidget(pB_remove);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        pB_replace = new QPushButton(Dg_FunctionOptPage);
        pB_replace->setObjectName(QStringLiteral("pB_replace"));

        horizontalLayout_2->addWidget(pB_replace);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pB_check = new QPushButton(Dg_FunctionOptPage);
        pB_check->setObjectName(QStringLiteral("pB_check"));

        horizontalLayout_3->addWidget(pB_check);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pB_quit = new QPushButton(Dg_FunctionOptPage);
        pB_quit->setObjectName(QStringLiteral("pB_quit"));

        horizontalLayout_4->addWidget(pB_quit);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_8 = new QPushButton(Dg_FunctionOptPage);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout_4->addWidget(pushButton_8);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Dg_FunctionOptPage);

        QMetaObject::connectSlotsByName(Dg_FunctionOptPage);
    } // setupUi

    void retranslateUi(QDialog *Dg_FunctionOptPage)
    {
        Dg_FunctionOptPage->setWindowTitle(QApplication::translate("Dg_FunctionOptPage", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dg_FunctionOptPage", "\346\231\272\350\203\275\350\257\225\345\211\202\346\237\234", Q_NULLPTR));
        label_userName->setText(QString());
        pB_takeOut->setText(QApplication::translate("Dg_FunctionOptPage", "\345\217\226", Q_NULLPTR));
        pB_return->setText(QApplication::translate("Dg_FunctionOptPage", "\350\277\230", Q_NULLPTR));
        pB_scrap->setText(QApplication::translate("Dg_FunctionOptPage", "\346\212\245\345\272\237", Q_NULLPTR));
        pB_takeIn->setText(QApplication::translate("Dg_FunctionOptPage", "\345\205\245\346\237\234", Q_NULLPTR));
        pB_remove->setText(QApplication::translate("Dg_FunctionOptPage", "\347\247\273\345\207\272", Q_NULLPTR));
        pB_replace->setText(QApplication::translate("Dg_FunctionOptPage", "\346\233\277\346\215\242", Q_NULLPTR));
        pB_check->setText(QApplication::translate("Dg_FunctionOptPage", "\347\202\271\351\252\214", Q_NULLPTR));
        pB_quit->setText(QApplication::translate("Dg_FunctionOptPage", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Dg_FunctionOptPage", "\345\205\254\345\221\212\346\240\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dg_FunctionOptPage: public Ui_Dg_FunctionOptPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_FUNCTIONOPTPAGE_H
