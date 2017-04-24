/********************************************************************************
** Form generated from reading UI file 'dg_loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_LOGINPAGE_H
#define UI_DG_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dg_LoginPage
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lE_account;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lE_passwd;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pB_quit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pB_login;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *Dg_LoginPage)
    {
        if (Dg_LoginPage->objectName().isEmpty())
            Dg_LoginPage->setObjectName(QStringLiteral("Dg_LoginPage"));
        Dg_LoginPage->resize(1142, 633);
        gridLayout = new QGridLayout(Dg_LoginPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(Dg_LoginPage);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(26);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Dg_LoginPage);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lE_account = new QLineEdit(Dg_LoginPage);
        lE_account->setObjectName(QStringLiteral("lE_account"));
        lE_account->setMinimumSize(QSize(200, 50));
        lE_account->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(lE_account);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(Dg_LoginPage);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lE_passwd = new QLineEdit(Dg_LoginPage);
        lE_passwd->setObjectName(QStringLiteral("lE_passwd"));
        lE_passwd->setMinimumSize(QSize(200, 50));
        lE_passwd->setEchoMode(QLineEdit::Password);
        lE_passwd->setClearButtonEnabled(true);

        horizontalLayout_3->addWidget(lE_passwd);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pB_quit = new QPushButton(Dg_LoginPage);
        pB_quit->setObjectName(QStringLiteral("pB_quit"));
        pB_quit->setMinimumSize(QSize(100, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(14);
        pB_quit->setFont(font1);

        horizontalLayout_4->addWidget(pB_quit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pB_login = new QPushButton(Dg_LoginPage);
        pB_login->setObjectName(QStringLiteral("pB_login"));
        pB_login->setMinimumSize(QSize(100, 50));
        pB_login->setFont(font1);

        horizontalLayout_4->addWidget(pB_login);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(Dg_LoginPage);

        QMetaObject::connectSlotsByName(Dg_LoginPage);
    } // setupUi

    void retranslateUi(QDialog *Dg_LoginPage)
    {
        Dg_LoginPage->setWindowTitle(QApplication::translate("Dg_LoginPage", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dg_LoginPage", "\346\231\272\350\203\275\350\257\225\345\211\202\346\237\234", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dg_LoginPage", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        lE_account->setText(QApplication::translate("Dg_LoginPage", "admin", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dg_LoginPage", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lE_passwd->setText(QApplication::translate("Dg_LoginPage", "123456", Q_NULLPTR));
        pB_quit->setText(QApplication::translate("Dg_LoginPage", "\351\200\200\345\207\272", Q_NULLPTR));
        pB_login->setText(QApplication::translate("Dg_LoginPage", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dg_LoginPage: public Ui_Dg_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_LOGINPAGE_H
