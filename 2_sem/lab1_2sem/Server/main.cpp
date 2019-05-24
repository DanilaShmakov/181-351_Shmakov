#include <QCoreApplication>
#include "mytcpserver.h"
#include "database.h"

int main(int argc, char *argv[])
{
    DataBase ab;
    ab.despair();
    QCoreApplication a(argc, argv);
    MyTcpServer ser;
    return a.exec();
}
