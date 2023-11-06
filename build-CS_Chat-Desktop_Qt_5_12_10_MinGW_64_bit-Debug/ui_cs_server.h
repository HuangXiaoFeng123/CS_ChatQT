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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CS_Server
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditRead;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonFile;
    QPushButton *ButtonRecord;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEditWrite;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonSend;

    void setupUi(QWidget *CS_Server)
    {
        if (CS_Server->objectName().isEmpty())
            CS_Server->setObjectName(QString::fromUtf8("CS_Server"));
        CS_Server->resize(700, 520);
        gridLayout = new QGridLayout(CS_Server);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEditRead = new QTextEdit(CS_Server);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));

        verticalLayout->addWidget(textEditRead);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ButtonFile = new QPushButton(CS_Server);
        ButtonFile->setObjectName(QString::fromUtf8("ButtonFile"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonFile->sizePolicy().hasHeightForWidth());
        ButtonFile->setSizePolicy(sizePolicy);
        ButtonFile->setMinimumSize(QSize(30, 30));
        ButtonFile->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/send.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonFile->setIcon(icon);

        horizontalLayout->addWidget(ButtonFile);

        ButtonRecord = new QPushButton(CS_Server);
        ButtonRecord->setObjectName(QString::fromUtf8("ButtonRecord"));
        ButtonRecord->setMinimumSize(QSize(30, 30));
        ButtonRecord->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(ButtonRecord);

        horizontalSpacer = new QSpacerItem(538, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        textEditWrite = new QTextEdit(CS_Server);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));
        textEditWrite->setAutoFillBackground(false);

        verticalLayout->addWidget(textEditWrite);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(498, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ButtonSend = new QPushButton(CS_Server);
        ButtonSend->setObjectName(QString::fromUtf8("ButtonSend"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ButtonSend->sizePolicy().hasHeightForWidth());
        ButtonSend->setSizePolicy(sizePolicy1);
        ButtonSend->setMinimumSize(QSize(0, 30));
        ButtonSend->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(ButtonSend);

        horizontalLayout_2->setStretch(0, 8);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CS_Server);

        QMetaObject::connectSlotsByName(CS_Server);
    } // setupUi

    void retranslateUi(QWidget *CS_Server)
    {
        CS_Server->setWindowTitle(QApplication::translate("CS_Server", "CS_Server", nullptr));
        ButtonFile->setText(QString());
        ButtonRecord->setText(QString());
        ButtonSend->setText(QApplication::translate("CS_Server", "\345\217\221\351\200\201(S)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CS_Server: public Ui_CS_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CS_SERVER_H
