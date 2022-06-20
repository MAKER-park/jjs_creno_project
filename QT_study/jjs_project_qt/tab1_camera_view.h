#ifndef TAB1_CAMERA_VIEW_H
#define TAB1_CAMERA_VIEW_H

#include <QWidget>
//debug
#include <QtDebug>
//for delay
#include "qt_delay.h"
//webview
#include <QWebEngineView>
#include <QString>
//setpath + TIME
#include <QDir>
#include <QTime>
#include <QTimer>
//recoder
#include <QMediaRecorder>

namespace Ui {
class Tab1_Camera_view;
}

class Tab1_Camera_view : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1_Camera_view(QWidget *parent = nullptr);
    ~Tab1_Camera_view();

private:
    Ui::Tab1_Camera_view *ui;
    QWebEngineView  *pWebView;
    bool test_timer_set = false;
    qint16 pos_x = 0;
    qint16 pos_y = 0;
//    QScopedPointer<QMediaRecorder> m_mediaRecorder;//안될듯;;;

private slots:
    void url_load();
    void url_pause();
    void capture();
    void recorde();

    void showTime();

//signals:
//    void sigSocketRecv(QString);

};

#endif // TAB1_CAMERA_VIEW_H
