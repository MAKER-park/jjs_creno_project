#include "tab6database.h"
#include "ui_tab6database.h"

Tab6Database::Tab6Database(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab6Database)
{
    ui->setupUi(this);
    sqlDb = QSqlDatabase::addDatabase("QSQLITE");
    sqlDb.setDatabaseName("temp.db");
    if(sqlDb.open()) //true이면 db파일 오픈
    {
        qDebug() << "success DB connection";
    }
    else
        qDebug() << "fail DB connection";

    QString query = "CREATE TABLE temp_db (id integer primary key,date DATETIME, illu VARCHAR(10), temp VARCHAR(10), humi VARCHAR(10))";
    QSqlQuery qry;
    if(!qry.exec(query))
    {
        qDebug() << "already maked query";
    }
    else
    {
        qDebug() << "create query success";
    }
    connect(ui->pPBSearchButton, SIGNAL(clicked()),this, SLOT(slotSearchDb()));
    connect(ui->pPBDeleteButton, SIGNAL(clicked()),this, SLOT(slotDeleteDb()));
    ui->pTableWidget->resizeColumnToContents(0);
    ui->pTableWidget->resizeColumnToContents(2);
    ui->pTableWidget->resizeColumnToContents(3);
    ui->pTableWidget->resizeColumnToContents(4);
}

Tab6Database::~Tab6Database()
{
    delete ui;
}
void Tab6Database:: slotTab6RecvData(QString strRecvData)
{
    //qDebug() << strRecvData;
    QDateTime dateTime = QDateTime::currentDateTime();

    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList qlist = strRecvData.split("@");
    QString illu = qlist[3];
    QString temp = qlist[4];
    QString humi = qlist[5];;

    QString queryData = "insert into temp_db(date,illu,temp,humi) values('"+dateTime.toString("yy/MM/dd hh:mm:ss") +"','" + illu + "', '" + temp + "','" + humi + "')";
    QSqlQuery qryData;
    if(qryData.exec(queryData))
    {
        qDebug() << "Insert Ok";
    }
    else
    {
        qDebug() << qryData.lastError().text();
    }
}
void Tab6Database:: slotSearchDb()
{
    QSqlQuery qrySearch;
    QString querySearch;
    QDateTime dateTimeFrom = ui->pDateTimeEditFrom->dateTime();
    QString strFrom = dateTimeFrom.toString("yy/MM/dd hh:mm:ss");
    QDateTime dateTimeTo = ui->pDateTimeEditTo->dateTime();
    QString strTo = dateTimeTo.toString("yy/MM/dd hh:mm:ss");

    int rowCount = 0;
    ui->pTableWidget->clearContents();

    querySearch = "select * from temp_db where date>'" + strFrom +"' AND date <'" +strTo +"'";
    if(qrySearch.exec(querySearch))
    {
        while (qrySearch.next()) {
            rowCount++;
            ui->pTableWidget->setRowCount(rowCount);
            QTableWidgetItem * id = new QTableWidgetItem();
            QTableWidgetItem * date = new QTableWidgetItem();
            QTableWidgetItem * illu = new QTableWidgetItem();
            QTableWidgetItem * temp = new QTableWidgetItem();
            QTableWidgetItem * humi = new QTableWidgetItem();
            id->setText(qrySearch.value("id").toString());
            date->setText(qrySearch.value("date").toString());
            illu->setText(qrySearch.value("illu").toString());
            temp->setText(qrySearch.value("temp").toString());
            humi->setText(qrySearch.value("humi").toString());
            ui->pTableWidget->setItem(rowCount-1, 0, id);
            ui->pTableWidget->setItem(rowCount-1, 1, date);
            ui->pTableWidget->setItem(rowCount-1, 2, illu);
            ui->pTableWidget->setItem(rowCount-1, 3, temp);
            ui->pTableWidget->setItem(rowCount-1, 4, humi);
        }
    }
}
void Tab6Database:: slotDeleteDb()
{
    QSqlQuery qryDelete;
    QString queryDelete;
    QDateTime dateTimeFrom = ui->pDateTimeEditFrom->dateTime();
    QString strFrom = dateTimeFrom.toString("yy/MM/dd hh:mm:ss");
    QDateTime dateTimeTo = ui->pDateTimeEditTo->dateTime();
    QString strTo = dateTimeTo.toString("yy/MM/dd hh:mm:ss");

    queryDelete = "delete from temp_db where date>'" + strFrom +"' AND date <'" +strTo +"'";
    if(qryDelete.exec(queryDelete))
    {
        ui->pTableWidget->clearContents();
    }

}
