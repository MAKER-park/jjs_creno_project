#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->pTW_main->setCurrentIndex(1);
    //exit button
    connect(ui->pPB_EXIT,SIGNAL(clicked()),qApp,SLOT(quit()));

    //tab1 connect
    pTab1_Camera_View = new Tab1_Camera_view(ui->pTab1);
    ui->pTab1->setLayout(pTab1_Camera_View->layout());

    //tab2 connect
    pTab2_Setting = new tab2_connecting(ui->pTab2);
    ui->pTab2->setLayout(pTab2_Setting->layout());

    //set tab1->tab2 connect for send
    connect(pTab1_Camera_View , SIGNAL(sigsend_tab1(QString)),pTab2_Setting, SLOT(send_Data(QString)));//다른곳에 있는 기능및 변수 넘기기
    //set tab2->tab1 connect for recv
    connect(pTab2_Setting, SIGNAL(sendRespone(QString)),pTab1_Camera_View, SLOT(getRespone(QString)));
    //set tab2->tab1 connect for IP stream
    connect(pTab2_Setting, SIGNAL(sigsend_IP(QString)),pTab1_Camera_View, SLOT(getIp(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

