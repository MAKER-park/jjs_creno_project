#ifndef CAMCAPTURE_H
#define CAMCAPTURE_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class CamCapture; }
QT_END_NAMESPACE

class CamCapture : public QMainWindow
{
    Q_OBJECT

public:
    CamCapture(QWidget *parent = nullptr);
    ~CamCapture();

private:
    Ui::CamCapture *ui;
    void CamView();
    void put_string(Mat &frame, string text, Point pt, int value);
};
#endif // CAMCAPTURE_H
