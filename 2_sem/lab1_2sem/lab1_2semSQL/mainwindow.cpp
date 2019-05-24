#include "mainwindow.h"
//#include "server.h"
#include "startwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"MainWindow constr";
    sWindow = new StartWindow();
    //подключаем к слоту запуска главного окна по кнопке в окне авторизации
    SignUp *SignUpWindow;
    SignUpWindow = new SignUp();
    //подключаем к слоту запуска главного окна по кнопке в окне авторизации
    connect (this,&MainWindow::toSignUpWindow, SignUpWindow, &SignUp::show);
   // connect (SignUpWindow,&SignUp::toMWindow, this, &MainWindow::showMainWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// переход к окну авторизации
void MainWindow::on_pushButton_Authorize_clicked()
{
  sWindow->show();
  this->close();
}

//переход окну регистрации
void MainWindow::on_pushButton_SignUP_clicked()
{
   emit toSignUpWindow();
   this->close();
}
