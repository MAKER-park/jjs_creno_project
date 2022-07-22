#include "qsocket.h"
#include <QDebug>
#define Kor(str)  QString::fromLocal8Bit(str)



qsocket::qsocket()
{
    socket = new QTcpSocket();
    connect(socket, SIGNAL(readyRead()), this, SLOT(Recvice_Data()));
}

void qsocket::Recvice_Data(){//recvie data
    msg_data = QString::fromUtf8(socket->readLine());
    if(!socket->canReadLine()){
        msg_data = msg_data.left(msg_data.length());
//        qDebug()<<"server : " << msg_data << "\n";
        emit sigSocketRecv(msg_data);
    }
}

bool qsocket::SlotConnectToServer(){
}



bool qsocket::ConnectToHost(QString HOST_IP, QString HOST_PORT ){
    socket->connectToHost(HOST_IP,HOST_PORT.toInt());
    return socket->waitForConnected();
}

bool qsocket::DisconToHost(){
    socket->disconnectFromHost();
    bool result = socket->waitForDisconnected();
    return result;
}


void qsocket::Send_test_Data(QString msg){

    if(socket->state() == QAbstractSocket::ConnectedState){//check connection! & test data send
        socket->write(msg.toUtf8());
    }else{
        QMessageBox msg_box;
        msg_box.setInformativeText("check your connection");
    }
}
