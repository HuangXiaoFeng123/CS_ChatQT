/********************************************************************************
** Form generated from reading UI file 'cs_client.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CS_CLIENT_H
#define UI_CS_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CS_Client
{
public:

    void setupUi(QWidget *CS_Client)
    {
        if (CS_Client->objectName().isEmpty())
            CS_Client->setObjectName(QString::fromUtf8("CS_Client"));
        CS_Client->resize(700, 520);

        retranslateUi(CS_Client);

        QMetaObject::connectSlotsByName(CS_Client);
    } // setupUi

    void retranslateUi(QWidget *CS_Client)
    {
        CS_Client->setWindowTitle(QApplication::translate("CS_Client", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CS_Client: public Ui_CS_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CS_CLIENT_H
