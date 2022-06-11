#include "tab4sensordisplay.h"
#include "ui_tab4sensordisplay.h"

tab4SensorDisplay::tab4SensorDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab4SensorDisplay)
{
    ui->setupUi(this);
}

tab4SensorDisplay::~tab4SensorDisplay()
{
    delete ui;
}

void tab4SensorDisplay::slotTab4RecvData(QString msg){
        msg.replace("[","@");//문자 치환
        msg.replace("]","@");//문자 치환
        QStringList qlist = msg.split("@");//문자 자르기 @12@13 -> (12,13)
//        qDebug()<<qlist[3];//lux
//        qDebug()<<qlist[4];//tmp
//        qDebug()<<qlist[5];//hum

        //init
//        ui->pLB_LUX->clear();
//        ui->pLB_TEMP->clear();
//        ui->pLB_HUM->clear();

        //input data
        ui->pLB_LUX->setText(qlist[3]+" lux");
        ui->pLB_TEMP->setText(qlist[4]+" °C");
        ui->pLB_HUM->setText(qlist[5]+" %");
}
