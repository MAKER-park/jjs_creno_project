//#include "widget.h"
#include <QLabel>// label 사용하기 위한 라이브러리 추가

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel *hello = new QLabel("hello world!!",0);//label object create and initalize 최상위 위젯으로 나타내는 변수 0
    hello ->show();//showup

    return a.exec();
}
