#include "web_view_cam.h"
#include "ui_web_view_cam.h"

web_view_cam::web_view_cam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::web_view_cam)
{
    ui->setupUi(this);
    pWebView = new QWebEngineView(this);
    pWebView->load(QUrl(QStringLiteral("http://cloud.park-cloud.co19.kr:8002/")));
    ui->pL_cam_view->addWidget(pWebView);
}

web_view_cam::~web_view_cam()
{
    delete ui;
}
