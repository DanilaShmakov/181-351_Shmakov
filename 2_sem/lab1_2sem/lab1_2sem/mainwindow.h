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

    void on_pushButton_SignUP_clicked();

private:
    Ui::MainWindow *ui;
    StartWindow *sWindow;
    SignUp *SignUpWindow;
};

#endif // MAINWINDOW_H
