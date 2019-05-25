#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include "userwindow.h"
//#include "server.h"
StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)

{
    qDebug()<<"StartWindow constr";
    ui->setupUi(this);
}


StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pB_Authorize_clicked()
{
    QString password = ui->lineEdit_password->text();
    QString login = ui->lineEdit_login->text();
    uWindow = new UserWindow();
    // connect (uWindow,&UserWindow::toSWindow, this, &StartWindow::show);
    //connect(this,&StartWindow::toUWindow, uWindow, &UserWindow::toUserWindow);
    emit uWindow->toUserWindow(login, password);
    this->close();

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

/*void StartWindow::on_pushButton_Home_clicked(){
   emit toMWindow(mydbstart);
   this->close();
}
*/


