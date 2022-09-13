#ifndef TAB2_CONNECTING_H
#define TAB2_CONNECTING_H

#include <QWidget>
#include <QMessageBox>
#include <QtDebug>
#include <QTime>
#include <QMap>

#include <QtNetwork>
#include <QTcpSocket>

#include "qsocket.h"

namespace Ui {
class tab2_connecting;
}

class tab2_connecting : public QWidget
{
    Q_OBJECT

public:
    explicit tab2_connecting(QWidget *parent = nullptr);
    ~tab2_connecting();
    QString dlgLineStr;
    qsocket *pqsocket;

private:
    Ui::tab2_connecting *ui;
//    QTcpSocket *socket;//creat socket
    bool fd_flag = false;
    bool send_flag = false;
    int cnt = 0;

private slots:
    void slotConnectToServer();//connection
    bool connectToHost(QString host, QString port);//connection to server
    void disconToHost(); //disconnection to server
    bool send_test_Data(); //send test message

    void send_Data(QString);

    void recvice_Data(QString);//get recive data

//public slots:
//

signals: //send variable or funcution!
    void sendRespone(QString);//commend respon send to tab1

    void sigsend_IP(QString);//send IP for stream
};

#endif // TAB2_CONNECTING_H
