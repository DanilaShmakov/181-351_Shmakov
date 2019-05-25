#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "startwindow.h"
#include "signup.h"
#include "userwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Authorize_clicked();


signals:

private:
    Ui::MainWindow *ui;
    StartWindow *sWindow;


};

#endif // MAINWINDOW_H
