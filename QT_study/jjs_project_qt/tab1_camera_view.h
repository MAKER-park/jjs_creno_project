#ifndef TAB1_CAMERA_VIEW_H
#define TAB1_CAMERA_VIEW_H

#include <QWidget>
//debug
#include <QtDebug>
//webview
#include <QWebEngineView>
#include <QString>
//setpath + TIME
#include <QDir>
#include <QTime>
#include <QTimer>
//recoder
#include <QMediaRecorder>
#include <QtSql>
#include <QSqlDatabase>
//msgbox
#include <QMessageBox>

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
    QWebEngineView  *pWebView_2;
    bool test_timer_set = false;
    qint16 pos_x = 0;
    qint16 pos_y = 0;
    QString IP;

private slots:
    void url_load();
    void url_pause();
    void capture();
    void move();

    //for get data tab2
    void getRespone(QString);
    //for get ip tab2
    void getIp(QString);

signals:
    void sigsend_tab1(QString);

};

#endif // TAB1_CAMERA_VIEW_H
