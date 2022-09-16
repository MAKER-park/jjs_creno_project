#include "tab2_connecting.h"
#include "ui_tab2_connecting.h"

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
    //(7,"2,0,1","1,0,1","2,1,1","1,1,1","2,0,2","1,0,2","2,1,2","1,1,2")
    //0,1,1->insert
    //0,0,1->remove(DELETE FROM `smart_crane` WHERE ID = 'BICU6789012')
    POS_REF.append("2,0,1");
    POS_REF.append("1,0,1");
    POS_REF.append("2,1,1");
    POS_REF.append("1,1,1");
    POS_REF.append("2,0,2");
    POS_REF.append("1,0,2");
    POS_REF.append("2,1,2");
    POS_REF.append("1,1,2");
    POS_COUNTER = 0;
}

tab2_connecting::~tab2_connecting()
{
    delete ui;
}

//recive data
void tab2_connecting::recvice_Data(QString msg){
    ui->plog_console->insertPlainText("server : "+msg+"\n");
//    pqsocket->Recvice_Data();
    if((msg.indexOf("running") != -1))//get data respon! tab1 move button after
    {
        qDebug()<<"get command!\n";
        emit sendRespone(msg);
    }else if((msg.indexOf("complete")) != -1){
        qDebug()<<"done command!\n";
        emit sendRespone(msg);
    }//[QR] BICU1234567
    else if((msg.indexOf("<QR>")) != -1){
        qDebug()<<"get QR " << msg;
        QR_INFO = msg.mid(9,11);//WORKING!
        qDebug()<<"QR : " << QR_INFO;
        //<QR_DB> BICU6789012 2,0,1
        qDebug()<<"[1] <QR_DB> "+QR_INFO+" "+POS_REF[POS_COUNTER];
//        pqsocket->Send_test_Data("[1] move 0,1,1,"+POS_REF[POS_COUNTER]+"\n");

        qDebug()<<"QMAP_INSERT";
        QR_MAP[QR_INFO] = POS_REF[POS_COUNTER];
        //pqsocket->Send_test_Data("[1] move 0,1,1,"+POS_REF[POS_COUNTER]+"\n");

        qDebug()<<"QMAP_CHECK";
        QMapIterator<QString, QString> i(QR_MAP);
        while (i.hasNext()) {
            i.next();
            qDebug() << i.key() << ": " << i.value();
        }

        qDebug()<<"send data";
        pqsocket->Send_test_Data("[1] <QR_DB> "+QR_INFO+" "+POS_REF[POS_COUNTER]+"\n");
//        pqsocket->Send_test_Data("[1] move 0,1,1,"+POS_REF[POS_COUNTER]+"\n");
//        pqsocket->Recvice_Data();


    }else if(msg.indexOf("DB_OK") != -1){//db respon!
        //send move commend!
        pqsocket->Send_test_Data("[1] move 0,1,1,"+POS_REF[POS_COUNTER]+"\n");
        POS_COUNTER++;
        if(POS_COUNTER == 7){
            POS_COUNTER = 0;
        }
        qDebug()<<"COUNTER = " << POS_COUNTER;
    }else if(msg.indexOf("danger")){
        //if you get danger
        qDebug()<<"get danger!\n";
        emit sendRespone(msg);
    }else if(msg.indexOf("safe")){
        //if you get safe
        qDebug()<<"get safe!\n";
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
    pqsocket->Send_test_Data("hello!!\n");
}

//realsend
void tab2_connecting::send_Data(QString msg){
    qDebug()<<"send data" << msg;

    //find value to key
    QString QR_INFO,QR_POS_START,QR_POS_END ;
    qDebug() << "msg_start_pos : " << msg.mid(9,5) << " msg_end_pos : " << msg.mid(15,5);
    QR_POS_START = msg.mid(9,5);
    QR_POS_END = msg.mid(15,5);
    //change
    qDebug() << "change!!";
    QMapIterator<QString, QString> index(QR_MAP);
    while (index.hasNext()) {
        index.next();
        if(index.value().compare(QR_POS_START) == 0){//if find your QR_POS?
            qDebug() << "find QR!" << index.key();
            QR_INFO = index.key();
            QR_MAP[QR_INFO] = QR_POS_END;//change value!
            //and send update pos!
            pqsocket->Send_test_Data("[1] <QR_DB> "+QR_INFO+" "+ QR_POS_END+"\n");
        }
    }

    QMapIterator<QString, QString> index2(QR_MAP);
    qDebug() << "change map check";
    while (index2.hasNext()) {
        index2.next();
        qDebug() << index2.key() << ": " << index2.value();
    }

    pqsocket->Send_test_Data(msg);
}
