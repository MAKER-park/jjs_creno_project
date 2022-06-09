#include "tab2socketclient.h"
#include "ui_tab2socketclient.h"

Tab2SocketClient::Tab2SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2SocketClient)
{
    ui->setupUi(this);
    ui->pPB_SendButton->setEnabled(false);
    pSocketClient = new SocketClient(this);

    //connect
    connect(ui->pPB_ServerConnect,SIGNAL(clicked(bool)),this,SLOT(slotConnectToServer(bool)));

    //get ip addr
    connect(pSocketClient,SIGNAL(sigSocketRecv(QString)),this,SLOT(slotSocketRecvUpdate(QString)));

    //clear
    connect(ui->pPB_RecvDataClear,SIGNAL(clicked()),this,SLOT(clear()));

    //send
    connect(ui->pPB_SendButton,SIGNAL(clicked()),this,SLOT(slotSocketSendData()));
}

Tab2SocketClient::~Tab2SocketClient()
{
    delete ui;
}

//connection
void Tab2SocketClient::slotConnectToServer(bool check){
    bool bOk;
    if(check){
        pSocketClient->slotConnectToServer(bOk);
        if(bOk){
            ui->pPB_ServerConnect->setText("연결 해제");
            ui->pPB_SendButton->setEnabled(bOk);
        }
    }else{
        pSocketClient->slotClosedByServer();
        ui->pPB_ServerConnect->setText("서버 연결");
        ui->pPB_SendButton->setEnabled(false);
    }
}



void Tab2SocketClient::clear(){
    ui->pTE_RecvData->clear();
}

//get recive data
void Tab2SocketClient::slotSocketRecvUpdate(QString msg){
    QTime time = QTime::currentTime();
    QString str_time = time.toString();
//    qDebug() << str_time;
    msg.chop(1);

    if(msg.indexOf("LAMP") != -1 || msg.indexOf("GAS") != -1 ){//indexof 단어가 있으면 1 없으면 -1
       //tab2->tab3 ui changer
        emit sigTab3RecvData(msg);
    }

    if(msg.indexOf("SENSOR") != -1){
//       qDebug() << "ffff";
       //emit sigTab4RecvData
       emit sigTab4RecvData(msg);
    }

    msg = "["+str_time+"]"+msg;
    ui->pTE_RecvData->append(msg);
    ui->pTE_RecvData->moveCursor(QTextCursor::End);
}

////----------------22.06.09--------homework////




//send function
void Tab2SocketClient::slotSocketSendData(){
    QString strRecID,strSend;
    strRecID = ui->pLE_Recvid->text();
    strSend = ui->pLE_SendData->text();
    if(strRecID.isEmpty()){
        strSend = "[ALLMSG]" + strSend;
        pSocketClient->slotSocketSendData(strSend);
        ui->pLE_SendData->clear();
    }else{
        strSend = "["+strRecID+"]"+strSend;
        pSocketClient->slotSocketSendData(strSend);
        ui->pLE_SendData->clear();
    }
}

//send function2
void Tab2SocketClient::slotSocketSendData(QString command){
    if(ui->pPB_ServerConnect->isChecked()){
         pSocketClient->slotSocketSendData(command);
    }else{
        QMessageBox::information(this,"socket","서버 연결 확인");
    }
}

