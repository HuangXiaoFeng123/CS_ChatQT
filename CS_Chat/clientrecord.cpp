#include "clientrecord.h"
#include "ui_clientrecord.h"

ClientRecord::ClientRecord(QWidget *parent) :QWidget(parent),ui(new Ui::ClientRecord)
{
    ui->setupUi(this);
    fileread_client.setFileName("./ChatRecord_Client.txt");
    fileread_client.open(QIODevice::ReadOnly);
    QByteArray array=fileread_client.readAll();
    ui->textEdit->setText(array);
}

ClientRecord::~ClientRecord(void)
{
    delete ui;
}
