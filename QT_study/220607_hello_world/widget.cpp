#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    hello = new QLabel("hello world!!",this);//label object create and initalize
    hello ->show();//showup
}

Widget::~Widget()
{
}

