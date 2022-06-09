#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QApplication>
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(3);// 2:tab3 open

    //set tab4 ui connect
    ptab4Sensordisplay = new tab4SensorDisplay(ui->pTab4);
    ui->pTab4->setLayout(ptab4Sensordisplay->layout());

    //set tab3 ui connect
    ptab3ControlPannel = new tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(ptab3ControlPannel->layout());

    //set tab2 ui connect
    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    ui->pTab2->setLayout(pTab2SocketClient->layout());

    //set tab1 ui connect
    ptab1opencv_stream_test = new tab1opencv_stream_test(ui->pTab1);
    ui->pTab1->setLayout(ptab1opencv_stream_test->layout());

    //set tab2 tab3 connect
    connect(ptab3ControlPannel , SIGNAL(sigSoketSendData(QString)),pTab2SocketClient, SLOT(slotSocketSendData(QString)));//다른곳에 있는 기능및 변수 넘기기

    //set tab3 tab2 connect
    connect(pTab2SocketClient, SIGNAL(sigTab3RecvData(QString)), ptab3ControlPannel, SLOT(slotTab3RecvData(QString)));

    //set tab2 tab4 connect
    connect(pTab2SocketClient , SIGNAL(sigTab4RecvData(QString)),ptab4Sensordisplay, SLOT(slotTab4RecvData(QString)));//다른곳에 있는 기능및 변수 넘기기

    //exit button
    connect(ui->pPB_EXIT,SIGNAL(clicked()),qApp,SLOT(quit()));


}

MainWidget::~MainWidget()
{
    delete ui;
}

