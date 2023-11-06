/********************************************************************************
** Form generated from reading UI file 'serverrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERRECORD_H
#define UI_SERVERRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerRecord
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *ServerRecord)
    {
        if (ServerRecord->objectName().isEmpty())
            ServerRecord->setObjectName(QString::fromUtf8("ServerRecord"));
        ServerRecord->resize(458, 372);
        gridLayout = new QGridLayout(ServerRecord);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(ServerRecord);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(ServerRecord);

        QMetaObject::connectSlotsByName(ServerRecord);
    } // setupUi

    void retranslateUi(QWidget *ServerRecord)
    {
        ServerRecord->setWindowTitle(QApplication::translate("ServerRecord", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerRecord: public Ui_ServerRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERRECORD_H
