#include "tab2_connecting.h"
#include "ui_tab2_connecting.h"

tab2_connecting::tab2_connecting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab2_connecting)
{
    ui->setupUi(this);
    connect(ui->pB_connect,SIGNAL(clicked(bool)),this,SLOT(slotConnectToServer(bool)));
}

tab2_connecting::~tab2_connecting()
{
    delete ui;

}

//connection button click
void tab2_connecting::slotConnectToServer(bool check){
    qDebug("click!!");
    bool bOk;
    if(check){
        pSocketClient->slotConnectToServer(bOk);
        if(bOk){
            ui->pB_connect->setText("연결 해제");
            ui->pB_close->setEnabled(bOk);
        }
    }else{
//        pSocketClient->slotClosedByServer();
        ui->pB_connect->setText("서버 연결");
    }
}

