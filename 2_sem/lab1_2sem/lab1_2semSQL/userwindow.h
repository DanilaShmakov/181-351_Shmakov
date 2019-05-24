#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QDialog>
//#include <QList>
#include <QStandardItemModel>
#include "server.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QDialog
{
    Q_OBJECT
public:

    explicit UserWindow(QWidget *parent = nullptr);
    QStandardItemModel *tableDB;
    datas datasuser;

    void drawTable(QList<QByteArray>);
    void ShowInfo(int, QString, QString);
    datas LoadFromForm();
    ~UserWindow();
signals:
 //void toSWindow();
public slots:
    void slotConnected();
    void slotReadyRead();
    void slotSendToServer(QString);
    void slotDisconected();

    void toUserWindow(QString, QString);

     void on_pushButtonChange_clicked();

     void on_pushButton_reload_clicked();

     void on_pushButtonAdd_clicked();

     void on_pushButtonDel_clicked();

private:
    void parsing(QByteArray recieved_array);

    Ui::UserWindow *ui;
    UserWindow *uWindow;
    QByteArray answerArray;
    QString userlog;
    QString userpass;
    QTcpSocket *client_socket;
};

#endif // USERWINDOW_H
