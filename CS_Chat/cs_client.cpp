#include "cs_client.h"
#include "ui_cs_client.h"

CS_Client::CS_Client(QWidget *parent) :QWidget(parent),ui(new Ui::CS_Client)
{
    ui->setupUi(this);
    setWindowTitle("CS_Client V0.08");
    setMinimumSize(700,520);
    setMaximumSize(700,520);
    filesize_temp=0;
    filename_temp="";
    socket_c=new QTcpSocket(this);
    box_c=new QMessageBox(this);
    box_c->setIcon(QMessageBox::Icon::Information);
    box_c->setModal(false);
    connect(socket_c,&QTcpSocket::connected,this,&CS_Client::getConnectInfoSlot);
    connect(socket_c,&QTcpSocket::readyRead,this,&CS_Client::readInfoFromServerSlot);
    connect(&delaytimer_c,&QTimer::timeout,this,&CS_Client::sendMessageSlot);
    connect(&delayreconnect_timer,&QTimer::timeout,this,&CS_Client::delayReconnectSlot);
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
    start_sendfile=false;
    is_start=false;
}

void CS_Client::readInfoFromServerSlot(void)
{
    QByteArray buff=socket_c->readAll();
    filename_c=QString(buff).section("##",0,0);
    filesize_c=QString(buff).section("##",1,1).toInt();
    if((!filename_c.isEmpty())&&(filesize_c!=0))
    {
        start_sendfile=true;
        is_start=true;
        filesize_temp=filesize_c;       //第二次解出来文件大小为0 需保存第一次解包的文件大小准确的数值
        filename_temp=filename_c;
    }
    if(start_sendfile==false)           //文字传输模式
    {
        QString str=QString("server:%1").arg(QString(buff));
        ui->textEditRead->append(str);
    }
    else                                //文件传输模式
    {
        if(is_start==true)
        {
            is_start=false;
            recvsize_c=0;
            file_c.setFileName(filename_c);
            file_c.open(QIODevice::WriteOnly);
        }
        else
        {
            qint64 len=file_c.write(buff);
            if(len>0)
            {
                recvsize_c+=len;
            }
            if(recvsize_c==filesize_temp)
            {
                start_sendfile=false;
                file_c.close();
                socket_c->disconnectFromHost();
                socket_c->close();
                QString tmp_c=QString("[%1]文件接收成功!").arg(filename_temp);
                box_c->setText(tmp_c);
                box_c->show();
                on_ButtonConnect_clicked();
            }
        }
    }
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

void CS_Client::on_ButtonFile_clicked(void)
{
    QString path=QFileDialog::getOpenFileName(this,"open","../");
    if(path.isEmpty()==false)
    {
        filename_c="";
        filesize_c=0;
        sendsize_c=0;
        QFileInfo info(path);
        filename_c=info.fileName();
        filesize_c=info.size();
        file_c.setFileName(path);
        bool read_fileOK=file_c.open(QIODevice::ReadOnly);
        if(read_fileOK==true)
        {
             int ret=QMessageBox::question(this,"发送","确定要发送?",QMessageBox::Yes,QMessageBox::No);
             if(ret==QMessageBox::Yes)
             {
                 QString head=QString("%1##%2").arg(filename_c).arg(filesize_c);
                 qint64 len=socket_c->write(head.toUtf8());
                 if(len>0)
                 {
                     delaytimer_c.start(20);
                 }
                 else
                 {
                     file_c.close();
                 }
             }
             else
             {
                 path="";
             }
        }
    }
}

void CS_Client::delayReconnectSlot(void)
{
    delayreconnect_timer.stop();
    on_ButtonConnect_clicked();
}

void CS_Client::sendMessageSlot(void)
{
    delaytimer_c.stop();
    qint64 len=0;
    do
    {
        char buff[4*1024]={0};
        len=file_c.read(buff,sizeof(buff));
        socket_c->write(buff,len);
        sendsize_c+=len;
    }while(len>0);
    qDebug()<<sendsize_c<<" "<<filesize_c;
    if(sendsize_c==filesize_c)
    {
        file_c.close();
        socket_c->disconnectFromHost();
        socket_c->close();
        QString tmp_c=QString("[%1]文件发送成功!").arg(filename_c);
        box_c->setText(tmp_c);
        box_c->show();
        delayreconnect_timer.start(1);      //延时重连
    }
}





