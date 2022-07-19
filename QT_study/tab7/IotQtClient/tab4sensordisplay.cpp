#include "tab4sensordisplay.h"
#include "ui_tab4sensordisplay.h"

Tab4SensorDisplay::Tab4SensorDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab4SensorDisplay)
{
    ui->setupUi(this);


}

Tab4SensorDisplay::~Tab4SensorDisplay()
{
    delete ui;
}
void Tab4SensorDisplay:: slotTab4RecvData(QString strRecvData)
{
    //qDebug() << strRecvData;
    QStringList qlist = strRecvData.split("@");
    //qDebug() << qlist[1];
    //QString Photo;
    //QString Temp;
    //QString Humi;
    //Photo = qlist[1] + "%";
    //Temp = qlist[2] + "°C";
    //Humi = qlist[3] + "%";

    ui->pTEPhoto->setText(qlist[1] + "%");
    ui->pTETemp->setText(qlist[2] + "°C");
    ui->pTEHumi->setText(qlist[3] + "%");

}
