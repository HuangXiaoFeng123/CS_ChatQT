#ifndef CLIENTRECORD_H
#define CLIENTRECORD_H

#include <QWidget>
#include <QFile>

namespace Ui
{
class ClientRecord;
}

class ClientRecord : public QWidget
{
    Q_OBJECT

public:
    explicit ClientRecord(QWidget *parent = nullptr);
    ~ClientRecord(void);

private:
    Ui::ClientRecord *ui;
    QFile fileread_client;
};

#endif // CLIENTRECORD_H
