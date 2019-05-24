#ifndef SERVER_H
#define SERVER_H

#include <QSqlDatabase>
#include <QTcpServer>
#include <QTcpSocket>

struct datas{
    QString ID;
    QString fio;
    QString type;
    QString price;
    QString count;
    QString date;

};

class Server{

public:

    Server();//конструктор
    ~Server();//деструктор
    void output(struct datas);//Вывод структуры в косноль
public slots:
    void slotConnected();
    void slotReadyRead();
    void slotSendToServer(QString);
    void slotDisconected();
private:
     QTcpSocket *client_socket;
     void parsing(QByteArray recieved_array);
protected:


};

#endif
