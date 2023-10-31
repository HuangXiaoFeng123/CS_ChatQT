/********************************************************************************
** Form generated from reading UI file 'cs_server.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CS_SERVER_H
#define UI_CS_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CS_Server
{
public:

    void setupUi(QWidget *CS_Server)
    {
        if (CS_Server->objectName().isEmpty())
            CS_Server->setObjectName(QString::fromUtf8("CS_Server"));
        CS_Server->resize(700, 520);

        retranslateUi(CS_Server);

        QMetaObject::connectSlotsByName(CS_Server);
    } // setupUi

    void retranslateUi(QWidget *CS_Server)
    {
        CS_Server->setWindowTitle(QApplication::translate("CS_Server", "CS_Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CS_Server: public Ui_CS_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CS_SERVER_H
