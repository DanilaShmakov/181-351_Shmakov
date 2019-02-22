#include "mainwindow.h"
#include "startwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Danila/Documents/lab1_2sem/images/parrot.jpg");
    int w = ui->Pix_Parrot->width();
    int h = ui->Pix_Parrot->height();
    ui->Pix_Parrot->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Authorize_clicked()
{
    hide();
    StartWindow w;
    w.setModal(true);
    w.exec();
}

void MainWindow::on_pushButton_SignUP_clicked()
{
    hide();
    SignUp w;
    w.setModal(true);
    w.exec();
}
