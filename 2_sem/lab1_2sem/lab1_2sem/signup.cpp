#include "signup.h"
#include "ui_signup.h"
#include "startwindow.h"
#include <QFile>
#include "QTextStream"
#include <QDebug>
#include <iostream>
#include <QMessageBox>
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    sWindow = new StartWindow();
    //подключаем к слоту запуска главного окна по кнопке в окне авторизации
     connect (sWindow,&StartWindow::SWindow, this, &SignUp::show);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{
    QFile fileOut("C:/Users/Danila/Documents/2_sem/lab1_2sem/base.txt");
    fileOut.open(QIODevice::Append | QIODevice::Text);
    if (!fileOut.isOpen())
    {
        qDebug("file not opened!");
    }
    else {
        QString login = ui->lineEdit_Login->text();
        QString password = ui->lineEdit_Password->text();
        if ((login == "") || (password == ""))
        {
           QMessageBox::critical(0,"Warning", "empty data");
        }
        else if (login.contains("'" ) || password.contains("'") || login.contains(" " ) || password.contains(" "))
        {
           QMessageBox::critical(0,"Warning", "prohibited symbols");
        }
        else{
        QTextStream writeStream(&fileOut);
              writeStream << "\r\n"<< "login'" << login << "'password'" << password
                          << "'access'1'";
              fileOut.close();
              sWindow->show();
              this->close();
      }
      }
}
