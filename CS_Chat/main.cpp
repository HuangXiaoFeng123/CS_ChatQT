#include "cs_server.h"
#include "cs_client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CS_Server s;
    s.show();
    CS_Client c;
    c.show();
    return a.exec();
}
