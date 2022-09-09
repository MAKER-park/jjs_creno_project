#ifndef QSOCKET_H
#define QSOCKET_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>

#include <QWidget>
#include <QMessageBox>
#include <QTime>

#include <QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>
#include <QInputDialog>
#include <QMessageBox>

class qsocket: public QWidget
{
    Q_OBJECT

public:
    qsocket();
    QString IP = "cloud.park-cloud.co19.kr";
    QString PORT = "5040";
    QString msg_data;

private:
    QTcpSocket *socket;//creat socket


public slots:
//    bool SlotConnectToServer();
    bool ConnectToHost(QString host, QString port);//connection to server
    bool DisconToHost(); //disconnection to server
    void Send_test_Data(QString); //send test message
    void Recvice_Data();//recvie message

signals:
    void sigSocketRecv(QString);



};

#endif // QSOCKET_H
