#include "tab5chatplot.h"
#include "ui_tab5chatplot.h"

Tab5ChatPlot::Tab5ChatPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab5ChatPlot)
{


    ui->setupUi(this);
    pIlluLine = new QLineSeries(this);
    pIlluLine->setName("조도");

    pTempLine = new QLineSeries(this);
    pTempLine->setName("온도");

    pHumiLine = new QLineSeries(this);
    pHumiLine->setName("습도");

    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    pIlluLine->setPen(pen);

    pen.setBrush(Qt::green);
    pTempLine->setPen(pen);

    pen.setBrush(Qt::blue);
    pHumiLine->setPen(pen);

    chart = new QChart();
    chart->addSeries(pIlluLine);
    chart->addSeries(pTempLine);
    chart->addSeries(pHumiLine);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0,100);
    //chart->axes(Qt::Horizontal).first()->setRange(0,20);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->pChartHLayout->layout()->addWidget(chartView);

    axisX = new QDateTimeAxis;
    axisX->setFormat("h:mm");

    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    chartView->chart()->setAxisX(axisX,pIlluLine);
    chartView->chart()->setAxisX(axisX,pTempLine);
    chartView->chart()->setAxisX(axisX,pHumiLine);

    firstDate.setDate(date);
    firstDate.setTime(time);

    QTime tempTime = time.addSecs(600); //10분
    lastDate.setDate(date);
    lastDate.setTime(tempTime);


    axisX->setRange(firstDate, lastDate);

    connect(ui->pPBClearButton, SIGNAL(clicked()), this, SLOT(ChartPlotClear()));
    connect(ui->pPBAddButton, SIGNAL(clicked()), this, SLOT(CharPlotAdd()));

}

Tab5ChatPlot::~Tab5ChatPlot()
{
    delete ui;
}

void Tab5ChatPlot:: ChartPlotClear()
{
    pIlluLine->clear();
    pTempLine->clear();
    pHumiLine->clear();

}

void Tab5ChatPlot::CharPlotAdd()
{
    //double XPosition;
    //double YPosition;
    //XPosition = ui->pLExPosition->text().toDouble();
    //YPosition = ui->pLEyPosition->text().toDouble();
    //pIlluLine->append(XPosition, YPosition);

    pIlluLine->append(ui->pLExPosition->text().toDouble(), ui->pLEyPosition->text().toDouble());

    ui->pLExPosition->clear();
    ui->pLEyPosition->clear();
}
void Tab5ChatPlot:: slotTab5RecvData(QString recvData)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QDateTime xValue;
    xValue.setDate(date);
    xValue.setTime(time);

    //qDebug() << recvData;
    QStringList qlist = recvData.split("@");
    //qDebug() << qlist[2];


    pIlluLine->append(xValue.toMSecsSinceEpoch(), qlist[1].toDouble());
    pTempLine->append(xValue.toMSecsSinceEpoch(), qlist[2].toDouble());
    pHumiLine->append(xValue.toMSecsSinceEpoch(), qlist[3].toDouble());

}

