#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include "userwindow.h"
StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)

{
    ui->setupUi(this);
    client_socket = new QTcpSocket(this);
    client_socket->connectToHost( "127.0.0.1" , 33333 );

    connect(client_socket, SIGNAL(connected()),SLOT(slotConnected()));

    uWindow = new UserWindow;
    connect (uWindow,&UserWindow::userWindow, this, &StartWindow::show);
}

StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::on_pushButton_SignUp_clicked()
{
    //
    qDebug("clicked");
}



void StartWindow::on_pB_Authorize_clicked()
{
    QString password = ui->lineEdit_password->text();
    QString login = ui->lineEdit_login->text();
    QString message = "auth&"+login+"&"+password;
    slotSendToServer(message);
    DataBase a;
  switch(a.Authorize(password,login))
  {
  case 1:
      uWindow->drawTable();
      uWindow->ShowInfo(1, password, login);
      this->close();
      uWindow->show();
      break;
  case 2:
      uWindow->drawTable();
      uWindow->ShowInfo(2, password, login);
      this->close();
      uWindow->show();
      break;
  case 3:
      uWindow->drawTable();
      uWindow->ShowInfo(3, password, login);
      this->close();
      uWindow->show();
      break;
  default:
      ui->lineEdit_login->setStyleSheet("background-color: rgb(255, 156, 174);");
      ui->lineEdit_password->setStyleSheet("background-color: rgb(255, 156, 174);");
  }
}
bool view = false;
void StartWindow::on_radioButton_Eye_clicked()
{
    if (!view) {
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
        view = true;
    }
    else {
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        view = false;
    }
}

void StartWindow::on_pushButton_Home_clicked()//НЕ БАГ, А ФИЧА (открывает только что закрывшееся окно)
{
   this->close();
   emit SWindow();
}

void StartWindow::slotConnected(){
    QMessageBox Msg;
    Msg.setText("connected");
    Msg.exec();
}

void StartWindow::slotReadyRead(){
    QByteArray array;
    std::string message;
    while (client_socket->bytesAvailable()>0) {
        array = client_socket->readAll();
        message = array.toStdString();
        //qDebug() << QString::fromStdString(message);
    }
    QMessageBox Msg;
    Msg.setText(QString::fromStdString(message));
    Msg.exec();
}

void StartWindow::slotSendToServer(QString message){
    QByteArray array;
    array.append(message);
    client_socket->write(array);
}

void StartWindow::slotDisconected(){

}
