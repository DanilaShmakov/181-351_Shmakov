#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include "database.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QDialog
{
    Q_OBJECT
public slots:
    //  void writeAccess(int a);
public:
    //  int sc_Access;
    QStandardItemModel *tableDB;
    void drawTable();
    void ShowInfo(int, QString, QString);
    explicit UserWindow(QWidget *parent = nullptr);
    datas LoadFromForm();
    ~UserWindow();
signals:
     void userWindow();
private slots:
     void on_pushButtonChange_clicked();

     void on_pushButton_reload_clicked();

     void on_pushButtonAdd_clicked();

     void on_pushButtonDel_clicked();

private:
    Ui::UserWindow *ui;
    UserWindow *uWindow;

};

#endif // USERWINDOW_H
