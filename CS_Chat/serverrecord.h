#ifndef SERVERRECORD_H
#define SERVERRECORD_H

#include <QWidget>
#include <QFile>

namespace Ui
{
class ServerRecord;
}

class ServerRecord : public QWidget
{
    Q_OBJECT

public:
    explicit ServerRecord(QWidget *parent = nullptr);
    ~ServerRecord(void);
    void ServerRecord_File(void);

private:
    Ui::ServerRecord *ui;
    QFile fileread_server;
};

#endif // SERVERRECORD_H
