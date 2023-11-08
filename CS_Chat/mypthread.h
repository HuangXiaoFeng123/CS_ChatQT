#ifndef MYPTHREAD_H
#define MYPTHREAD_H

#include <QThread>
#include <QtDebug>

class MyPthread:public QThread
{
    Q_OBJECT
public:
    explicit MyPthread(QObject *parent=nullptr);

protected:
    void run(void);

signals:
    void isDone(void);
};

#endif // MYPTHREAD_H
