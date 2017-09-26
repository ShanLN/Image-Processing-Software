/********************************************************************************
** Form generated from reading UI file 'ips.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPS_H
#define UI_IPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IPSClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IPSClass)
    {
        if (IPSClass->objectName().isEmpty())
            IPSClass->setObjectName(QStringLiteral("IPSClass"));
        IPSClass->resize(600, 400);
        menuBar = new QMenuBar(IPSClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        IPSClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IPSClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        IPSClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(IPSClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        IPSClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IPSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IPSClass->setStatusBar(statusBar);

        retranslateUi(IPSClass);

        QMetaObject::connectSlotsByName(IPSClass);
    } // setupUi

    void retranslateUi(QMainWindow *IPSClass)
    {
        IPSClass->setWindowTitle(QApplication::translate("IPSClass", "IPS", 0));
    } // retranslateUi

};

namespace Ui {
    class IPSClass: public Ui_IPSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPS_H
