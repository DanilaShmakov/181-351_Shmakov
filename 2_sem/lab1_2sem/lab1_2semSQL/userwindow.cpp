#include "userwindow.h"
#include "ui_userwindow.h"
#include "startwindow.h"
//#include "server.h"
#include "crypter.h"

#include<vector>
#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
UserWindow::UserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserWindow)
{
 ui->setupUi(this);

 client_socket = new QTcpSocket(this);
 client_socket->connectToHost( "127.0.0.1" , 33333 );

 connect(client_socket, SIGNAL(connected()),SLOT(slotConnected()));

 connect(client_socket, SIGNAL(readyRead()), SLOT(slotReadyRead()));

 qDebug()<<"UserWindow constr";
}

void UserWindow::drawTable(QList<QByteArray> all){

    tableDB = new QStandardItemModel(1, 6, this);
    QStandardItem  *item;
    ui->tableDB->setModel(tableDB);
    tableDB->setHeaderData(0, Qt::Horizontal, "ID");
    tableDB->setHeaderData(1, Qt::Horizontal, "FIO");
    tableDB->setHeaderData(2, Qt::Horizontal, "Type");
    tableDB->setHeaderData(3, Qt::Horizontal, "Price");
    tableDB->setHeaderData(4, Qt::Horizontal, "Quantity");
    tableDB->setHeaderData(5, Qt::Horizontal, "Date");
    int i = 0;
    QList <QByteArray> all_2;
    //std::vector<QByteArray> vecall;
    //QByteArray word;
    for (int k = 1; k < all.size() - 1; k++){
        //vecall.push_back(all[k]);
        all_2 = all[k].split('|');
        QString a = all_2[0];
                    item = new QStandardItem(a);
                    tableDB->setItem(i, 0, item);
         a = all_2[1];
                    item = new QStandardItem(a);
                    tableDB->setItem(i, 1, item);
         a = all_2[2];
                    item = new QStandardItem(a);
                    tableDB->setItem(i, 2, item);
         a = all_2[3];
                    item = new QStandardItem(a);
                    tableDB->setItem(i, 3, item);
         a = all_2[4];
                    item = new QStandardItem(a);
                    tableDB->setItem(i, 4, item);
         a = all_2[5];
                    item = new QStandardItem(a);
                    tableDB->setItem(i, 5, item);
                    i++;

                }

}

void UserWindow::ShowInfo(int sc_Access, QString password, QString login){
    if (sc_Access == 1)
    {
        ui->LabelAccessRight->setText( "User");
        ui->LabelLogin->setText(login);
        ui->LabelPassword->setText(password);
    }
    if (sc_Access == 2)
    {
        ui->LabelAccessRight->setText( "Manager");
        ui->LabelLogin->setText(login);
        ui->LabelPassword->setText(password);
    }
    if (sc_Access == 3)
    {
        ui->LabelAccessRight->setText( "Admin");
        ui->LabelLogin->setText(login);
        ui->LabelPassword->setText(password);
    }
    if (sc_Access == 0)
    {
        ui->LabelAccessRight->setText( "000000");
        ui->LabelLogin->setText("000000");
        ui->LabelPassword->setText("000000");
    }
}

UserWindow::~UserWindow()
{
    delete ui;
}


datas UserWindow::LoadFromForm(){
   datasuser.ID    = ui->lineEdit_id->text();
   datasuser.fio   = ui->lineEdit_fio->text();
   datasuser.date  = ui->lineEdit_date->text();
   datasuser.type  = ui->lineEdit_type->text();
   datasuser.count = ui->lineEdit_count->text();
   datasuser.price = ui->lineEdit_price->text();
   return datasuser;
}
void UserWindow::on_pushButtonChange_clicked(){

    datasuser = LoadFromForm();
    QByteArray mess;
    QString message;
    message.append("Chan&" + datasuser.ID    +  "&" + datasuser.fio   +  "&" +
                             datasuser.type  +  "&" + datasuser.price +  "&" +
                             datasuser.count +  "&" + datasuser.date         );
    mess.append(Crypter::cryptString(message));
    qDebug()  << mess << "crypted message" << Crypter::decryptString(mess) << "decrypted message";
    client_socket->write(mess);
}

