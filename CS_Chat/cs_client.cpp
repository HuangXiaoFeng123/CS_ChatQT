#include "cs_client.h"
#include "ui_cs_client.h"

CS_Client::CS_Client(QWidget *parent) :QWidget(parent),ui(new Ui::CS_Client)
{
    ui->setupUi(this);
    setWindowTitle("CS_Client V0.05");
    setMinimumSize(700,520);
    setMaximumSize(700,520);
    filesize_temp=0;
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
    }
    if(start_sendfile==false)           //文字传输模式
    {
        ui->textEditRead->append(buff);
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

}
