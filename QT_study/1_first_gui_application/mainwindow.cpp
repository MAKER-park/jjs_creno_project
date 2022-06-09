#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator64>
#include <QPushButton>

int x_num=25;
int y_num=60;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(test()));
    connect(ui->pushButton_2, SIGNAL(clicked()), qApp, SLOT(quit()));
    ui->lcdNumber->display(x_num);
    ui->lcdNumber_2->display(y_num);
}

void MainWindow::test(){
    //x_num++;
    x_num=0;
    y_num=0;
    ui->lcdNumber->display(x_num);
    ui->lcdNumber_2->display(y_num);
}

MainWindow::~MainWindow()
{
    delete ui;
}

