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
    QString SERVERIP = "112.145.215.121";
    int SERVERPOT = 9092;
    QString LOGID = "15";
    QString LOGPW = "PASSWD";
public:
	SocketClient(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~SocketClient();

signals:
    void sigSocketRecv(QString);
    void sigSocketRecvData(QString);

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
