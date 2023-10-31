#ifndef CS_CLIENT_H
#define CS_CLIENT_H

#include <QWidget>

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

private:
    Ui::CS_Client *ui;
};

#endif // CS_CLIENT_H
