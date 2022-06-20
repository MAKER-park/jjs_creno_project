#include "tab1_camera_view.h"
#include "ui_tab1_camera_view.h"

Tab1_Camera_view::Tab1_Camera_view(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab1_Camera_view)
{
    ui->setupUi(this);
    pWebView = new QWebEngineView(this);
    test_timer_set = true;//lcd display test 실행변수
    if(test_timer_set){
        qDebug()<<"start!!";
        QTimer *timer = new QTimer(this);
        connect(timer , SIGNAL(timeout()),this,SLOT(showTime()));
        timer->start(50);//0.05sec
    }
    //start_button
//    connect(ui->pPB_START,SIGNAL(clicked()),this,SLOT(url_load(cam_url)));//왜 변수 붙으면 난리나냐....
    connect(ui->pPB_START,SIGNAL(clicked()),this,SLOT(url_load()));
    //pause_button
    connect(ui->pPB_PAUSE,SIGNAL(clicked()),this,SLOT(url_pause()));
    //capture_button
    connect(ui->pPB_CAPTURE,SIGNAL(clicked()),this,SLOT(capture()));
    //recoder_button
    connect(ui->pPB_RECORDE,SIGNAL(clicked()),this,SLOT(recorde()));
}

Tab1_Camera_view::~Tab1_Camera_view()
{
    delete ui;
}

void Tab1_Camera_view::url_load(){
    QString url = "http://cloud.park-cloud.co19.kr:8002/";
    qDebug()<<"url : " << url;
    //webviewsetting for layout
//    pWebView = new QWebEngineView(this);//계속하면 레이아웃이 계속 생성된다.
    pWebView->load(QUrl(url));
    ui->pVL_Cam->addWidget(pWebView);
}

void Tab1_Camera_view::url_pause(){
    qDebug()<<"acitivity : " << pWebView->isActiveWindow();
    if(pWebView->isActiveWindow()){
        qDebug()<<"is stop";
        pWebView->stop();
    }else{
        qDebug()<<"is not active don't stop!";
    }
}

void Tab1_Camera_view::capture(){
    qDebug()<<"acitivity : " << pWebView->isActiveWindow();
    if(pWebView->isActiveWindow()){
        QTime current_time = QTime::currentTime();
        QPixmap qPixmap = QPixmap::grabWidget(pWebView);
        QString fileName = "/Users/bagjaewan/Documents/screen/"+current_time.toString("hh:mm:ss")+"_captuer.PNG";
        qDebug()<<"capture start!!" << fileName;
        qPixmap.save(fileName,0,500);
    }else{
        qDebug()<<"not active no captuer!!";
    }
}

void Tab1_Camera_view::recorde(){
    qDebug()<<"acitivity : " << pWebView->isActiveWindow();
    if(pWebView->isActiveWindow()){
        QTime current_time = QTime::currentTime();
//        m_mediaRecorder->record(); //안될듯
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
