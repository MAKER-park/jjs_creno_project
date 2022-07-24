#include "tab2_connecting.h"
#include "ui_tab2_connecting.h"

static inline QByteArray IntToArray(qint32 source);

tab2_connecting::tab2_connecting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab2_connecting)
{
    ui->setupUi(this);
    pqsocket = new qsocket();
    ui->pLE_IP->setText(pqsocket->IP);
    ui->pLE_PORT->setText(pqsocket->PORT);
    ui->pB_close->setEnabled(false);
    ui->pB_connect->setEnabled(true);
    connect(ui->pB_connect,SIGNAL(clicked(bool)),this,SLOT(slotConnectToServer()));//connect
    connect(ui->pB_close, SIGNAL(clicked(bool)),this, SLOT(disconToHost()));//disconnect
    connect(ui->pPB_TEST, SIGNAL(clicked(bool)),this,SLOT(send_test_Data()));//testsend


    connect(pqsocket,SIGNAL(sigSocketRecv(QString)),this,SLOT(recvice_Data(QString)));//get pqsocket->tab2
}

tab2_connecting::~tab2_connecting()
{
    delete ui;
}

//recive data
void tab2_connecting::recvice_Data(QString msg){
    ui->plog_console->insertPlainText("server : "+msg+"\n");
//    pqsocket->Recvice_Data();
    if((msg.indexOf("ok") != -1))//get data respon! tab1 move button after
    {
        qDebug()<<"get command!\n";
        emit sendRespone(msg);
    }else if((msg.indexOf("compelete")) != -1){
        qDebug()<<"done command!\n";
        emit sendRespone(msg);
    }

}

//connection button click
void tab2_connecting::slotConnectToServer(){
    bool result;
    QMessageBox msgBox;
    msgBox.setWindowTitle("서버 연결 확인");
    msgBox.setText("IP : "+ui->pLE_IP->text()+" PORT : "+ui->pLE_PORT->text()+"에 연결 하시겠습니까?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if(msgBox.exec() == QMessageBox::Yes){
      // server connection try!
        QString IP = ui->pLE_IP->text();
        QString PORT = ui->pLE_PORT->text();
        qDebug()<< "IP : " << IP.toUtf8().constData();
        qDebug()<< "PORT : " << PORT.toUtf8().constData();
        result = pqsocket->ConnectToHost(IP.toUtf8().constData(), PORT.toUtf8().constData());

        if(!result){
            //connect fail!
            ui->plog_console->insertPlainText("Socket connect fail\n");
            ui->pB_close->setEnabled(!fd_flag);
            ui->pB_connect->setEnabled(fd_flag);
        }else{
            ui->plog_console->insertPlainText("Socket connect sucees!!\n");
//            pqsocket->Recvice_Data();
            ui->pB_close->setEnabled(!fd_flag);
            ui->pB_connect->setEnabled(fd_flag);
            emit sigsend_IP(IP);
        }
    }else {
      // do something else
    }
}

bool tab2_connecting::connectToHost(QString host, QString port)
{
    //server connection!
//    socket->connectToHost(host, port.toInt()); // ip address, port
//    return socket->waitForConnected();
}
//server disconnection!
void tab2_connecting::disconToHost(){
    bool result = pqsocket->DisconToHost();
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
    pqsocket->Send_test_Data("[1] move#2,1#1,1\n");
}

//realsend
void tab2_connecting::send_Data(QString msg){
    pqsocket->Send_test_Data(msg);
}
