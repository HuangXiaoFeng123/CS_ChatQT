#ifndef CS_SERVER_H
#define CS_SERVER_H

#include <QWidget>

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

private:
    Ui::CS_Server *ui;
};
#endif // CS_SERVER_H
