#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "startwindow.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_clicked();
signals:
    void FirstWindow();
private:
    Ui::SignUp *ui;
    StartWindow *sWindow;
};

#endif // SIGNUP_H
