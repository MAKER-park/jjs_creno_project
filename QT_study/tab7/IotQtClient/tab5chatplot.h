#ifndef TAB5CHATPLOT_H
#define TAB5CHATPLOT_H

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QDebug>


QT_CHARTS_USE_NAMESPACE  //APT 라이브러리

namespace Ui {
class Tab5ChatPlot;
}

class Tab5ChatPlot : public QWidget
{
    Q_OBJECT

public:
    explicit Tab5ChatPlot(QWidget *parent = nullptr);
    ~Tab5ChatPlot();

private:
    Ui::Tab5ChatPlot *ui;
    QLineSeries * pIlluLine;
    QLineSeries * pTempLine;
    QLineSeries * pHumiLine;
    QChart *chart;
    QChartView *chartView;
    QDateTimeAxis *axisX;
    QDateTime firstDate;
    QDateTime lastDate;



private slots:
    void ChartPlotClear();
    void CharPlotAdd();
    void slotTab5RecvData(QString);


};

#endif // TAB5CHATPLOT_H
