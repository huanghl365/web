/********************************************************************************
** Form generated from reading UI file 'httpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HTTPWINDOW_H
#define UI_HTTPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HttpWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *HttpWindow)
    {
        if (HttpWindow->objectName().isEmpty())
            HttpWindow->setObjectName(QStringLiteral("HttpWindow"));
        HttpWindow->resize(689, 409);
        centralWidget = new QWidget(HttpWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        HttpWindow->setCentralWidget(centralWidget);

        retranslateUi(HttpWindow);

        QMetaObject::connectSlotsByName(HttpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HttpWindow)
    {
        HttpWindow->setWindowTitle(QApplication::translate("HttpWindow", "HttpWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HttpWindow: public Ui_HttpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HTTPWINDOW_H
