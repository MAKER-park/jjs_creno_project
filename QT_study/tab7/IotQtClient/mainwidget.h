#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <tab2socketclient.h>
#include <tab3controlpannel.h>
#include <tab4sensordisplay.h>
#include <tab5chatplot.h>
#include <tab6database.h>
#include <tab7databasechartplot.h>

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
    Tab2SocketClient *pTab2SocketClient;
    Tab3ControlPannel *pTab3ControlPannel;
    Tab4SensorDisplay *pTab4SensorDisplay;
    Tab5ChatPlot *pTab5ChatPlot;
    Tab6Database *pTab6Database;
    Tab7DatabaseChartPlot *pTab7DatabaseChartPlot;


};
#endif // MAINWIDGET_H
