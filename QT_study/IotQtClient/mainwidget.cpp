#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QApplication>
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(5);// 2:tab3 open

    //set tab6 ui connect
    ptab6_DB = new tab6_DB_View(ui->pTab6);
    ui->pTab6->setLayout(ptab6_DB->layout());

    //set tab5 ui connect
    ptab5_chart = new tab5_chart(ui->pTab5);
    ui->pTab5->setLayout(ptab5_chart->layout());

    //set tab4 ui connect
    ptab4Sensordisplay = new tab4SensorDisplay(ui->pTab4);
    ui->pTab4->setLayout(ptab4Sensordisplay->layout());

    //set tab3 ui connect
    ptab3ControlPannel = new tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(ptab3ControlPannel->layout());
//---------------------tab2 server connection----------------//
    //set tab2 ui connect
    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    ui->pTab2->setLayout(pTab2SocketClient->layout());

    //set tab2 tab4 connect
    connect(pTab2SocketClient , SIGNAL(sigTab4RecvData(QString)),ptab4Sensordisplay, SLOT(slotTab4RecvData(QString)));//다른곳에 있는 기능및 변수 넘기기

    //set tab2 tab5 connect
    connect(pTab2SocketClient , SIGNAL(sigTab5RecvData(QString)),ptab5_chart, SLOT(slotTab5RecvData(QString)));//다른곳에 있는 기능및 변수 넘기기

    //set tab2 tab6 connect
    connect(pTab2SocketClient , SIGNAL(sigTab6RecvData(QString)),ptab6_DB, SLOT(slotTab6RecvData(QString)));//다른곳에 있는 기능및 변수 넘기기

    //set tab2 tab3 connect
    connect(ptab3ControlPannel , SIGNAL(sigSoketSendData(QString)),pTab2SocketClient, SLOT(slotSocketSendData(QString)));//다른곳에 있는 기능및 변수 넘기기

    //set tab3 tab2 connect
    connect(pTab2SocketClient, SIGNAL(sigTab3RecvData(QString)), ptab3ControlPannel, SLOT(slotTab3RecvData(QString)));
//------------------tab connection------------------------//
    //set tab1 ui connect
    ptab1opencv_stream_test = new tab1opencv_stream_test(ui->pTab1);
    ui->pTab1->setLayout(ptab1opencv_stream_test->layout());


    //exit button
    connect(ui->pPB_EXIT,SIGNAL(clicked()),qApp,SLOT(quit()));


}

MainWidget::~MainWidget()
{
    delete ui;
}

