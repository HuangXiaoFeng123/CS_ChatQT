#include "cs_server.h"
#include "ui_cs_server.h"

CS_Server::CS_Server(QWidget *parent): QWidget(parent), ui(new Ui::CS_Server)
{
    ui->setupUi(this);
    setWindowTitle("CS_Server V0.03");
    setMinimumSize(700,520);
    setMaximumSize(700,520);
    server_s=NULL;
    socket_s=NULL;
    server_s=new QTcpServer(this);
    server_s->listen(QHostAddress::Any,8888);
    connect(server_s,&QTcpServer::newConnection,this,&CS_Server::getConnectInfoSlot);
}

CS_Server::~CS_Server(void)
{
    delete ui;
}

void CS_Server::getConnectInfoSlot(void)
{
    socket_s=server_s->nextPendingConnection();
    QString ip=socket_s->peerAddress().toString();
    quint16 port=socket_s->peerPort();
    QString temp=QString("[%1:%2连接成功]").arg(ip).arg(port);
    ui->textEditRead->setText(temp);
    connect(socket_s,&QTcpSocket::readyRead,this,&CS_Server::readInfoFromClientSlot);
}

void CS_Server::readInfoFromClientSlot(void)
{
    QByteArray array=socket_s->readAll();
    ui->textEditRead->append(array);
}

void CS_Server::on_ButtonSend_clicked(void)
{
    if(socket_s!=NULL)
    {
        QString str=ui->textEditWrite->toPlainText();
        socket_s->write(str.toUtf8().data());
    }
}

void CS_Server::closeEvent(QCloseEvent *)
{
    if(socket_s!=NULL)
    {
        socket_s->disconnectFromHost();
        socket_s->close();
        delete socket_s;
        socket_s=NULL;
    }
}
