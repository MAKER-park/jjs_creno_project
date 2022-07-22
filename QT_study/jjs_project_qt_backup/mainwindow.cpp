#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pTW_main->setCurrentIndex(0);
    //exit button
    connect(ui->pPB_EXIT,SIGNAL(clicked()),qApp,SLOT(quit()));

    //tab1 connect
    pTab1_Camera_View = new Tab1_Camera_view(ui->pTab1);
    ui->pTab1->setLayout(pTab1_Camera_View->layout());

    //tab2 connect
    pTab2_Setting = new tab2_connecting(ui->pTab2);
    ui->pTab2->setLayout(pTab2_Setting->layout());

    //set tab2 tab1 connect
    connect(pTab2_Setting , SIGNAL(sigTab4RecvData(QString)),pTab1_Camera_View, SLOT(slotTab4RecvData(QString)));//다른곳에 있는 기능및 변수 넘기기


    /*
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
     */

}

MainWindow::~MainWindow()
{
    delete ui;
}

