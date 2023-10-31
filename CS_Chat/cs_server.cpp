#include "cs_server.h"
#include "ui_cs_server.h"

CS_Server::CS_Server(QWidget *parent): QWidget(parent), ui(new Ui::CS_Server)
{
    ui->setupUi(this);
    setWindowTitle("CS_Server V0.01");
}

CS_Server::~CS_Server(void)
{
    delete ui;
}

