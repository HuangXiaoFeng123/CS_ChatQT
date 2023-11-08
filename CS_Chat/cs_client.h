#ifndef CS_CLIENT_H
#define CS_CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QPainter>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "clientrecord.h"
#include "mypthread.h"

namespace Ui
{
class CS_Client;
}

class CS_Client : public QWidget
{
    Q_OBJECT

public:
    explicit CS_Client(QWidget *parent = nullptr);
    ~CS_Client(void);
    void getConnectInfoSlot(void);
    void readInfoFromServerSlot(void);
    void sendMessageSlot(void);
    void delayReconnectSlot(void);
    void client_chatRecord(void);

protected:
    void closeEvent(QCloseEvent *);
    void paintEvent(QPaintEvent *);

private slots:
    void on_ButtonConnect_clicked(void);
    void on_ButtonSend_clicked(void);
    void on_ButtonFile_clicked(void);
    void on_pushButton_clicked(void);
    void on_ButtonDel_clicked(void);

private:
    Ui::CS_Client *ui;
    QTcpSocket *socket_c;
    QFile file_c;
    QFile record_client;
    QString filename_c;
    qint64 filesize_c;
    qint64 recvsize_c;
    qint64 sendsize_c;
    bool start_sendfile;
    bool is_start;
    QTimer delaytimer_c;
    QTimer delayreconnect_timer;
    qint64 filesize_temp;
    QString filename_temp;
    QMessageBox *box_c;
    ClientRecord c_rec;
    MyPthread *thread_c;
};

#endif // CS_CLIENT_H
