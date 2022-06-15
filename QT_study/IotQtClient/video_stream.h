#ifndef VIDEO_STREAM_H
#define VIDEO_STREAM_H

#include <QPixmap>
#include <QImage>
#include <QThread>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;


class video_stream : public QThread//
{
    Q_OBJECT//
public:
    video_stream(QObject *parent = nullptr);

    QPixmap pixmap() const{
        return mPixmap;
    }

signals:
    void newPixmapCaptured();
private :
    QPixmap mPixmap;
//    cv::Mat imag;
//    imag = imread("/Users/bagjaewan/Desktop/test.png");


//    cv::Mat mFrame;
//    cv::VideoCapture mVideoCap;

//    QImage cvMatToQImage(const cv::Mat &inMat);
//    QPixmap cvMatToQPixmap(const cv::Mat &inMat);
};

#endif // VIDEO_STREAM_H
