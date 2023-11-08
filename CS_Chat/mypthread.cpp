#include "mypthread.h"

MyPthread::MyPthread(QObject *parent):QThread(parent)
{

}

void MyPthread::run(void)
{
    sleep(3);
    emit isDone();
}
