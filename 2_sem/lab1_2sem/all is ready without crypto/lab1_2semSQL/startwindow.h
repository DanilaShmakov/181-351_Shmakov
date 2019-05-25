#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <QTcpSocket>
#include "userwindow.h"
namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
public slots:
       // void toUserWindow(QString, QString);

private slots:

    void on_pB_Authorize_clicked();

    void on_radioButton_Eye_clicked();

   // void on_pushButton_Home_clicked();

signals:
    void toUWindow(QString, QString);
private:
    Ui::StartWindow *ui;
    Server *mydbstart;
    UserWindow *uWindow;
};
#endif // STARTWINDOW_H
