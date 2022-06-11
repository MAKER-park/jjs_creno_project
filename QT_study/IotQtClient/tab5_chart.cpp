#include "tab5_chart.h"
#include "ui_tab5_chart.h"

tab5_chart::tab5_chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab5_chart)
{
    ui->setupUi(this);

    //creat object
    series_lux = new QLineSeries(this);
    series_temp = new QLineSeries(this);
    series_hum = new QLineSeries(this);

    //set name
    series_lux->setName("조도");
    series_temp->setName("온도");
    series_hum->setName("습도");

    //set & apply style to series_temp
    QPen pen;
    pen.setWidth(2);//2px
    pen.setBrush(Qt::red);//set color
    pen.setCapStyle(Qt::FlatCap);// set capstyle
    pen.setJoinStyle(Qt::MiterJoin);//set joinstyle
    series_temp->setPen(pen);//apply style temp

    pen.setBrush(Qt::blue);//set color
    series_hum->setPen(pen);

    pen.setBrush(Qt::green);//set color
    series_lux->setPen(pen);


    //temply add data
//    series_temp->append(0, 6);
//    series_temp->append(2, 4);
//    series_temp->append(3, 8);
//    *series_temp<< QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

//    series_hum->append(0, 10);
//    series_hum->append(2, 8);
//    series_hum->append(3, 25);
//    *series_hum<< QPointF(11, 20) << QPointF(13, 40) << QPointF(17, 30) << QPointF(18, 35) << QPointF(20, 25);

//    series_lux->append(0, 66);
//    series_lux->append(2, 54);
//    series_lux->append(3, 48);
//    *series_lux<< QPointF(11, 51) << QPointF(13, 53) << QPointF(17, 56) << QPointF(18, 70) << QPointF(20, 80);

    //set axis x : time
    axisX = new QDateTimeAxis;
    axisX->setFormat("MM.dd h:mm");

    //get currrent time date
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    //current time date set
    firstDate.setDate(date);
    firstDate.setTime(time);

    QTime temp_time = time.addSecs(600);//add second 600sec = 10min

    //max time data set
    lastDate.setDate(date);
    lastDate.setTime(temp_time);

//    QChart *chart_temp = new QChart();
    chart = new QChart();

    //legend hide
    //chart_temp->legend()->hide();
    //add data
    chart->addSeries(series_temp);
    chart->addSeries(series_hum);
    chart->addSeries(series_lux);
    //set axes
    chart->createDefaultAxes();
    //set axes range
    chart->axes(Qt::Vertical).first()->setRange(0,100);
    chart->axes(Qt::Horizontal).first()->setRange(0,20);
    chart->setTitle("simple line chart temp");

    chartview = new QChartView(chart);

    chartview->chart()->setAxisX(axisX,series_temp);
    chartview->chart()->setAxisX(axisX,series_hum);
    chartview->chart()->setAxisX(axisX,series_lux);
    axisX->setRange(firstDate,lastDate);

    ui->pChart_H->layout()->addWidget(chartview);

    //click clear
    connect(ui->pPB_clear,SIGNAL(clicked()),this,SLOT(clear()));
    //click add button
    connect(ui->pPB_add,SIGNAL(clicked()),this,SLOT(add()));
}
//void clear(QLineSeries);

tab5_chart::~tab5_chart()
{
    delete ui;
}

void tab5_chart::clear(){
    series_hum->clear();
    series_lux->clear();
    series_temp->clear();

    //

}

void tab5_chart::add(){
    QString temp,hum,lux;
    temp = ui->pL_temp_input->text();
    hum = ui->pL_hum_input->text();
    lux = ui->pL_lux_input->text();

    //get current time and date
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QDateTime xValue;
    xValue.setDate(date);
    xValue.setTime(time);

//    qDebug()<<temp.toFloat();
//    qDebug()<<hum.toFloat();
//    qDebug()<<lux.toInt();

    series_temp->append(xValue.toMSecsSinceEpoch(),temp.toFloat());
    series_hum->append(xValue.toMSecsSinceEpoch(),hum.toFloat());
    series_lux->append(xValue.toMSecsSinceEpoch(),lux.toInt());
}

void tab5_chart::slotTab5RecvData(QString msg){
//    qDebug()<<"recv : " << msg;
    msg.replace("[","@");//문자 치환
    msg.replace("]","@");//문자 치환
    QStringList qlist = msg.split("@");//문자 자르기 @12@13 -> (12,13)

    //get current time and date
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QDateTime xValue;
    xValue.setDate(date);
    xValue.setTime(time);

//    qDebug()<<"lux : "<<qlist[3];//lux
//    qDebug()<<"tmep : "<<qlist[4];//tmp
//    qDebug()<<"hum : "<<qlist[5];//hum
//    qDebug()<<"time : "<<xValue.toMSecsSinceEpoch();

    series_temp->append(xValue.toMSecsSinceEpoch(),qlist[4].toDouble());
    series_hum->append(xValue.toMSecsSinceEpoch(),qlist[5].toDouble());
    series_lux->append(xValue.toMSecsSinceEpoch(),qlist[3].toInt());


}

