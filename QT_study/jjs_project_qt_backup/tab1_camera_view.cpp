#include "tab1_camera_view.h"
#include "ui_tab1_camera_view.h"

Tab1_Camera_view::Tab1_Camera_view(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab1_Camera_view)
{
    ui->setupUi(this);
    pWebView = new QWebEngineView(this);
    pWebView_2 = new QWebEngineView(this);
//    pWebView = new QWebEngineView(this);//계속하면 레이아웃이 계속 생성된다.
    test_timer_set = true;//lcd display test 실행변수
    if(test_timer_set){
        qDebug()<<"start!!";
        QTimer *timer = new QTimer(this);
        connect(timer , SIGNAL(timeout()),this,SLOT(showTime()));
        timer->start(50);//0.05sec
    }
    //start_button
    connect(ui->pPB_START,SIGNAL(clicked()),this,SLOT(url_load()));
    //pause_button
    connect(ui->pPB_PAUSE,SIGNAL(clicked()),this,SLOT(url_pause()));
    //capture_button
    connect(ui->pPB_CAPTURE,SIGNAL(clicked()),this,SLOT(capture()));
}

Tab1_Camera_view::~Tab1_Camera_view()
{
    delete ui;
}

void Tab1_Camera_view::url_load(){
    QString url = "http://cloud.park-cloud.co19.kr:8090/?action=stream";
    qDebug()<<"url : " << url;
    QString url_2 = "http://cloud.park-cloud.co19.kr:8091/?action=stream";
    qDebug()<<"url : " << url_2;
    //webviewsetting for layout
//    pWebView = new QWebEngineView(this);//계속하면 레이아웃이 계속 생성된다.
    pWebView->load(QUrl(url));
    pWebView_2->load(QUrl(url_2));
    ui->pVL_Cam->addWidget(pWebView);
    ui->pVL_Cam->addWidget(pWebView_2);
}

void Tab1_Camera_view::url_pause(){
    qDebug()<<"acitivity : " << pWebView->isActiveWindow();
    if(pWebView->isActiveWindow()){
        qDebug()<<"pWebView is stop";
        pWebView->stop();
    }else{
        qDebug()<<"pWebView is not active don't stop!";
    }
    if(pWebView_2->isActiveWindow()){
        qDebug()<<"pWebView_2 is stop";
        pWebView_2->stop();
    }else{
        qDebug()<<"pWebView_2 is not active don't stop!";
    }
}

void Tab1_Camera_view::capture(){
    qDebug()<<"acitivity : " << pWebView->isActiveWindow();
    if(pWebView->isActiveWindow()){
        QTime current_time = QTime::currentTime();
        //cam1
        QPixmap qPixmap = QPixmap::grabWidget(pWebView);
        QString fileName = "/Users/bagjaewan/Documents/screen/CAM_0_"+current_time.toString("hh:mm:ss")+"_captuer.PNG";
        //cam2
        QPixmap qPixmap_2 = QPixmap::grabWidget(pWebView_2);
        QString fileName_2 = "/Users/bagjaewan/Documents/screen/CAM_1_"+current_time.toString("hh:mm:ss")+"_captuer.PNG";
        qDebug()<<"capture start!!" << fileName <<"        "<< fileName_2;
        qPixmap.save(fileName,0,500);
        qPixmap_2.save(fileName_2,0,500);
    }else{
        qDebug()<<"not active no captuer!!";
    }
}

void Tab1_Camera_view::showTime(){
    ui->pLN_Xpos->display(pos_x++);
    ui->pLN_Ypos->display(pos_y);
    if(pos_x > 100){
        pos_x = 0;
        pos_y++;
    }
}
