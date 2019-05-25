#include "database.h"
#include "crypto.h"
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
#include <QCryptographicHash>


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

 QByteArray DataBase::SigningUp(QByteArray login, QByteArray  password, QByteArray status){

     QSqlQuery query;
     QString pass, log, stat;
     log.append(login);
     pass.append(password);
     stat.append(status);
     query.prepare("INSERT INTO User(login, password, status) "
                         "VALUES (:login, :password, :status)");


         query.bindValue(":password", pass);
         query.bindValue(":login",log);
         query.bindValue(":status", stat);

         crypto c;
         if(query.exec()){
         return c.encrypt("LAddAnswer&Added");
         } else {
             return c.encrypt("LAddAnswer&NotAdded");
         }

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

        crypto c;
         if(query.next()){
             qDebug()<< query.value(loginIndex).toString()   << "\t"
                     << query.value(passwordIndex).toString()<< "\t"
                     << query.value(statusIndex).toString()  << "\n";
         if (query.value(statusIndex).toString() == "user"){

             client_socket->write(c.encrypt("AuthAnswer&User"));
         } else  if (query.value(statusIndex).toString() == "manager"){

             client_socket->write(c.encrypt("AuthAnswer&Manager"));
         } else  if (query.value(statusIndex).toString() == "admin"){

             client_socket->write(c.encrypt("AuthAnswer&Admin"));
         }} else {
             client_socket->write(c.encrypt("AuthAnswer&None"));
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
         crypto c;
         if(query.exec()){// выполнить запрос
             return c.encrypt("RAddAnswer&Added");
             } else {
                 return c.encrypt("RAddAnswer&NotAdded");
        }
 }

 QByteArray DataBase::del_data(QString id){//удалить запись с заданным id

     QSqlQuery query;
     query.prepare("DELETE FROM database WHERE id =:id");
     query.bindValue(":id",id);
     crypto c;
     if(query.exec()){
     return c.encrypt("DelAnswer&Deleted");
     } else {
         return c.encrypt("DelAnswer&NotDeleted");
}
 };

 QByteArray DataBase::change(datas ab){
     QSqlQuery query;
     query.prepare("UPDATE  database SET fio = :fio, type = :type, price = :price, count = :count, date = :date) "
                   " WHERE id =:id");
     query.bindValue(":id",    ab.ID);
     query.bindValue(":fio",   ab.fio);
     query.bindValue(":type",  ab.type);
     query.bindValue(":price", ab.price);
     query.bindValue(":count", ab.count);
     query.bindValue(":date",  ab.date);
     crypto c;
     if(query.exec()){
     return c.encrypt("ChangeAnswer&Changed");
     } else {
         return c.encrypt("ChangeAnswer&NotChanged");
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

     buffer.append("Up&");
     while(query.next()){
         qDebug()<< query.value(idIndex).toString()    << "\t"
                 << query.value(fioIndex).toString()   << "\t"
                 << query.value(typeIndex).toString()  << "\t"
                 << query.value(priceIndex).toString() << "\t"
                 << query.value(countIndex).toString() << "\t"
                 << query.value(dateIndex).toString()  << "\n";
         buffer.append(query.value(idIndex).toString()    +  " " +
                       query.value(fioIndex).toString()   +  " " +
                       query.value(typeIndex).toString()  +  " " +
                       query.value(priceIndex).toString() +  " " +
                       query.value(countIndex).toString() +  " " +
                       query.value(dateIndex).toString()  +  " &" );
     }
     crypto c;
     qDebug() << buffer;

     client_socket->write(c.encrypt(buffer));
 }

 QByteArray DataBase::del_data_log(QString log){//удалить запись с заданным id

     QSqlQuery query;
     query.prepare("DELETE FROM User WHERE login =:log");
     query.bindValue(":log", log);
     crypto c;
     if(query.exec()){
     return c.encrypt("PDelAnswer&Deleted");
     } else {
         return c.encrypt("PDelAnswer&NotDeleted");
}
 };

 //______________Обновление таблицы пользователей__________//
 void DataBase::Refresh_pass(QTcpSocket* client_socket){
     QSqlQuery query;
     QByteArray buffer;
     buffer.clear();

     query.prepare("SELECT * FROM User" );
     query.exec();

     QSqlRecord rec = query.record();
     const int loginIndex      = rec.indexOf("login");//номер "столбца"
     const int passwordIndex   = rec.indexOf("password");
     const int statusIndex     = rec.indexOf("status");

        buffer.append("TabAnswer&");
     while(query.next()){
         qDebug()<< query.value(loginIndex).toString()      << "\t"
                 << query.value(passwordIndex).toString()   << "\t"
                 << query.value(statusIndex).toString()     << "\n";
         buffer.append(query.value(loginIndex).toString()    +  " " +
                       query.value(passwordIndex).toString() +  " " +
                       query.value(statusIndex).toString()   +  " &" );
     }
     qDebug() << buffer;
     crypto c;
     client_socket->write(c.encrypt(buffer));
 }



