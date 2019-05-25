#include "signup.h"
#include "mainwindow.h"
#include "ui_signup.h"
//#include "startwindow.h"
#include <QFile>
#include "QTextStream"
#include <QDebug>
#include <QMessageBox>
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
       qDebug()<<"SignUP constr";
       //mydbsignup = new DataBase;
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{ /*
        QString login = ui->lineEdit_Login->text();
        QString password = ui->lineEdit_Password->text();
        if ((login == "") || (password == "")){
           QMessageBox::critical(0,"Warning", "Empty Data");
        } else {
        /*    DataBase a;
            if(a.SigningUp(login,password)){
                 }
      } */
}

void SignUp::on_pushButton_Home_clicked(){
  //  emit toMWindow();
    this->close();
}
