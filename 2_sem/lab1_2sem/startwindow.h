#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_pushButton_SignUp_clicked();

    void on_pB_Authorize_clicked();
    int Authorize(QString password, QString login);

private:
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
