/********************************************************************************
** Form generated from reading UI file 'clientrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTRECORD_H
#define UI_CLIENTRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientRecord
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *ClientRecord)
    {
        if (ClientRecord->objectName().isEmpty())
            ClientRecord->setObjectName(QString::fromUtf8("ClientRecord"));
        ClientRecord->resize(458, 372);
        gridLayout = new QGridLayout(ClientRecord);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(ClientRecord);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(ClientRecord);

        QMetaObject::connectSlotsByName(ClientRecord);
    } // setupUi

    void retranslateUi(QWidget *ClientRecord)
    {
        ClientRecord->setWindowTitle(QApplication::translate("ClientRecord", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientRecord: public Ui_ClientRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTRECORD_H
