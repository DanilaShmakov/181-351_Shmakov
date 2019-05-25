#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtSql>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include "database.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
    void send_to_client (QString message, QTcpSocket* clientSocket);

private:

    //void parsing(QByteArray recieved_array);
    QTcpServer * mTcpServer;
    int server_status;
    QMap<int,QTcpSocket *> SClients;
    QSqlDatabase *db;
    DataBase *mydb;
};
#endif // MYTCPSERVER_H







