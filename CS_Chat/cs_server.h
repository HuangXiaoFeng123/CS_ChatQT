#ifndef CS_SERVER_H
#define CS_SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
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

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_ButtonSend_clicked(void);

private:
    Ui::CS_Server *ui;
    QTcpServer *server_s;
    QTcpSocket *socket_s;
};
#endif // CS_SERVER_H
