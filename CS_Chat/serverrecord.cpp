#include "serverrecord.h"
#include "ui_serverrecord.h"

ServerRecord::ServerRecord(QWidget *parent) :QWidget(parent),ui(new Ui::ServerRecord)
{
    ui->setupUi(this);
    setWindowTitle("Server Record");
}

ServerRecord::~ServerRecord(void)
{
    delete ui;
}

void ServerRecord::ServerRecord_File(void)
{
    fileread_server.setFileName("./ChatRecord_Server.txt");
    fileread_server.open(QIODevice::ReadOnly);
    QByteArray array=fileread_server.readAll();
    ui->textEdit->setText(array);
    fileread_server.close();
}
