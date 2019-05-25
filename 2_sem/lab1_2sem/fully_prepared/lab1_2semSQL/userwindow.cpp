#include "userwindow.h"
#include "ui_userwindow.h"
#include "startwindow.h"
//#include "server.h"
//#include "crypter.h"

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

//___________Прорисовка таблицы database___________________//
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
    for (int k = 1; k < all.size() - 1; k++){
        all_2 = all[k].split(' ');
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

//______________Прорисовка таблицы с пользователями_______//
void UserWindow::drawTable_pass(QList<QByteArray> all){

    tableView_pass = new QStandardItemModel(1, 3, this);
    QStandardItem  *item;
    ui->tableView_pass->setModel(tableView_pass);
    tableView_pass->setHeaderData(0, Qt::Horizontal, "Login");
    tableView_pass->setHeaderData(1, Qt::Horizontal, "Password");
    tableView_pass->setHeaderData(2, Qt::Horizontal, "Status");
    int i = 0;
    QList <QByteArray> all_2;
    for (int k = 1; k < all.size() - 1; k++){
        all_2 = all[k].split(' ');
        QString a = all_2[0];
                    item = new QStandardItem(a);
                    tableView_pass->setItem(i, 0, item);
         a = all_2[1];
                    item = new QStandardItem(a);
                    tableView_pass->setItem(i, 1, item);
         a = all_2[2];
                    item = new QStandardItem(a);
                    tableView_pass->setItem(i, 2, item);
                    i++;

                }

}

//_________________Прорисовка информации и нужных виждетов в зависимости от статуса пользователя_________//
void UserWindow::ShowInfo(int sc_Access, QString password, QString login){
    if (sc_Access == 1)
    {
        ui->LabelAccessRight->setText( "User");
        ui->LabelLogin->setText(login);
        ui->LabelPassword->setText(password);

        ui->tableView_pass->hide();
        ui->add_pass->hide();
        ui->del_pass->hide();
        ui->ref_pass->hide();
        ui->lineEdit_status->hide();
        ui->lineEdit_login->hide();
        ui->lineEdit_pass->hide();


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

//___________Запись данных из форм в структуру______________//
datas UserWindow::LoadFromForm(){
   datasuser.ID    = ui->lineEdit_id->text();
   datasuser.fio   = ui->lineEdit_fio->text();
   datasuser.date  = ui->lineEdit_date->text();
   datasuser.type  = ui->lineEdit_type->text();
   datasuser.count = ui->lineEdit_count->text();
   datasuser.price = ui->lineEdit_price->text();
   return datasuser;
}

//_________________Изменение записи в database_________________//
void UserWindow::on_pushButtonChange_clicked(){

    datasuser = LoadFromForm();
    QByteArray mess;
    mess.append(   "Chan&" + datasuser.ID    +  "&" + datasuser.fio   +  "&" +
                             datasuser.type  +  "&" + datasuser.price +  "&" +
                             datasuser.count +  "&" + datasuser.date         );
    qDebug()  << mess << "crypted message";
    crypto crypt;
    client_socket->write(crypt.encrypt(mess));
}

//________________Прорисовка таблицы database______________________________//
void UserWindow::on_pushButton_reload_clicked(){
    QByteArray mess;
    mess.append("Ref&");
    qDebug()  << mess << "crypted message";
    crypto crypt;
    client_socket->write(crypt.encrypt(mess));
}

//________________Добавление записи в database_____________//
void UserWindow::on_pushButtonAdd_clicked(){
    datasuser = LoadFromForm();
    QByteArray mess;
    mess.append("Add&" +     datasuser.ID    +  "&" + datasuser.fio   +  "&" +
                             datasuser.type  +  "&" + datasuser.price +  "&" +
                             datasuser.count +  "&" + datasuser.date         );

    qDebug()  << mess << "crypted message";
    crypto crypt;
    client_socket->write(crypt.encrypt(mess));

}

//_________________Удаление из database ______________________//
void UserWindow::on_pushButtonDel_clicked(){
    qDebug() << "on_pushButtonDel_clicked()";
    QByteArray mess;
    mess.append("Del&" + ui->lineEdit_id->text());
    qDebug()  << mess << "crypted message";
    crypto crypt;
    client_socket->write(crypt.encrypt(mess));

}


void UserWindow::toUserWindow(QString login, QString password){
    QByteArray mess;
    userlog = login;
    userpass = password;
    mess.append("Auth&" + login + "&" + password);
    qDebug() << "message " << mess;
    crypto crypt;
    client_socket->write(crypt.encrypt(mess));

    this->show();
}


//_______________Обработка сообщений с сервера______________//
void UserWindow::slotReadyRead(){
    while (client_socket->bytesAvailable()>0) {
        answerArray = client_socket ->readAll();
        QByteArray decrypted;
        qDebug() << "array is " << answerArray;
        crypto crypt;
        decrypted = crypt.decrypt(answerArray);
        qDebug() << "decrypted array is " << decrypted;
        QList <QByteArray> all = decrypted.split('&');
        switch (all[0][0]) {

     //__________________//AuthAnswer authorization from user
        case 'A':
            if (all[1] == "User"){
                qDebug()<<"User";
                ShowInfo(1, userlog, userpass);
                emit on_pushButton_reload_clicked();
            } else if (all[1] == "Manager"){
                qDebug()<<"Manager";
                ShowInfo(2, userlog, userpass);
                emit on_pushButton_reload_clicked();
            } else if (all[1] == "Admin"){
                         qDebug()<<"Admin";
                         ShowInfo(3, userlog, userpass);
                         emit on_pushButton_reload_clicked();
            } else {
                qDebug()<<"None";
                this->close();
                StartWindow *swindow;
                swindow = new StartWindow;
                QMessageBox::critical(this, "Alert", "Wrong password or login");
                swindow->show();
            }
            break;

       //------------------// RAddAnswer& - add to database

        case 'R':
            if (all[1] == "Added"){
                qDebug() << "Added";
                emit on_pushButton_reload_clicked();
            } else qDebug() << "Not Added";
               break;

       //_______________// // RDelete& - delete from User

        case 'P':
            if (all[1] == "Deleted"){
                qDebug() << "Deleted";
                emit on_ref_pass_clicked();
            } else qDebug() << "Not Deleted";
               break;

      //________________ // LAdd& - add to User

        case 'L':
            if (all[1] == "Added"){
                qDebug() << "Added";
                emit on_ref_pass_clicked();
            } else qDebug() << "Not Added";
               break;

      //_______________// D- delete delete from database

        case 'D':
            qDebug() <<all[1];
            emit on_pushButton_reload_clicked();
            break;

    //_________________//Up - refresh database

        case 'U':
            qDebug() <<all[0];
            drawTable(all);
            break;

        case 'T':
            qDebug() << all[0];
            drawTable_pass(all);
            break;
    }
    }
}

//void UserWindow::parsing(QByteArray recieved_array){}


void UserWindow::slotSendToServer(QString message){
    QByteArray array;
    array.append(message);
    crypto crypt;
    client_socket->write(crypt.encrypt(array));
}

void UserWindow::slotDisconected(){

}

void UserWindow::slotConnected(){
  //  QMessageBox Msg;
  //  Msg.setText("connected");
  // Msg.exec();
    qDebug() << "connected";
}


//________________Удаление пользователя_________________//
void UserWindow::on_del_pass_clicked(){
    QByteArray mess;
   // QString message;
    mess.append("PDel&" + ui->lineEdit_login->text());
   // mess.append(Crypter::cryptString(message));
    qDebug()  << mess << "crypted message"; //<< Crypter::decryptString(mess) << "decrypted message";
    crypto crypt;
    client_socket->write(crypt.encrypt(mess));
}

//________________Добавление нового пользователя___________//
void UserWindow::on_add_pass_clicked(){
    QByteArray mess;
   // QString message;
    mess.append("LAdd&" + ui->lineEdit_login->text() + "&" + ui->lineEdit_pass->text()
                  + "&" + ui->lineEdit_status->text());
    //mess.append(Crypter::cryptString(message));
    qDebug()  << mess << "crypted message"; // << Crypter::decryptString(mess) << "decrypted message";
    crypto crypt;
    client_socket->write(crypt.encrypt(mess));
}

//_______________Обновление таблицы пользователей___________//
void UserWindow::on_ref_pass_clicked(){
     crypto crypt;
     client_socket->write(crypt.encrypt("Tab&")); //TablePass
}
