#include "cs_client.h"
#include "ui_cs_client.h"

CS_Client::CS_Client(QWidget *parent) :QWidget(parent),ui(new Ui::CS_Client)
{
    ui->setupUi(this);
    setWindowTitle("CS_Client V0.01");
}

CS_Client::~CS_Client(void)
{
    delete ui;
}
