#include "tab1opencv_stream_test.h"
#include "ui_tab1opencv_stream_test.h"

tab1opencv_stream_test::tab1opencv_stream_test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab1opencv_stream_test)
{
    ui->setupUi(this);
    connect(ui->pPB_Start,SIGNAL(clicked()),this,SLOT(slot_video()));
}

tab1opencv_stream_test::~tab1opencv_stream_test()
{
    delete ui;
}

void tab1opencv_stream_test::slot_video(){
    qDebug()<<"start video!!";
}

void tab1opencv_stream_test::on_pPB_Start_clicked()
{

}

