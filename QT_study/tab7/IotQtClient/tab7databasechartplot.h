#ifndef TAB7DATABASECHARTPLOT_H
#define TAB7DATABASECHARTPLOT_H

#include <QWidget>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QLineSeries>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTimeAxis>
#include <QDate>
#include <QTime>
#include <QDateTime>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Tab7DatabaseChartPlot;
}

class Tab7DatabaseChartPlot : public QWidget
{
    Q_OBJECT

public:
    explicit Tab7DatabaseChartPlot(QWidget *parent = nullptr);
    ~Tab7DatabaseChartPlot();

private:
    Ui::Tab7DatabaseChartPlot *ui;
    QLineSeries *pIlluLine;
    QLineSeries *pTempLine;
    QLineSeries *pHumiLine;
    QChart *chart;
    QChartView *chartView;
    QSqlDatabase Db;
    QDateTimeAxis *axisX;
    QDateTime firstDate;
    QDateTime lastDate;

    QDateTime yy;
    QDateTime mm;
    QDateTime dd;




private slots:
    void ChartPlotRefresh();

};

#endif // TAB7DATABASECHARTPLOT_H
