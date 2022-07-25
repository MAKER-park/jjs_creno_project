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
    qDebug()<<"drivers : " << QSqlDatabase::drivers();
    ui->pPB_MOVE->setEnabled(true); //default
    //start_button
    connect(ui->pPB_START,SIGNAL(clicked()),this,SLOT(url_load()));
    //pause_button
    connect(ui->pPB_PAUSE,SIGNAL(clicked()),this,SLOT(url_pause()));
    //capture_button
    connect(ui->pPB_CAPTURE,SIGNAL(clicked()),this,SLOT(capture()));
    //move_button
    connect(ui->pPB_MOVE,SIGNAL(clicked()),this,SLOT(move()));
}

Tab1_Camera_view::~Tab1_Camera_view()
{
    delete ui;
}

void Tab1_Camera_view::move(){
    //click button move
    QString move,to;
    move = ui->pLE_MOVE->text();
    to = ui->pLE_TO->text();

    if(move.isEmpty() && to.isEmpty()){
        QMessageBox::warning(this,"경고","좌표값을 확인해 주세요.");
        //msgbox check your location
    }else{
        int move_x = move.split(",")[0].toInt();
        int move_y = move.split(",")[1].toInt();
        int move_z = move.split(",")[2].toInt();
        qDebug()<< "mx : " << move_x << " my : " << move_y << "mz : " << move_z << "\n";

        int to_x = to.split(",")[0].toInt();
        int to_y = to.split(",")[1].toInt();
        int to_z = to.split(",")[2].toInt();
        qDebug()<< "tx : " << to_x << " ty : " << to_y << "tz : " << to_z << "\n";

        if(move_x < 4 && move_y < 3 && move_z < 3 ){
            if(to_x < 4 && to_y < 3 && to_z < 3){
                emit sigsend_tab1("[1]move"+ move +" "+ to + "\n");
            }else{
                QMessageBox::warning(this,"경고","좌표값을 확인해 주세요.");
                //msgbox check your location
            }
        }else{
            QMessageBox::warning(this,"경고","좌표값을 확인해 주세요.");
            //msgbox check your location
        }

    }

}

void Tab1_Camera_view::url_load(){
    if(IP.isEmpty()){
    }else{
        QString url = "http://"+IP+":8080/?action=stream";
        qDebug()<<"url : " << url;
        QString url_2 = "http://"+IP+":8081/?action=stream";
        qDebug()<<"url : " << url_2;
        //webviewsetting for layout
    //    pWebView = new QWebEngineView(this);//계속하면 레이아웃이 계속 생성된다.
        pWebView->load(QUrl(url));
        pWebView_2->load(QUrl(url_2));
        ui->pVL_Cam->addWidget(pWebView);
        ui->pVL_Cam->addWidget(pWebView_2);
    }

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
        //start button 을 눌러주세.
        QMessageBox::warning(this,"경고","재생중인 영상이 없습니다.");
    }
}

//void Tab1_Camera_view::showTime(){
//    ui->pLN_Xpos->display(pos_x++);
//    ui->pLN_Ypos->display(pos_y);
//    if(pos_x > 100){
//        pos_x = 0;
//        pos_y++;
//    }
//}

void Tab1_Camera_view::getRespone(QString respon){
    if((respon.indexOf("ok"))!=-1){
        ui->pPB_MOVE->setEnabled(false);
    }else if((respon.indexOf("compelete"))!=-1){
        ui->pPB_MOVE->setEnabled(true);
    }
}

void Tab1_Camera_view::getIp(QString ip){
    IP = ip;
}
