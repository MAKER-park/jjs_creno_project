#ifndef TAB1OPENCV_STREAM_TEST_H
#define TAB1OPENCV_STREAM_TEST_H

#include <QWidget>

namespace Ui {
class tab1opencv_stream_test;
}

class tab1opencv_stream_test : public QWidget
{
    Q_OBJECT

public:
    explicit tab1opencv_stream_test(QWidget *parent = nullptr);
    ~tab1opencv_stream_test();

private:
    Ui::tab1opencv_stream_test *ui;
};

#endif // TAB1OPENCV_STREAM_TEST_H
