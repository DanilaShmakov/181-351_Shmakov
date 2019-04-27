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

private slots:
    void on_pushButton_SignUp_clicked();

    void on_pB_Authorize_clicked();

    void on_radioButton_Eye_clicked();

    void on_pushButton_Home_clicked();

    void slotConnected();
    void slotReadyRead();
    void slotSendToServer(QString);
    void slotDisconected();
signals:
    void SWindow();
 //   void setAccess(int);
private:
    Ui::StartWindow *ui;
    UserWindow *uWindow;
    QTcpSocket *client_socket;
};
#endif // STARTWINDOW_H
