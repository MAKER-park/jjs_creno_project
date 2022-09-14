#ifndef TAB2_CONNECTING_H
#define TAB2_CONNECTING_H

#include <QWidget>
#include <QMessageBox>
#include <QtDebug>
#include <QTime>
#include <QMap>
#include <QVector>

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
    /*
     [2] <QR> BICU1234561 2,0,1
    [2] <QR> BICU7891012  1,0,1
    [2] <QR> AICR2345673  2,1,1
    [2] <QR> AICU8901234  1,1,1
    [2] <QR> AICU4567895  2,0,2
    [2] <QR> BICU0123456  1,0,2
    [2] <QR> BICU6789017  2,1,2
    [2] <QR> DICU2345678  1,1,2
     */
    QString QR_INFO;
    QMap<QString, QString> QR_MAP;
    QVector<QString> POS_REF;
    int POS_COUNTER = 0;

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
