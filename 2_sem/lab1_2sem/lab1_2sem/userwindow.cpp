#include "userwindow.h"
#include "ui_userwindow.h"
#include "startwindow.h"
#include "database.h"

UserWindow::UserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserWindow)
{
 ui->setupUi(this);
}
void UserWindow::drawTable(){
    tableDB = new QStandardItemModel(3, 6, this);
    QStandardItem  *item;
    ui->tableDB->setModel(tableDB);
    tableDB->setHeaderData(0, Qt::Horizontal, "ID");
    tableDB->setHeaderData(1, Qt::Horizontal, "FIO");
    tableDB->setHeaderData(2, Qt::Horizontal, "Type");
    tableDB->setHeaderData(3, Qt::Horizontal, "Price");
    tableDB->setHeaderData(4, Qt::Horizontal, "Quantity");
    tableDB->setHeaderData(5, Qt::Horizontal, "Date");

            QFile fileIn;
            datas ab;
            DataBase a;
            int i = 0;
            fileIn.setFileName("C:/Users/Danila/Documents/2_sem/lab1_2sem/bd.txt");
            if(fileIn.open(QIODevice::ReadOnly | QIODevice::WriteOnly ))
            {
                QString stf;
                std::string strFromFile;
                while (!fileIn.atEnd()) {
                    stf = fileIn.readLine();
                    strFromFile = stf.toStdString();
                    ab = a.transformStr2BD(strFromFile);
                {
                    item = new QStandardItem(QString::fromStdString(ab.ID));
                    tableDB->setItem(i, 0, item);
                    item = new QStandardItem(QString::fromStdString(ab.fio));
                    tableDB->setItem(i, 1, item);
                    item = new QStandardItem(QString::fromStdString(ab.type));
                    tableDB->setItem(i, 2, item);
                    item = new QStandardItem(QString::fromStdString(ab.price));
                    tableDB->setItem(i, 3, item);
                    item = new QStandardItem(QString::fromStdString(ab.count));
                    tableDB->setItem(i, 4, item);
                    item = new QStandardItem(QString::fromStdString(ab.date));
                    tableDB->setItem(i, 5, item);
                    i++;

                }
         }
    }
}

void UserWindow::ShowInfo(int sc_Access, QString password, QString login){
    if (sc_Access == 1)
    {
        ui->LabelAccessRight->setText( "User");
        ui->LabelLogin->setText(login);
        ui->LabelPassword->setText(password);
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

datas UserWindow::LoadFromForm(){
    datas a;
    a.ID    = ui->lineEdit_id->text().toStdString();
    a.fio   = ui->lineEdit_fio->text().toStdString();
    a.date  = ui->lineEdit_date->text().toStdString();
    a.type  = ui->lineEdit_type->text().toStdString();
    a.count = ui->lineEdit_count->text().toStdString();
    a.price = ui->lineEdit_price->text().toStdString();
    return a;
}
void UserWindow::on_pushButtonChange_clicked(){
   DataBase a;
   a.change(LoadFromForm());
}

void UserWindow::on_pushButton_reload_clicked(){
    drawTable();
}

void UserWindow::on_pushButtonAdd_clicked(){
    DataBase a;
    a.add_data(LoadFromForm());
}

void UserWindow::on_pushButtonDel_clicked(){
    DataBase a;
    a.del_data(ui->lineEdit_id->text().toStdString());
}
