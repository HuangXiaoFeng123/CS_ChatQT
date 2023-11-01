#include "cs_client.h"
#include "ui_cs_client.h"

CS_Client::CS_Client(QWidget *parent) :QWidget(parent),ui(new Ui::CS_Client)
{
    ui->setupUi(this);
    setWindowTitle("CS_Client V0.04");
    setMinimumSize(700,520);
    setMaximumSize(700,520);
    socket_c=new QTcpSocket(this);
    connect(socket_c,&QTcpSocket::connected,this,&CS_Client::getConnectInfoSlot);
    connect(socket_c,&QTcpSocket::readyRead,this,&CS_Client::readInfoFromServerSlot);
}

CS_Client::~CS_Client(void)
{
    delete ui;
}

void CS_Client::on_ButtonConnect_clicked(void)
{
    QString ip=ui->lineEditIP->text();
    quint16 port=ui->lineEditPort->text().toInt();
    socket_c->connectToHost(QHostAddress(ip),port);
}

void CS_Client::getConnectInfoSlot(void)
{
    ui->textEditRead->setText("连接成功!");
}

void CS_Client::readInfoFromServerSlot(void)
{
    QByteArray array=socket_c->readAll();
    ui->textEditRead->append(array);
}

void CS_Client::on_ButtonSend_clicked(void)
{
    if(socket_c!=NULL)
    {
        QString str=ui->textEditWrite->toPlainText();
        socket_c->write(str.toUtf8().data());
    }
}

void CS_Client::closeEvent(QCloseEvent *)
{
    if(socket_c!=NULL)
    {
        socket_c->disconnectFromHost();
        socket_c->close();
    }
}

void CS_Client::paintEvent(QPaintEvent *)
{
    QPainter client_p(this);
    QPixmap client_map(":/Image/clientbackground.jpg");
    client_p.drawPixmap(0,0,this->width(),this->height(),client_map);
}
