#include "testwebview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestWebView w;
    w.show();
    return a.exec();
}
