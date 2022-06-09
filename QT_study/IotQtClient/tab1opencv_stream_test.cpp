#include "tab1opencv_stream_test.h"
#include "ui_tab1opencv_stream_test.h"

tab1opencv_stream_test::tab1opencv_stream_test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab1opencv_stream_test)
{
    ui->setupUi(this);
}

tab1opencv_stream_test::~tab1opencv_stream_test()
{
    delete ui;
}
