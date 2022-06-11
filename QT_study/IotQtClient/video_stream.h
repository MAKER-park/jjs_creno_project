#ifndef VIDEO_STREAM_H
#define VIDEO_STREAM_H

#include <QPixmap>
#include <QImage>
#include <QThread>
#include <opencv2/opencv.hpp>

class video_stream : public QThread//
{
    Q_OBJECT//
public:
    video_stream(QObject *parent = nullptr);

//    QPixmap pixmap() const{
//        return mPixmap;
//    }
signals:
//    QPixmap mPixmap;
//    cv::Mat mFrame;
//    cv::VideoCapture mVideoCap;
};

#endif // VIDEO_STREAM_H
