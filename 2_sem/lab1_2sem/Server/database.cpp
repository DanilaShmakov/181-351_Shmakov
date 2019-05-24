#include "database.h"
#include "crypter.h"
#include <cstdio>
#include <QFile>
#include <QDebug>
#include <QObject>

#include <QtSql>
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


 void DataBase::output(datas a){
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


 DataBase::DataBase(){
}
 void DataBase::despair(){
     db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("DB.sqlite");

     if(!db.open()){
         qDebug()<<db.lastError().text();
     }
          QSqlQuery query(db);

              if(db.tables().indexOf("User")==-1){
               qDebug() << "create User";
                query.exec("CREATE TABLE User("
                     "login VARCHAR(20) NOT NULL, "
                     "password VARCHAR(20) NOT NULL,"
                     "status VARCHAR(20) NOT NULL"
                     ")");
      }
        if(db.tables().indexOf("database")==-1){
               qDebug() << "create database";
                query.exec("CREATE TABLE database("
                          "id    VARCHAR(20) NOT NULL, "
                          "fio   VARCHAR(20) NOT NULL, "
                          "type  VARCHAR(20) NOT NULL, "
                          "price INT(10) NOT NULL, "
                          "count INT(10) NOT NULL, "
                          "date  DATE(10) NOT NULL  "
                          ")");
           }
       /* // query.prepare("DELETE FROM database");
        //query.exec();
         query.prepare("INSERT INTO database(id, fio, type, price,count,date) "
                             "VALUES (:id, :fio, :type, :price,:count,:date)");
         for (int i = 0; i < 30; i++){


             query.bindValue(":id", QString::number(i) );
             query.bindValue(":fio",  "Name" + QString::number(i));
             query.bindValue(":type", "Type" + QString::number(i));
             query.bindValue(":price", QString::number(i + i % 3) );
             query.bindValue(":count", "1" + QString::number(i + i % 4));
             query.bindValue(":date", (QString::number(1990 + i)) + "." + QString::number(i % 12) + "." + (QString::number( 1+ ((20 + i) % 27))));

             query.exec();// выполнить запрос
         }
         */
 }

 DataBase::~DataBase(){
 db.close();
 }

 //new funcs

 bool DataBase::SigningUp(QString log, QString pass){

     QSqlQuery query;

     query.prepare("INSERT INTO User(login, password, status) "
                         "VALUES (:login, :password, :status)");


         query.bindValue(":password", pass);
         query.bindValue(":login",log);
         query.bindValue(":status", 1);

         query.exec();// выполнить запрос


     return true;
 }

 void DataBase::Authorize(QByteArray QBAlog, QByteArray QBApass, QTcpSocket* client_socket){
         QSqlQuery query;
         QString log,pass;
         log.append(QBAlog);
         pass.append(QBApass);
         qDebug() << "QBAlog " << QBAlog << " log " << log;

         query.prepare("SELECT * FROM User WHERE login = :log AND password = :pass" );
         query.bindValue(":log",  log);
         query.bindValue(":pass", pass);
         //query.bindValue(":status", "1");
         query.exec();

         QSqlRecord rec = query.record();
         const int loginIndex = rec.indexOf("login");//номер "столбца"
         const int passwordIndex = rec.indexOf("password");
         const int statusIndex = rec.indexOf("status");


         if(query.next()){
             qDebug()<< query.value(loginIndex).toString()   << "\t"
                     << query.value(passwordIndex).toString()<< "\t"
                     << query.value(statusIndex).toString()  << "\n";
         if (query.value(statusIndex).toString() == "user"){
             QByteArray mess;
             mess.append(Crypter::cryptString("AuthAnswer&User"));
             client_socket->write(mess);
         } else  if (query.value(statusIndex).toString() == "manager"){
             QByteArray mess;
             mess.append(Crypter::cryptString("AuthAnswer&Manager"));
             qDebug() << mess;
             client_socket->write(mess);
         } else  if (query.value(statusIndex).toString() == "admin"){
             QByteArray mess;
             mess.append(Crypter::cryptString("AuthAnswer&Admin"));
             client_socket->write(mess);
         }} else {
             QByteArray mess;
             mess.append(Crypter::cryptString("AuthAnswer&None"));
             client_socket->write(mess);
         }


 }


 QByteArray DataBase::add_data(datas ab){// добавить строку данных в БД

     QSqlQuery query;

        query.prepare("INSERT INTO database (id,fio,type,price,count,date) "
                         "VALUES (:id, :fio, :type, :price, :count, :date)");


         query.bindValue(":id",    ab.ID);
         query.bindValue(":fio",   ab.fio);
         query.bindValue(":type",  ab.type);
         query.bindValue(":price", ab.price);
         query.bindValue(":count", ab.count);
         query.bindValue(":date",  ab.date);

         if(query.exec()){// выполнить запрос
             return "AddAnswer&Added";
             } else {
                 return "AddAnswer&NotAdded";
        }
 }

 QByteArray DataBase::del_data(QString id){//удалить запись с заданным id

     QSqlQuery query;
     query.prepare("DELETE FROM database WHERE id =:id");
     query.bindValue(":id",id);
     if(query.exec()){
     return "DelAnswer&Deleted";
     } else {
         return "DelAnswer&NotDeleted";
}
 };

 QByteArray DataBase::change(datas ab){
     QSqlQuery query;
     //qDebug()<<ab.fio;
     query.prepare("UPDATE  database SET fio = :fio, type = :type, price = :price, count = :count, date = :date) "
                   " WHERE id =:id");
     query.bindValue(":id",    ab.ID);
     query.bindValue(":fio",   ab.fio);
     query.bindValue(":type",  ab.type);
     query.bindValue(":price", ab.price);
     query.bindValue(":count", ab.count);
     query.bindValue(":date",  ab.date);

     if(query.exec()){
     return "ChangeAnswer&Changed";
     } else {
         return "ChangeAnswer&NotChanged";
}
 }

 QSqlDatabase DataBase::getDB(){
     return db;
 }

 void DataBase::Refresh(QTcpSocket* client_socket){
     QSqlQuery query;
     QByteArray buffer;
     buffer.clear();

     query.prepare("SELECT * FROM database" );
     query.exec();

     QSqlRecord rec = query.record();
     const int idIndex    = rec.indexOf("id");//номер "столбца"
     const int fioIndex   = rec.indexOf("fio");
     const int typeIndex  = rec.indexOf("type");
     const int priceIndex = rec.indexOf("price");//номер "столбца"
     const int countIndex = rec.indexOf("count");
     const int dateIndex  = rec.indexOf("date");


     while(query.next()){
         qDebug()<< query.value(idIndex).toString()    << "\t"
                 << query.value(fioIndex).toString()   << "\t"
                 << query.value(typeIndex).toString()  << "\t"
                 << query.value(priceIndex).toString() << "\t"
                 << query.value(countIndex).toString() << "\t"
                 << query.value(dateIndex).toString()  << "\n";
         buffer.append(query.value(idIndex).toString()    +  "|" +
                       query.value(fioIndex).toString()   +  "|" +
                       query.value(typeIndex).toString()  +  "|" +
                       query.value(priceIndex).toString() +  "|" +
                       query.value(countIndex).toString() +  "|" +
                       query.value(dateIndex).toString()  +  "|&" );
     }
     qDebug() << buffer;
     QString cryptedbuf;
     //cryptedbuf = "Up&" + buffer;
     buffer.clear();
     buffer.append(Crypter::cryptString(cryptedbuf));
     qDebug() << buffer;
     client_socket->write(buffer);
 }
 // проверки

/* bool DataBase::checkFio(QString fio) {
     if ((fio.size() > 20) || (fio.size() < 1)){
         QMessageBox::critical(0,"ERROR","Prohibited size");
         return false;
     } else {
         for (int i = 0; i <= fio.size(); i++) { // не работает
            if(!fio[i].isLetter()) {
             //   return false;
            }
         }
       }
     return true;
 }

 QString DataBase::registrFio(QString fio){ // ноуп
     QChar charFio = 'a';
     charFio.toUpper();

     qDebug() << charFio << " 1";
    // for (int i = 1; i <= fio.size(); i++) {
     //   fio[i].toLower();
    // }
     charFio.toLower();
     qDebug() << charFio << " 2";
     return fio;
 }
 */
