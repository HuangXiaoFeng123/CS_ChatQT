#ifndef CS_SERVER_H
#define CS_SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPainter>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui
{
class CS_Server;
}
QT_END_NAMESPACE

class CS_Server : public QWidget
{
    Q_OBJECT

public:
    CS_Server(QWidget *parent = nullptr);
    ~CS_Server(void);
    void getConnectInfoSlot(void);
    void readInfoFromClientSlot(void);
    void sendMessageSlot(void);

protected:
    void closeEvent(QCloseEvent *);
    void paintEvent(QPaintEvent *);

private slots:
    void on_ButtonSend_clicked(void);
    void on_ButtonFile_clicked(void);

signals:
    void send_Flag(void);

private:
    Ui::CS_Server *ui;
    QTcpServer *server_s;
    QTcpSocket *socket_s;
    QFile file_s;
    QString filename_s;
    qint64 filesize_s;
    qint64 sendsize_s;
    QTimer delaytimer;
};
#endif // CS_SERVER_H
