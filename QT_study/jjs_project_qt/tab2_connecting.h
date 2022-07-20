#ifndef TAB2_CONNECTING_H
#define TAB2_CONNECTING_H

#include <QWidget>
#include "socketclient.h"
#include <QMessageBox>
#include <QtDebug>
#include <QTime>

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
    SocketClient* pSocketClient;

private slots:
    void slotConnectToServer(bool);//connection
    void slotSocketRecvUpdate(QString);
//    void slotSocketSendData();
//    void slotSocketSendData(QString);
};

#endif // TAB2_CONNECTING_H
