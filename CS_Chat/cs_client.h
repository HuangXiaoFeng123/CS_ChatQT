#ifndef CS_CLIENT_H
#define CS_CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QPainter>

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

private:
    Ui::CS_Client *ui;
    QTcpSocket *socket_c;
};

#endif // CS_CLIENT_H
