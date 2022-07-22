#ifndef QSOCKET_H
#define QSOCKET_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QInputDialog>
#include <QMessageBox>

class qsocket
{
public:
    qsocket();

private:
    QTcpSocket *socket;//creat socket
    bool fd_flag = false;
    bool send_flag = false;
    int cnt = 0, SERV;
    QString IP = "112.145.215.121";
    QString PORT = "9092";

private slots:
    void slotConnectToServer();//connection
    bool connectToHost(QString host, QString port);//connection to server
    void disconToHost(); //disconnection to server
    bool send_test_Data(); //send test message
    void Recvice_Data();//recvie message
};



#endif // QSOCKET_H
