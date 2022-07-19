#include "tab2socketclient.h"
#include "ui_tab2socketclient.h"


Tab2SocketClient::Tab2SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2SocketClient)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    ui->pPBSendButton->setEnabled(false);
    connect(ui->pPBServerConnect,SIGNAL(clicked(bool)), this, SLOT(slotConnectToServer(bool)));
    connect(ui->pPBSendButton,SIGNAL(clicked()),this, SLOT(slotSocketSendData()));
    connect(pSocketClient, SIGNAL(sigSocketRecv(QString)), this, SLOT(slotSocketRecvUpdate(QString)));

    connect(ui->pPBRecvDataClear, SIGNAL(clicked()), ui->pTERecvData, SLOT(clear()));


}

Tab2SocketClient::~Tab2SocketClient()
{
    delete ui;
}
void Tab2SocketClient :: slotConnectToServer(bool check)
{
    bool bOK;
    if(check){
        pSocketClient->slotConnectToServer(bOK);
        if(bOK)
        {
            ui->pPBServerConnect->setText("서버해제");
            ui->pPBSendButton->setEnabled(true);
        }
    }
    else
    {
        pSocketClient->slotClosedByServer();
        ui->pPBServerConnect->setText("서버연결");
        ui->pPBSendButton->setEnabled(false);
    }
}
void Tab2SocketClient :: slotSocketRecvUpdate(QString strRecvData)
{
    //qDebug() << strRecvData;

    QTime time = QTime::currentTime();
    QString strtime = time.toString();
    //qDebug() << strtime;
    strRecvData.chop(1);

    if((strRecvData.indexOf("LAMP") != -1) || (strRecvData.indexOf("GAS") != -1))
    {
        emit sigTab3RecvData(strRecvData);
    }
    if((strRecvData.indexOf("SENSOR") != -1))
    {
        emit sigTab4RecvData(strRecvData);
        emit sigTab5RecvData(strRecvData);
        emit sigTab6RecvData(strRecvData);
    }

    strRecvData = strtime + " " + strRecvData;

    ui->pTERecvData->append(strRecvData);
    ui->pTERecvData->moveCursor(QTextCursor::End);

}

void Tab2SocketClient :: slotSocketSendData()
{
    QString strRecvId;
    QString strSendData;

    strRecvId = ui->pLERecvId->text();
    strSendData = ui->pLESendData->text();

    if(strRecvId.isEmpty())
        strSendData = "[ALLMSG]" + strSendData;
    else
        strSendData = "[" + strRecvId + "]" + strSendData;
    pSocketClient->slotSocketSendData(strSendData);
    ui->pLESendData->clear();
}

void Tab2SocketClient :: slotSocketSendData(QString strData)
{
    if(ui->pPBServerConnect->isChecked())
    {
        pSocketClient->slotSocketSendData(strData);
    }
    else
        QMessageBox::information(this,"socket", "서버 연결 확인");

}







