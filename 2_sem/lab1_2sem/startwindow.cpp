#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include "QDebug"
#include <QFile>
#include <QMessageBox>
StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}
int StartWindow::Authorize(QString password, QString login)
{
 QFile fileIn;
 fileIn.setFileName("C:/Users/Danila/Documents/lab1_2sem/base.txt");
 if(fileIn.open(QIODevice::ReadOnly))
 {
     while(!fileIn.atEnd())
     {
     QString temp = fileIn.readLine();

     if (temp.contains("'"+password+"'") && temp.contains("'"+login+"'"))
     {
        if (temp.contains("access'1'"))
            fileIn.close();
            return 1;
        if (temp.contains("access'2'"))
              fileIn.close();
            return 2;
        if (temp.contains("access'3'"))
              fileIn.close();
            return 3;
     }
     }
}
   fileIn.close();
 return 0;
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
    QMessageBox msg;
  switch(Authorize(password,login))
  {
  case 0:
 msg.setText("Error");
 msg.exec();
      break;
  case 1:
      msg.setText("User");
      msg.exec();
      break;
  case 2:
      msg.setText("Manager");
      msg.exec();
      break;
  case 3:
      msg.setText("Admin");
      msg.exec();
      break;
  }
}
