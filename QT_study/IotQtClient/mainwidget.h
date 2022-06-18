#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
//#include <tab2socketclient.h>
#include "tab1_stream.h"
#include "tab2socketclient.h"
#include "tab3controlpannel.h"
#include "tab4sensordisplay.h"
#include "tab5_chart.h"
#include "tab6_db_view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    //tab1_custom
    tab1opencv_stream_test* ptab1opencv_stream_test;
    Tab2SocketClient* pTab2SocketClient;
    tab3ControlPannel* ptab3ControlPannel;
    tab4SensorDisplay* ptab4Sensordisplay;
    tab5_chart* ptab5_chart;
    tab6_DB_View* ptab6_DB;

private slots:
//    void exit();
};
#endif // MAINWIDGET_H
