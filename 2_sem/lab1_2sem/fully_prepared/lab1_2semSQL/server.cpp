#include "server.h"
#include <cstdio>
#include <QMessageBox>
#include <QFile>
#include "userwindow.h"
#include <QDebug>
#include <QObject>

#include <QCoreApplication>
#include <QVariant>



 void Server::output(datas a){
     QString id = a.ID;
     qDebug() << id;
     QString name = a.fio;
     qDebug() << name;
     QString type = a.type;
     qDebug() << type;
     QString price =a.price;
     qDebug() << price;
     QString count = a.count;
     qDebug() << count;
     QString date = a.date;
     qDebug() << date;
}


 // server
 void Server::slotConnected(){
     QMessageBox Msg;
     Msg.setText("connected");
     Msg.exec();
 }

 void Server::slotReadyRead(){
     QByteArray array;
     std::string message;
     while (client_socket->bytesAvailable()>0) {
         QByteArray array = client_socket ->readAll();
         qDebug() << "array is" + array;
         parsing(array);

     }
     QMessageBox Msg;
     Msg.setText(QString::fromStdString(message));
     Msg.exec();
 }

void Server::parsing(QByteArray recieved_array)
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


 void Server::slotSendToServer(QString message){
     QByteArray array;
     array.append(message);
     client_socket->write(array);
 }

 void Server::slotDisconected(){

 }
