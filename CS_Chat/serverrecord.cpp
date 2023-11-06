#include "serverrecord.h"
#include "ui_serverrecord.h"

ServerRecord::ServerRecord(QWidget *parent) :QWidget(parent),ui(new Ui::ServerRecord)
{
    ui->setupUi(this);
    fileread_server.setFileName("./ChatRecord_Server.txt");
    fileread_server.open(QIODevice::ReadOnly);
    QByteArray array=fileread_server.readAll();
    ui->textEdit->setText(array);
}

ServerRecord::~ServerRecord(void)
{
    delete ui;
}
