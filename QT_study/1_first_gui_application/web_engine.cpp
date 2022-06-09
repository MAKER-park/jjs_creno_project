#include "web_engine.h"

WEB_engine::WEB_engine(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

WEB_engine::~WEB_engine(){
    webView->stop();
    delete webView;
    delete ui;
}

void WEB_engine::resizeEvent(QResizeEvent *event){
    webView->resize(this->size());
    QWidget::resizeEvent(event);
}

void WEB_engine::init(){
    webView=new QWebEngineView(this);
    webView->load(QUrl("http://google.co.kr"));
    webView->show();
}
