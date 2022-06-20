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

}

MainWindow::~MainWindow()
{
    delete ui;
}

