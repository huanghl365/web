/********************************************************************************
** Form generated from reading UI file 'dg_requestposition.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_REQUESTPOSITION_H
#define UI_DG_REQUESTPOSITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dg_RequestPosition
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextBrowser *TB_info;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cB_drawer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lE_bottle;
    QComboBox *cB_bottle;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lE_dose;
    QComboBox *cB_dose;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pB_apply;
    QSpacerItem *verticalSpacer_10;
    QPushButton *pB_back;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Dg_RequestPosition)
    {
        if (Dg_RequestPosition->objectName().isEmpty())
            Dg_RequestPosition->setObjectName(QStringLiteral("Dg_RequestPosition"));
        Dg_RequestPosition->resize(938, 555);
        Dg_RequestPosition->setMinimumSize(QSize(100, 40));
        gridLayout_2 = new QGridLayout(Dg_RequestPosition);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(Dg_RequestPosition);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TB_info = new QTextBrowser(groupBox);
        TB_info->setObjectName(QStringLiteral("TB_info"));

        gridLayout->addWidget(TB_info, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_9);


        horizontalLayout_6->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dg_RequestPosition);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        cB_drawer = new QComboBox(Dg_RequestPosition);
        cB_drawer->setObjectName(QStringLiteral("cB_drawer"));
        cB_drawer->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(14);
        cB_drawer->setFont(font1);

        horizontalLayout->addWidget(cB_drawer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Dg_RequestPosition);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dateEdit = new QDateEdit(Dg_RequestPosition);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMinimumSize(QSize(250, 40));

        horizontalLayout_2->addWidget(dateEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(Dg_RequestPosition);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lE_bottle = new QLineEdit(Dg_RequestPosition);
        lE_bottle->setObjectName(QStringLiteral("lE_bottle"));
        lE_bottle->setMinimumSize(QSize(0, 40));

        horizontalLayout_3->addWidget(lE_bottle);

        cB_bottle = new QComboBox(Dg_RequestPosition);
        cB_bottle->setObjectName(QStringLiteral("cB_bottle"));
        cB_bottle->setMinimumSize(QSize(0, 40));

        horizontalLayout_3->addWidget(cB_bottle);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(Dg_RequestPosition);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lE_dose = new QLineEdit(Dg_RequestPosition);
        lE_dose->setObjectName(QStringLiteral("lE_dose"));
        lE_dose->setMinimumSize(QSize(0, 40));

        horizontalLayout_4->addWidget(lE_dose);

        cB_dose = new QComboBox(Dg_RequestPosition);
        cB_dose->setObjectName(QStringLiteral("cB_dose"));
        cB_dose->setMinimumSize(QSize(0, 40));

        horizontalLayout_4->addWidget(cB_dose);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pB_apply = new QPushButton(Dg_RequestPosition);
        pB_apply->setObjectName(QStringLiteral("pB_apply"));
        pB_apply->setMinimumSize(QSize(100, 40));

        verticalLayout->addWidget(pB_apply);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        pB_back = new QPushButton(Dg_RequestPosition);
        pB_back->setObjectName(QStringLiteral("pB_back"));
        pB_back->setMinimumSize(QSize(100, 40));

        verticalLayout->addWidget(pB_back);

        verticalLayout->setStretch(0, 1);

        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_8);

        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_6->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        retranslateUi(Dg_RequestPosition);

        QMetaObject::connectSlotsByName(Dg_RequestPosition);
    } // setupUi

    void retranslateUi(QDialog *Dg_RequestPosition)
    {
        Dg_RequestPosition->setWindowTitle(QApplication::translate("Dg_RequestPosition", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dg_RequestPosition", "\350\215\257\345\211\202\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("Dg_RequestPosition", "\346\212\275\345\261\211\345\217\267\357\274\232", Q_NULLPTR));
        cB_drawer->clear();
        cB_drawer->insertItems(0, QStringList()
         << QApplication::translate("Dg_RequestPosition", "1", Q_NULLPTR)
         << QApplication::translate("Dg_RequestPosition", "2", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Dg_RequestPosition", "\345\244\261\346\225\210\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dg_RequestPosition", "\351\242\235\345\256\232\345\256\271\347\247\257\357\274\232", Q_NULLPTR));
        cB_bottle->clear();
        cB_bottle->insertItems(0, QStringList()
         << QApplication::translate("Dg_RequestPosition", "ml", Q_NULLPTR)
         << QApplication::translate("Dg_RequestPosition", "g", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Dg_RequestPosition", "\345\256\236\351\231\205\345\256\271\347\247\257\357\274\232", Q_NULLPTR));
        cB_dose->clear();
        cB_dose->insertItems(0, QStringList()
         << QApplication::translate("Dg_RequestPosition", "ml", Q_NULLPTR)
         << QApplication::translate("Dg_RequestPosition", "g", Q_NULLPTR)
        );
        pB_apply->setText(QApplication::translate("Dg_RequestPosition", "\347\224\263\350\257\267", Q_NULLPTR));
        pB_back->setText(QApplication::translate("Dg_RequestPosition", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dg_RequestPosition: public Ui_Dg_RequestPosition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_REQUESTPOSITION_H
