#include"database.h"
#include <cstdio>
#include <QMessageBox>
#include <QFile>
#include "userwindow.h"
#include <QDebug>
#include <string>

int DataBase::Authorize(QString password, QString login){
    QFile fileIn;
    fileIn.setFileName("C:/Users/Danila/Documents/2_sem/lab1_2sem/base.txt");
    if(fileIn.open(QIODevice::ReadOnly)){
        std::string t;
        std::string pas;
        std::string log;
        pas = password.toStdString();
        log = login.toStdString();
        while(!fileIn.atEnd()){
            QString temp = fileIn.readLine();
            t = temp.toStdString();
            if ((t.find("'" + pas + "'") != std::string::npos) && (t.find("'" + log + "'") != std::string::npos)){
                if (t.find("access'1'") != std::string::npos){
                fileIn.close();
                return 1;
                }
                else if (t.find("access'2'") != std::string::npos){
                    fileIn.close();
                    return 2;
                }
                else if (t.find("access'3'") != std::string::npos){
                    fileIn.close();
                    return 3;
                }
            }
         }
    QMessageBox::critical(0, "Warning", "Wrong Login or Password!");
    //ui->lineEdit_login->setStyleSheet("QLineEdit {color:red; background-color: #ffe9fd;}");
    // ui->lineEdit_password->setStyleSheet("QLineEdit {color:red; background-color: #ffe9fd;}");
    return -1;
}
   fileIn.close();
 return 0;
}

 void DataBase::output(datas a){
     QString id = QString::fromStdString(a.ID);
     qDebug() << id;
     QString name = QString::fromStdString(a.fio);
     qDebug() << name;
     QString type = QString::fromStdString(a.type);
     qDebug() << type;
     QString price = QString::fromStdString(a.price);
     qDebug() << price;
     QString count = QString::fromStdString(a.count);
     qDebug() << count;
     QString date = QString::fromStdString(a.date);
     qDebug() << date;
}

 bool DataBase::DownloadPerLine(){
     QFile fileIn;
     datas a;
     fileIn.setFileName("C:/Users/Danila/Documents/2_sem/lab1_2sem/bd.txt");
     if(fileIn.open(QIODevice::ReadOnly | QIODevice::WriteOnly ))
     {
         QString stf;
         std::string strFromFile;
         while (!fileIn.atEnd()) {
             stf = fileIn.readLine();
             strFromFile = stf.toStdString();
             a = transformStr2BD(strFromFile);
            // output(a);
         }
         return 1;
     }
     return 0;
 }

 bool DataBase::add_data(datas ab){// добавить строку данных в БД
     QFile fileIn;
     fileIn.setFileName("C:/Users/Danila/Documents/2_sem/lab1_2sem/bd.txt");
     if(fileIn.open(QIODevice::Append| QIODevice::Text)){
        DataBase a;
        QTextStream writeStream(&fileIn);
               writeStream << QString::fromStdString(ab.ID)    << ":" << QString::fromStdString(ab.fio)   << ":"
                           << QString::fromStdString(ab.type)  << ":" << QString::fromStdString(ab.price) << ":"
                           << QString::fromStdString(ab.count) << ":" << QString::fromStdString(ab.date)  << "}"
                           << '\n';
        qDebug("file opened and proccessing of adding");
        fileIn.close();
        return true;
    } else{
        return false;
    }
 }

 bool DataBase::open()//открываем файл
 {
     QFile fileIn;
     fileIn.setFileName("C:/Users/Danila/Documents/2_sem/lab1_2sem/bd.txt");
     if(fileIn.open(QIODevice::ReadOnly | QIODevice::WriteOnly))
     {
         return true;
     }
     else {
         return false;
     }
 }

 bool DataBase::close()// закрытие файла
 {
  QFile fileIn;
  fileIn.setFileName("C:/Users/Danila/Documents/2_sem/lab1_2sem/bd.txt");
  fileIn.close();
 }

 datas DataBase::parsing(std::string strFromFile){
     datas a;
 }
 //bool DataBase::download(std::string & res)//загружаем данные из файла в строку{};

