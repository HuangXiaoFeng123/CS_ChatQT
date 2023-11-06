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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CS_Client
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEditIP;
    QTextEdit *textEditRead;
    QPushButton *ButtonSend;
    QLabel *labelPort;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonConnect;
    QLineEdit *lineEditPort;
    QTextEdit *textEditWrite;
    QLabel *labelIP;
    QPushButton *ButtonFile;
    QPushButton *pushButton;

    void setupUi(QWidget *CS_Client)
    {
        if (CS_Client->objectName().isEmpty())
            CS_Client->setObjectName(QString::fromUtf8("CS_Client"));
        CS_Client->resize(700, 520);
        gridLayout = new QGridLayout(CS_Client);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditIP = new QLineEdit(CS_Client);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 3, 1, 1);

        textEditRead = new QTextEdit(CS_Client);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setReadOnly(true);

        gridLayout->addWidget(textEditRead, 2, 0, 1, 5);

        ButtonSend = new QPushButton(CS_Client);
        ButtonSend->setObjectName(QString::fromUtf8("ButtonSend"));
        ButtonSend->setMinimumSize(QSize(134, 30));
        ButtonSend->setMaximumSize(QSize(134, 30));

        gridLayout->addWidget(ButtonSend, 5, 4, 1, 1);

        labelPort = new QLabel(CS_Client);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        gridLayout->addWidget(labelPort, 1, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(643, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 3);

        horizontalSpacer = new QSpacerItem(539, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 4);

        ButtonConnect = new QPushButton(CS_Client);
        ButtonConnect->setObjectName(QString::fromUtf8("ButtonConnect"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonConnect->sizePolicy().hasHeightForWidth());
        ButtonConnect->setSizePolicy(sizePolicy);
        ButtonConnect->setMinimumSize(QSize(0, 30));
        ButtonConnect->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(ButtonConnect, 0, 4, 2, 1);

        lineEditPort = new QLineEdit(CS_Client);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 3, 1, 1);

        textEditWrite = new QTextEdit(CS_Client);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 4, 0, 1, 5);

        labelIP = new QLabel(CS_Client);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));

        gridLayout->addWidget(labelIP, 0, 0, 1, 3);

        ButtonFile = new QPushButton(CS_Client);
        ButtonFile->setObjectName(QString::fromUtf8("ButtonFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ButtonFile->sizePolicy().hasHeightForWidth());
        ButtonFile->setSizePolicy(sizePolicy1);
        ButtonFile->setMinimumSize(QSize(30, 30));
        ButtonFile->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/send.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonFile->setIcon(icon);

        gridLayout->addWidget(ButtonFile, 3, 0, 1, 1);

        pushButton = new QPushButton(CS_Client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);


        retranslateUi(CS_Client);

        QMetaObject::connectSlotsByName(CS_Client);
    } // setupUi

    void retranslateUi(QWidget *CS_Client)
    {
        CS_Client->setWindowTitle(QApplication::translate("CS_Client", "Form", nullptr));
        lineEditIP->setText(QApplication::translate("CS_Client", "127.0.0.1", nullptr));
        ButtonSend->setText(QApplication::translate("CS_Client", "\345\217\221\351\200\201(s)", nullptr));
        labelPort->setText(QApplication::translate("CS_Client", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        ButtonConnect->setText(QApplication::translate("CS_Client", "connect", nullptr));
        lineEditPort->setText(QApplication::translate("CS_Client", "8888", nullptr));
        labelIP->setText(QApplication::translate("CS_Client", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        ButtonFile->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CS_Client: public Ui_CS_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CS_CLIENT_H
