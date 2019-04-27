#include "mainwindow.h"
#include "database.h"
#include "startwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sWindow = new StartWindow();
    //подключаем к слоту запуска главного окна по кнопке в окне авторизации
    connect (sWindow,&StartWindow::SWindow, this, &MainWindow::show);
    SignUpWindow = new SignUp();
    //подключаем к слоту запуска главного окна по кнопке в окне авторизации
    connect (SignUpWindow,&SignUp::FirstWindow, this, &MainWindow::show);
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
    SignUpWindow->show();
    this->close();
}
