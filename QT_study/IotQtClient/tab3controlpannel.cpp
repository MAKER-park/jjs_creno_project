#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

tab3ControlPannel::tab3ControlPannel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab3ControlPannel)
{
    ui->setupUi(this);
    connect(ui->pPB_Light,SIGNAL(clicked(bool)),this,SLOT(slotLightToggle(bool)));
    connect(ui->pPB_Plug,SIGNAL(clicked(bool)),this,SLOT(slotPlugToggle(bool)));
}

tab3ControlPannel::~tab3ControlPannel()
{
    delete ui;
}

void tab3ControlPannel::slotLightToggle(bool state){
    qDebug()<<state;
    if(state){
        //light state = on -> off
        //ui->pPB_Light->setChecked(false);
        emit sigSoketSendData("[19]LAMPON");//send command
    }else{
        //light state = off -> on
        //ui->pPB_Light->setChecked(true);
        emit sigSoketSendData("[19]LAMPOFF");//send command
    }
}

void tab3ControlPannel::slotPlugToggle(bool state){

    if(state){
        //plug state = on -> off
        //ui->pPB_Plug->setChecked(false);
        emit sigSoketSendData("[19]GASON");//send command
    }else{
        //plug state = off -> on
        //ui->pPB_Plug->setChecked(true);
        emit sigSoketSendData("[19]GASOFF");//send command
    }
}

void tab3ControlPannel::slotTab3RecvData(QString Recv_Data){
    QIcon icon;
    //QMessageBox::information(this,"socket",Recv_Data);
    Recv_Data.replace("[","@");//문자 치환
    Recv_Data.replace("]","@");//문자 치환
    QStringList qlist = Recv_Data.split("@");//문자 자르기 @12@13 -> (12,13)
    qDebug() << "qlist : " << qlist[2];
    if(qlist[2] == "LAMPON"){
        //ui->pPB_Light->setCheckable(true);
        icon.addFile(":/IotQtClient/Image/light_on.png");
        //:/IotQtClient/Image/light_on.png
    }else if(qlist[2] == "LAMPOFF"){
        //ui->pPB_Light->setCheckable(false);
        icon.addFile(":/IotQtClient/Image/light_off.png");
    }

    if(qlist[2] == "GASON"){
        //ui->pPB_Plug->setCheckable(true);
        icon.addFile(":/IotQtClient/Image/plug_on.png");
    }else if(qlist[2] == "GASOFF"){
        //ui->pPB_Plug->setCheckable(false);
        icon.addFile(":/IotQtClient/Image/plug_off.png");
    }
}