datas DataBase::transformStr2BD(std::string strFromFile)// преобразует строку в БД
{
    //Цикл по входной строке
    datas a;
    //QString line = QString::fromStdString(strFromFile);
    std::string buf;
    int i = 0;
    char *c = const_cast<char*>(strFromFile.c_str());
    //ID

    while(!(c[i] == ':')){
        buf += c[i];
        i++;
    }
    a.ID = buf;
    i++;
    buf.clear();

    //FIO

    while(!(c[i] == ':')){
        buf += c[i];
        i++;
    }
    a.fio = buf;
    i++;
    buf.clear();

    //TYPE

    while(!(c[i] == ':')){
        buf += c[i];
        i++;
    }
    a.type = buf;
    i++;
    buf.clear();

    //PRICE

    while(!(c[i] == ':')){
        buf += c[i];
        i++;
    }
    a.price = buf;
    buf.clear();
    i++;

    //QUANTITY

    while(!(c[i] == ':')){
        buf += c[i];
        i++;
    }
    a.count = buf;
    buf.clear();
    i++;

    //DATE

    while(!(c[i] == '}')){
        buf += c[i];
        i++;
    }
    a.date = buf;
    return a;
}

 bool DataBase::download()//загружаем данные из файла в строку
 {
     QFile fileIn("C:/Users/Danila/Documents/2_sem/lab1_2sem/bd.txt");
     if(fileIn.open(QIODevice::ReadOnly | QIODevice::WriteOnly))
     {
         QString qres = QString::fromStdString(*res);
         qres = fileIn.readAll();
         *res = qres.toStdString();
         return true;
     }
     else return false;    // while(!fileIn.atEnd())
    // QString temp = fileIn.readLine();
    // std::string strFromFile = temp.toStdString();
    // return strFromFile;
     //data inf = transformStr2BD(strFromFile)
     close();
 }

 bool DataBase::del_data(std::string id)//удалить запись с заданным id
 {
     QFile fileIn;
     datas a;
     fileIn.setFileName("C:/Users/Danila/Documents/2_sem/lab1_2sem/bd.txt");
     if(fileIn.open(QIODevice::ReadOnly | QIODevice::WriteOnly ))
     {
         QString stf;
         std::string buf;
        // UserWindow uw;
        // datas auw;
         std::string strFromFile;
         while (!fileIn.atEnd()) {
             stf = fileIn.readLine();
             strFromFile = stf.toStdString();
             a = transformStr2BD(strFromFile);
             //output(a);
             if (a.ID != id){
                 buf += strFromFile;
             }
         }
         fileIn.close();
         if(fileIn.open(QIODevice::Truncate | QIODevice::WriteOnly )){
             qDebug() << QString::fromStdString(buf);
             QTextStream writeStream(&fileIn);
             fileIn.seek(0);
             fileIn.write(QByteArray::fromStdString(buf));
         }
         fileIn.close();
         return true;
       }
     return false;
 };

 //template<typename T>
 bool DataBase::find(datas form, datas transFromFile){//найти запись с заданным id
    if ((form.ID == transFromFile.ID) && ((form.fio == transFromFile.fio)    ||
                                         (form.type == transFromFile.type)   ||
                                         (form.price == transFromFile.price) ||
                                         (form.count == transFromFile.count) ||
                                         (form.date == transFromFile.date)   )){

        return true;
    }else {
        return false;
    }
 }

 bool DataBase::change(datas auw){
     QFile fileIn;
     datas a;
     fileIn.setFileName("C:/Users/Danila/Documents/2_sem/lab1_2sem/bd.txt");
     if(fileIn.open(QIODevice::ReadOnly | QIODevice::WriteOnly))
     {
         QString stf;
         std::string buf;
         //UserWindow uw;
         buf.clear();
         std::string strFromFile;
         while (!fileIn.atEnd()) {
             stf = fileIn.readLine();
             strFromFile = stf.toStdString();
             a = transformStr2BD(strFromFile);
             if (a.ID != auw.ID){
                 buf += strFromFile;
             }
             else{
                 // output(auw);
                  buf += (auw.ID    + ":" + auw.fio   + ":" + auw.type + ":"  +
                          auw.price  + ":" + auw.count + ":" + auw.date + "}" + "\n");
             }
         }
         fileIn.close();
         if(fileIn.open(QIODevice::Truncate| QIODevice::WriteOnly)){
        // qDebug() << QString::fromStdString(buf);
         QTextStream writeStream(&fileIn);
         fileIn.seek(0);
         writeStream << QString::fromStdString(buf);
         fileIn.close();
         return true;
         }
       }
     return false;
 }

 bool DataBase::write2file(){

 }

 DataBase::DataBase(){

 }

 DataBase::~DataBase(){

 }
