#include "signup.h"
#include "ui_signup.h"
#include "startwindow.h"
#include <QFile>
#include "QTextStream"
#include <QDebug>
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{
    QFile fileOut("C:/Users/Danila/Documents/lab1_2sem/base.txt");
    fileOut.open(QIODevice::Append | QIODevice::Text);
    if (!fileOut.isOpen())
    {
        qDebug("file not opened!");
    }
    else {
        QString login = ui->lineEdit_Login->text();
        QString password = ui->lineEdit_Password->text();
        QTextStream writeStream(&fileOut);
               writeStream << "\r\n"<< "login'" << login << "'password'" << password
                           << "'access'1'";
              fileOut.close();
        hide();
        StartWindow w;
        w.setModal(true);
        w.exec();
    }
}
