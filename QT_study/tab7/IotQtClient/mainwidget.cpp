#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(1);

    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    ui->pTab2->setLayout(pTab2SocketClient->layout());

    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(pTab3ControlPannel->layout());

    pTab4SensorDisplay = new Tab4SensorDisplay(ui->pTab4);
    ui->pTab4->setLayout(pTab4SensorDisplay->layout());

    pTab5ChatPlot = new Tab5ChatPlot(ui->pTab5);
    ui->pTab5->setLayout(pTab5ChatPlot->layout());

    pTab6Database = new Tab6Database(ui->pTab6);
    ui->pTab6->setLayout(pTab6Database->layout());

    pTab7DatabaseChartPlot = new Tab7DatabaseChartPlot(ui->pTab7);
    ui->pTab7->setLayout(pTab7DatabaseChartPlot->layout());


    connect(pTab2SocketClient, SIGNAL(sigTab3RecvData(QString)), pTab3ControlPannel, SLOT(slotTab3RecvData(QString)));
    connect(pTab2SocketClient, SIGNAL(sigTab4RecvData(QString)), pTab4SensorDisplay, SLOT(slotTab4RecvData(QString)));
    connect(pTab2SocketClient, SIGNAL(sigTab5RecvData(QString)), pTab5ChatPlot, SLOT(slotTab5RecvData(QString)));
    connect(pTab2SocketClient, SIGNAL(sigTab6RecvData(QString)), pTab6Database, SLOT(slotTab6RecvData(QString)));
    connect(pTab3ControlPannel, SIGNAL(sigSocketSendData(QString)), pTab2SocketClient, SLOT(slotSocketSendData(QString)));



}

MainWidget::~MainWidget()
{
    delete ui;
}

