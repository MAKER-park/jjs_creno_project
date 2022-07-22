#ifndef TAB2_CONNECTING_H
#define TAB2_CONNECTING_H

#include <QWidget>
#include <QMessageBox>
#include <QtDebug>
#include <QTime>

#include <QtNetwork>
#include <QTcpSocket>

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

private:
    Ui::tab2_connecting *ui;
    QTcpSocket *socket;//creat socket
    bool fd_flag = false;
    bool send_flag = false;
    int cnt = 0;

private slots:
    void slotConnectToServer();//connection
    bool connectToHost(QString host, QString port);//connection to server
    void disconToHost(); //disconnection to server
    bool send_test_Data(); //send test message
    void Recvice_Data();


//public slots:
//

//signals:
//    void sigSocketRecv(QString);
//    void sigTab3RecvData(QString);
//    void sigTab4RecvData(QString);
//    void sigTab5RecvData(QString);
//    void  sigTab6RecvData(QString);

};

#endif // TAB2_CONNECTING_H
