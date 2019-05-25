#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "server.h"
//#include "startwindow.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

public slots:

private slots:
    void on_pushButton_clicked();
    void on_pushButton_Home_clicked();


signals:
    void toMWindow();
private:
    Ui::SignUp *ui;

};

#endif // SIGNUP_H
