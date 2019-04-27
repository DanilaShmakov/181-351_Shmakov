#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include <fstream>
#include "QFile"

struct datas{
    std::string ID;
    std::string fio;
    std::string type;
    std::string price;
    std::string count;
    std::string date;

};
//bool checkFio(std::string fio);//Используемые символы - только буквы; Если регистр не тот, меняем на правильный.
//bool checkType(std::string tel);//длина строки 10 символов, все из которых цифры;
//bool checkDate(std::string date);//тип данных Date

class DataBase{

public:
    DataBase();//конструктор
    DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД
    ~DataBase();//деструктор
    void output(struct datas);//Вывод структуры в косноль
    bool add_data(datas);// добавить строку данных в БД
    bool open();//открываем файл
   // bool download(std::string & res);//загружаем данные из файла в строку
    bool close();// закрытие файла
    datas parsing(std::string strFromFile);
    datas transformStr2BD(std::string strFromFile);// преобразует строку в БД
    bool download();//загружаем данные из файла в строку
    bool del_data(std::string id);//удалить запись с заданным id
   // template<typename T>
    int Authorize(QString password, QString login);
    bool find(datas form, datas transFromFile);//найти запись
    bool change(datas);
    bool write2file();
    bool DownloadPerLine();
    std::string getRes(){return *res;}
    std::vector<datas> *db;
    std::string *res;
private:

protected:


};
#endif // DATABASE_H
