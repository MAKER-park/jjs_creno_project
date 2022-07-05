#include "tab2_connecting.h"
#include "ui_tab2_connecting.h"

tab2_connecting::tab2_connecting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab2_connecting)
{
    ui->setupUi(this);
}

tab2_connecting::~tab2_connecting()
{
    delete ui;
}