void UserWindow::on_pushButton_reload_clicked(){
  //  drawTable();
    QByteArray mess;
    QString message;
    message.append("Ref&");
    mess.append(Crypter::cryptString(message));
    qDebug()  << mess << "crypted message" << Crypter::decryptString(mess) << "decrypted message";
    client_socket->write(mess);
}

void UserWindow::on_pushButtonAdd_clicked(){
    datasuser = LoadFromForm();
    QByteArray mess;
    QString message;
    message.append("Add&" +  datasuser.ID    +  "&" + datasuser.fio   +  "&" +
                             datasuser.type  +  "&" + datasuser.price +  "&" +
                             datasuser.count +  "&" + datasuser.date         );

    mess.append(Crypter::cryptString(message));
    qDebug()  << mess << "crypted message" << Crypter::decryptString(mess) << "decrypted message";
    client_socket->write(mess);

}

void UserWindow::on_pushButtonDel_clicked(){
    qDebug() << "on_pushButtonDel_clicked()";
    QByteArray mess;
    QString message;
    message.append("Del&" + ui->lineEdit_id->text());
    mess.append(Crypter::cryptString(message));
    qDebug()  << mess << "crypted message" << Crypter::decryptString(mess) << "decrypted message";
    client_socket->write(mess);

}

void UserWindow::toUserWindow(QString login, QString password){
    QByteArray mess;
    QString message;
    userlog = login;
    userpass = password;
    message.append("Auth&" + login + "&" + password);
    qDebug() << "message " << message;
    mess.append(Crypter::cryptString(message));
    client_socket->write(mess);

    //через s
    this->show();
}

void UserWindow::slotReadyRead(){
    //QByteArray array;
  //  std::string message;
    while (client_socket->bytesAvailable()>0) {
        answerArray = client_socket ->readAll();
        qDebug() << "array is " << answerArray;
        QString mesarray;
        mesarray.append(answerArray);
        qDebug() << "mesarray is " << mesarray;
        answerArray.clear();
        answerArray.append(Crypter::decryptString(answerArray));
        qDebug() << "array is " << answerArray;
      //  qDebug() << "Crypter::decryptString(mesarray) " << Crypter::decryptString(mesarray);
        QList <QByteArray> all = answerArray.split('&');
        switch (all[0][0])
        {
        case 'A': //AuthAnswer

                    if (all[1] == "User"){
                        qDebug()<<"User";
                         ShowInfo(1, userlog, userpass);
                    } else if (all[1] == "Manage"){     // почему-то обрезается последняя буква
                         qDebug()<<"Manager";
                          ShowInfo(2, userlog, userpass);
                    } else if (all[1] == "Admin"){
                         qDebug()<<"Admin";
                          ShowInfo(3, userlog, userpass);
                    } else {
                        qDebug()<<"None";
                        this->close();
                        StartWindow *swindow;
                        swindow = new StartWindow;
                        QMessageBox::critical(this, "Alert", "Wrong password or login");
                        swindow->show();
                    }
            break;

        case 'D': qDebug() <<all[1]; // D- delete
               break;

        case 'U': qDebug() <<all[0]; //Up - refresh
               drawTable(all);
               break;
    }
    }
}

//void UserWindow::parsing(QByteArray recieved_array){}


void UserWindow::slotSendToServer(QString message){
    QByteArray array;
    array.append(message);
    client_socket->write(array);
}

void UserWindow::slotDisconected(){

}

void UserWindow::slotConnected(){
  //  QMessageBox Msg;
  //  Msg.setText("connected");
  // Msg.exec();
    qDebug() << "connected";
}

