#ifndef TAB5_CHART_H
#define TAB5_CHART_H

#include <QWidget>
#include <QLineSeries>

//unkonwun
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

//add
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDateTimeAxis>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class tab5_chart;
}

class tab5_chart : public QWidget
{
    Q_OBJECT

public:
    explicit tab5_chart(QWidget *parent = nullptr);
    ~tab5_chart();

private:
    Ui::tab5_chart *ui;
    QLineSeries* series_lux;
    QLineSeries* series_temp;
    QLineSeries* series_hum;

    QDateTimeAxis* axisX;

    QChart* chart;

    QChartView *chartview;

    QDateTime firstDate;
    QDateTime lastDate;

    QTime firstTime;
    QTime lastTime;

private slots:
    void add();
    void clear();
    void slotTab5RecvData(QString);
};

#endif // TAB5_CHART_H
