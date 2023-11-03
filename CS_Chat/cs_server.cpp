#include "cs_server.h"
#include "ui_cs_server.h"

CS_Server::CS_Server(QWidget *parent): QWidget(parent), ui(new Ui::CS_Server)
{
    ui->setupUi(this);
    setWindowTitle("CS_Server V0.07");
    setMinimumSize(700,520);
    setMaximumSize(700,520);
    server_s=NULL;
    socket_s=NULL;
    server_s=new QTcpServer(this);
    server_s->listen(QHostAddress::Any,8888);
    connect(server_s,&QTcpServer::newConnection,this,&CS_Server::getConnectInfoSlot);
    connect(&delaytimer_s,&QTimer::timeout,this,&CS_Server::sendMessageSlot);
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
    QByteArray buff=socket_s->readAll();
    filename_s=QString(buff).section("##",0,0);
    filesize_s=QString(buff).section("##",1,1).toInt();
    if((!filename_s.isEmpty())&&(filesize_s!=0))
    {
        start_sendfile=true;
        is_start=true;
        filesize_temp=filesize_s;
    }
    if(start_sendfile==false)
    {
        ui->textEditRead->append(buff);
    }
    else
    {
        if(is_start==true)
        {
            is_start=false;
            file_s.setFileName(filename_s);
            recvsize_s=0;
            file_s.open(QIODevice::WriteOnly);
        }
        else
        {
            qint64 len=file_s.write(buff);
            if(len>0)
            {
                recvsize_s+=len;
            }
            if(recvsize_s==filesize_temp)
            {
                start_sendfile=false;
                file_s.close();
                socket_s->disconnectFromHost();
                socket_s->close();
            }
        }
    }

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

void CS_Server::paintEvent(QPaintEvent *)
{
    QPainter server_p(this);
    QPixmap server_map(":/Image/serverbackground.jpg");
    server_p.drawPixmap(0,0,this->width(),this->height(),server_map);
}
//服务器--->客户端
//服务器 先把file读出到buff 然后在把buff写到socket
//客户端 先把socket读出到buff 然后在把buff写到file
void CS_Server::on_ButtonFile_clicked(void)
{
    QString path=QFileDialog::getOpenFileName(this,"open","../");
    if(path.isEmpty()==false)
    {
        filename_s="";
        filesize_s=0;
        sendsize_s=0;
        QFileInfo info(path);
        filename_s=info.fileName();
        filesize_s=info.size();
        file_s.setFileName(path);
        bool readfile_OK=file_s.open(QIODevice::ReadOnly);
        if(readfile_OK==true)
        {
            int ret=QMessageBox::question(this,"发送","确定要发送?",QMessageBox::Yes,QMessageBox::No);
            if(ret==QMessageBox::Yes)
            {
                QString head=QString("%1##%2").arg(filename_s).arg(filesize_s);     //组报文头
                qint64 len=socket_s->write(head.toUtf8());
                if(len>0)
                {
                    delaytimer_s.start(20);  //延时20ms
                }
                else                       //写失败
                {
                    file_s.close();
                }
            }
            else
            {
                path="";
            }
        }
    }
}

void CS_Server::sendMessageSlot(void)
{
    delaytimer_s.stop();                     //定时器停止开始传输正文内容
    qint64 len=0;
    do
    {
        char buff[4*1024]={0};
        len=file_s.read(buff,sizeof(buff));
        socket_s->write(buff,len);
        sendsize_s+=len;
    }while(len>0);
    if(sendsize_s==filesize_s)
    {
        file_s.close();
        socket_s->disconnectFromHost();
        socket_s->close();
    }
}
