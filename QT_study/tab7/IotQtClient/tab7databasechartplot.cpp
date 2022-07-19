#include "tab7databasechartplot.h"
#include "ui_tab7databasechartplot.h"

Tab7DatabaseChartPlot::Tab7DatabaseChartPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab7DatabaseChartPlot)
{
    ui->setupUi(this);
    connect(ui->pPBRefresh, SIGNAL(clicked()), this, SLOT(ChartPlotRefresh()));

    Db = QSqlDatabase::addDatabase("QSQLITE");
    Db.setDatabaseName("temp.db");
    if(Db.open()) //true이면 db파일 오픈
    {
        qDebug() << "success DB connection";
    }
    else
        qDebug() << "fail DB connection";

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

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->pHLayoutChart->layout()->addWidget(chartView);


}

Tab7DatabaseChartPlot::~Tab7DatabaseChartPlot()
{
    delete ui;
}

void Tab7DatabaseChartPlot:: ChartPlotRefresh()
{
    pIlluLine->clear();
    pTempLine->clear();
    pHumiLine->clear();

    QSqlQuery qry;
    QString queryStr;


    queryStr = QString("select * from temp_db");

    int id_count = 0;


    if(qry.exec(queryStr))
    {
        while (qry.next()) {
            id_count++;
            //QString id_values = qry.value(0).toString();
            QString date_values = qry.value(1).toString();
            //qDebug() << id_count;
            //qDebug() << id_values;
            //qDebug() << date_values;
            qDebug() << date_values;

            chart->axes(Qt::Horizontal).first()->setRange(0,id_count);
            pIlluLine->append(id_count, qry.value(2).toDouble());
            pTempLine->append(id_count, qry.value(3).toDouble());
            pHumiLine->append(id_count, qry.value(4).toDouble());

        }
    }
}
