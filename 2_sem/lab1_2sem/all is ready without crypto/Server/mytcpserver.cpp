#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include "database.h"
#include "crypter.h"
#include <QDebug>

//Делать через QByteArray!!!
MyTcpServer::~MyTcpServer()
{
    foreach(int i,SClients.keys()){
        QTextStream os(SClients[i]);
        SClients[i]->close();
        SClients.remove(i);
    }
    server_status = 0;
    mTcpServer->close();
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket* clientSocket=mTcpServer->nextPendingConnection();
        int idusersocks=(int)clientSocket->socketDescriptor();
        SClients[idusersocks]=clientSocket;
        //SClients[idusersocks]->write("Hello!\n");
        qDebug() << "connected";
        connect(SClients[idusersocks],&QTcpSocket::readyRead,this, &MyTcpServer::slotServerRead);
        connect(SClients[idusersocks],&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
       //int idusersocs=clientSocket->socketDescriptor();
      // QTextStream os(clientSocket);
           if (clientSocket ->bytesAvailable () >0) {
               QByteArray array = clientSocket ->readAll();
             /*  QString mesarray = array;
               array.clear();
               array.append(Crypter::decryptString(mesarray)); */

              // qDebug() << "mesarray is" + mesarray;

                 qDebug() << "array is" + array;

                  QList <QByteArray> all = array.split('&');
                  qDebug() << "name func is " + all[0];

               for (int i = 1 ;i < all.size(); i++) {
                    qDebug() << " " <<  all[i];
                  }

                   if (all[0] == "Auth") {
                       qDebug() << "Authorization";
                       mydb->Authorize(all[1],all[2],clientSocket);

                   } else if(all[0] == "Del"){
                        qDebug() << "Delete";
                        send_to_client(mydb->del_data(all[1]), clientSocket);

                   } else if (all[0] == "Chan"){
                       qDebug() << "Change";
                       datas a;
                       a.ID    = all[1];
                       a.fio   = all[2];
                       a.type  = all[3];
                       a.price = all[4];
                       a.count = all[5];
                       a.date  = all[6];
                       send_to_client(mydb->change(a), clientSocket);

                   } else if (all[0] == "Add") {
                       qDebug() << "Add";
                       datas a;
                       a.ID    = all[1];
                       a.fio   = all[2];
                       a.type  = all[3];
                       a.price = all[4];
                       a.count = all[5];
                       a.date  = all[6];
                       send_to_client(mydb->add_data(a), clientSocket);

                   } else if (all[0] == "Ref"){
                       mydb->Refresh(clientSocket);

                   } else if (all[0] == "PDel"){
                       send_to_client(mydb->del_data_log(all[1]),clientSocket);

                   } else if (all[0] == "LAdd") {
                       send_to_client(mydb->SigningUp(all[1],all[2],all[3]), clientSocket);
                   } else if (all[0] == "Tab"){
                        mydb->Refresh_pass(clientSocket);
                   }
                   else qDebug() << "something else";
           }
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *clientSocket = (QTcpSocket*)sender();
    int id = (int)clientSocket->socketDescriptor();
    clientSocket->close();
    SClients.remove(id);
    qDebug() << QString::fromUtf8("Client is disconnected \n");
}

void MyTcpServer::send_to_client (QString message, QTcpSocket* clientSocket){
QByteArray array;
qDebug() << message;
array.append(/*Crypter::cryptString*/(message));
clientSocket->write(array);
};



/*
void MyTcpServer::parsing(QByteArray recieved_array)
{
    QList <QByteArray> all = recieved_array.split('&');
    switch (all[0][0])
    {
    case 'A': //AuthAnswer

                if (all[1] == "User"){
                    qDebug()<<"User";
                }
                if (all[1] == "None"){
                    qDebug()<<"None";
                }
        break;

    case 'R': //registration

           break;


    }

}
*/
