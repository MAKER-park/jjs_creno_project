#include "camcapture.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CamCapture w;
    w.show();
    return a.exec();
}
