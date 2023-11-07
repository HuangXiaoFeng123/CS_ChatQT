#include "cs_server.h"
#include "ui_cs_server.h"

CS_Server::CS_Server(QWidget *parent): QWidget(parent), ui(new Ui::CS_Server)
{
    ui->setupUi(this);
    setWindowTitle("CS_Server V0.11");
    setMinimumSize(700,520);
    setMaximumSize(700,520);
    server_s=NULL;
    socket_s=NULL;
    filesize_temp=0;
    filename_temp="";
    server_s=new QTcpServer(this);
    server_s->listen(QHostAddress::Any,8888);
    box_s=new QMessageBox(this);
    box_s->setIcon(QMessageBox::Icon::Information);
    box_s->setModal(false);
    connect(server_s,&QTcpServer::newConnection,this,&CS_Server::getConnectInfoSlot);
    connect(&delaytimer_s,&QTimer::timeout,this,&CS_Server::sendMessageSlot);  
}

CS_Server::~CS_Server(void)
{
    delete ui;
}

void CS_Server::server_chatRecord(void)
{
    record_server.setFileName("./ChatRecord_Server.txt");
    record_server.open(QIODevice::Append);
    QString record_str=ui->textEditRead->toPlainText();
    record_server.write(record_str.toUtf8().data());
    record_server.close();
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
        filename_temp=filename_s;
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
                QString tmp_s=QString("[%1]文件接收成功!").arg(filename_temp);
                box_s->setText(tmp_s);
                box_s->show();
                server_chatRecord();
            }
        }
    }

}

void CS_Server::on_ButtonSend_clicked(void)
{
    if(socket_s!=NULL)
    {
        QString str=ui->textEditWrite->toPlainText();
        QString str_temp=QString("server:%1").arg(str);
        socket_s->write(str_temp.toUtf8().data());
        ui->textEditRead->append(str_temp);
        ui->textEditWrite->clear();
    }
}

void CS_Server::closeEvent(QCloseEvent *)
{
    if(socket_s!=NULL)
    {
        server_chatRecord();
        socket_s->disconnectFromHost();
        socket_s->close();
        delete socket_s;
        socket_s=NULL;
    }
    if(s_rec.isVisible())
    {
        s_rec.close();
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
                server_chatRecord();
                QString head=QString("%1##%2").arg(filename_s).arg(filesize_s);     //组报文头
                qint64 len=socket_s->write(head.toUtf8());
                if(len>0)
                {
                    delaytimer_s.start(20);  //延时20ms
                }
                else                         //写失败
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
        QString tmp_s=QString("[%1]文件发送成功!").arg(filename_s);
        box_s->setText(tmp_s);
        box_s->show();
    }
}

void CS_Server::on_ButtonRecord_clicked(void)
{
    s_rec.ServerRecord_File();
    s_rec.show();
}

void CS_Server::on_ButtonDel_clicked(void)
{
    int choose=QMessageBox::question(this,"确认","确定要删除聊天记录？",QMessageBox::Yes,QMessageBox::No);
    if(choose==QMessageBox::Yes)
    {
        record_server.setFileName("./ChatRecord_Server.txt");
        record_server.remove();
        QMessageBox::information(this,"删除","删除成功");
    }
}
