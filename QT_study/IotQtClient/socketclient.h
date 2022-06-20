#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

/* kccistc embedded & iot by ksh */

#include <QTcpSocket>
#include <QHostAddress>
#include <QInputDialog>
#include <QMessageBox>

#define BLOCK_SIZE      1024
class SocketClient : public QWidget
{
	Q_OBJECT

private:
    QTcpSocket *pQTcpSocket;
    QString SERVERIP = "cloud.park-cloud.co19.kr";
    int SERVERPOT = 9001;
    QString LOGID = "21";
    QString LOGPW = "PASSWD";
//    QString LOGID = "";
//    QString LOGPW = "";
public:
	SocketClient(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~SocketClient();

signals:
    void sigSocketRecv(QString);

private slots:
	void slotSocketReadData();
	void slotSocketError();
	void slotConnectServer();

public slots:
    void slotConnectToServer(bool&);
    void slotClosedByServer();
    void slotSocketSendData(QString);
};

#endif // SOCKETCLIENT_H
