#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H

#include <QWidget>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include "socketclient.h"


namespace Ui {
class Tab2SocketClient;
}

class Tab2SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2SocketClient(QWidget *parent = nullptr);
    ~Tab2SocketClient();

private:
    Ui::Tab2SocketClient *ui;
    SocketClient *pSocketClient;
    QString dlgLineStr;

private slots:
    void slotConnectToServer(bool);
    void slotSocketRecvUpdate(QString);
    void slotSocketSendData();
    void slotSocketSendData(QString);




signals:
    void sigSocketRecv(QString);
    void sigTab3RecvData(QString);
    void sigTab4RecvData(QString);
    void sigTab5RecvData(QString);
   void  sigTab6RecvData(QString);



};

#endif // TAB2SOCKETCLIENT_H
