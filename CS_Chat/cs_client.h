#ifndef CS_CLIENT_H
#define CS_CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QPainter>
#include "cs_server.h"

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

protected:
    void closeEvent(QCloseEvent *);
    void paintEvent(QPaintEvent *);

private slots:
    void on_ButtonConnect_clicked(void);
    void on_ButtonSend_clicked(void);
    void on_ButtonFile_clicked(void);

private:
    Ui::CS_Client *ui;
    QTcpSocket *socket_c;
    QFile file_c;
    QString filename_c;
    qint64 filesize_c;
    qint64 recvsize_c;
    CS_Server *s;
    bool start_sendfile;
    bool is_start;
    qint64 filesize_temp;
};

#endif // CS_CLIENT_H
