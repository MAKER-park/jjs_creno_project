#include "tab2_connecting.h"
#include "ui_tab2_connecting.h"

static inline QByteArray IntToArray(qint32 source);

tab2_connecting::tab2_connecting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab2_connecting)
{
    ui->setupUi(this);
    ui->pLE_IP->setText("10.10.141.250");
    ui->pLE_PORT->setText("5040");
    ui->pB_close->setEnabled(false);
    ui->pB_connect->setEnabled(true);
    connect(ui->pB_connect,SIGNAL(clicked(bool)),this,SLOT(slotConnectToServer()));//connect
    connect(ui->pB_close, SIGNAL(clicked(bool)),this, SLOT(disconToHost()));//disconnect
    connect(ui->pPB_TEST, SIGNAL(clicked(bool)),this,SLOT(send_test_Data()));//testsend
}

tab2_connecting::~tab2_connecting()
{
    delete ui;
    delete socket;

}

//recive data
void tab2_connecting::Recvice_Data(){
//    qDebug()<<"something recv! hello!! \n";
    if(!socket->canReadLine()){
        QString Recv_Data= QString::fromUtf8(socket->readLine());
        Recv_Data = Recv_Data.left(Recv_Data.length());
        ui->plog_console->insertPlainText("server : " + Recv_Data + "\n");
    }
}

//connection button click
void tab2_connecting::slotConnectToServer(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("서버 연결 확인");
    msgBox.setText("서버 연결 할거?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if(msgBox.exec() == QMessageBox::Yes){
      // server connection try!
        QString IP = ui->pLE_IP->text();
        QString PORT = ui->pLE_PORT->text();
        qDebug()<< "IP : " << IP.toUtf8().constData();
        qDebug()<< "PORT : " << PORT.toUtf8().constData();
        socket = new QTcpSocket(this);
        connect(socket, SIGNAL(readyRead()),this,SLOT(Recvice_Data()));//recv_data;
        fd_flag = connectToHost(ui->pLE_IP->text().toUtf8().constData(), ui->pLE_PORT->text().toUtf8().constData());//server info send
        if(!fd_flag){
            //connect fail!
            ui->plog_console->insertPlainText("Socket connect fail\n");
            ui->pB_close->setEnabled(fd_flag);
            ui->pB_connect->setEnabled(!fd_flag);
        }else{
            ui->plog_console->insertPlainText("Socket connect sucees!!\n");
            ui->pB_close->setEnabled(fd_flag);
            ui->pB_connect->setEnabled(!fd_flag);
        }
    }else {
      // do something else
    }
}

bool tab2_connecting::connectToHost(QString host, QString port)
{
    //server connection!
    socket->connectToHost(host, port.toInt()); // ip address, port
    return socket->waitForConnected();
}
//server disconnection!
void tab2_connecting::disconToHost(){
    socket->disconnectFromHost();
    bool result = socket->waitForDisconnected();
    if(result){
        ui->plog_console->insertPlainText("something error occur!\n");
    }else{//result = false
        ui->plog_console->clear();
        ui->pB_close->setEnabled(result);
        ui->pB_connect->setEnabled(!result);
    }
}


//send test data!
bool tab2_connecting::send_test_Data(){
    if(socket->state() == QAbstractSocket::ConnectedState){//check connection! & test data send
        socket->write(QString("move#1#2#3\n").toUtf8());
        ui->plog_console->insertPlainText("test send : move#1#2#3\n");
    }else{
        ui->plog_console->insertPlainText("check! your server connection!\n");
    }
}



