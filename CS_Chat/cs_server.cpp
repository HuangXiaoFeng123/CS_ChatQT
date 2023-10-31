#include "cs_server.h"
#include "ui_cs_server.h"

CS_Server::CS_Server(QWidget *parent): QWidget(parent), ui(new Ui::CS_Server)
{
    ui->setupUi(this);
    setWindowTitle("CS_Server V0.02");
    server=NULL;
    socket=NULL;
    server=new QTcpServer(this);
    server->listen(QHostAddress::Any,8888);
    connect(server,&QTcpServer::newConnection,this,&CS_Server::getConnectInfoSlot);
}

CS_Server::~CS_Server(void)
{
    delete ui;
}

void CS_Server::getConnectInfoSlot(void)
{
    socket=server->nextPendingConnection();
    QString ip=socket->peerAddress().toString();
    quint16 port=socket->peerPort();
    QString temp=QString("[%1:%2连接成功]").arg(ip).arg(port);
    ui->textEditRead->setText(temp);
    connect(socket,&QTcpSocket::readyRead,this,&CS_Server::readInfoFromClientSlot);
}

void CS_Server::readInfoFromClientSlot(void)
{
    QByteArray array=socket->readAll();
    ui->textEditRead->append(array);
}

void CS_Server::on_ButtonSend_clicked(void)
{
    if(socket!=NULL)
    {
        QString str=ui->textEditWrite->toPlainText();
        socket->write(str.toUtf8().data());
    }
}

void CS_Server::closeEvent(QCloseEvent *)
{
    if(socket!=NULL)
    {
        socket->disconnectFromHost();
        socket->close();
        delete socket;
        socket=NULL;
    }
}
