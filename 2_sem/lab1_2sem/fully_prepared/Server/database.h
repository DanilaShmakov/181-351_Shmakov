#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include <fstream>
#include "QFile"
#include <QSqlDatabase>
#include <QTcpSocket>
#include "crypto.h"

struct datas{
    QString ID;
    QString fio;
    QString type;
    QString price;
    QString count;
    QString date;

};

class DataBase{

public:
    //datas dbstruct; del this?

   // QSqlDatabase db;//ПЕРЕНЕСТИ В PRIVATE!!!!!!!!

    DataBase();//конструктор
    ~DataBase();//деструктор
    void output(struct datas);//Вывод структуры в косноль

    // new funcs
    void despair();
    QByteArray SigningUp(QByteArray,QByteArray,QByteArray );
    void Authorize( QByteArray, QByteArray, QTcpSocket*);
    QByteArray add_data(datas);// добавить строку данных в БД
    QByteArray del_data(QString id);//удалить запись с заданным id
    QByteArray del_data_log(QString id);
    QByteArray change(datas);
    void Refresh(QTcpSocket*);
    void Refresh_pass(QTcpSocket* client_socket);
    //проверки
    bool checkFio(QString fio);//Используемые символы - только буквы; не превышен ли размер строки
    QString registrFio(QString fio); //Если регистр не тот, меняем на правильный.
    //bool checkType(std::string tel);//длина строки 10 символов, все из которых цифры;
    //bool checkDate(std::string date);//тип данных Date

   QSqlDatabase getDB();
private:
   QSqlDatabase db;
protected:


};
#endif // DATABASE_H
