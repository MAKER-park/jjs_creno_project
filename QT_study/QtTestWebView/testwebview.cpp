#include "testwebview.h"
#include "ui_testwebview.h"

TestWebView::TestWebView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestWebView)
{
    ui->setupUi(this);
    pWebView = new QWebEngineView(this);
    pWebView->load(QUrl(QStringLiteral("http://cloud.park-cloud.co19.kr:8002/")));
    ui->pTab1VL1->addWidget(pWebView);

    pWebView2 = new QWebEngineView(this);
    pWebView2->load(QUrl(QStringLiteral("http:www.naver.com")));
    ui->pTab2VL1->addWidget(pWebView2);

}

TestWebView::~TestWebView()
{
    delete ui;
}

