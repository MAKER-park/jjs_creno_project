#include "tab6_db_view.h"
#include "ui_tab6_db_view.h"

tab6_DB_View::tab6_DB_View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab6_DB_View)
{
    ui->setupUi(this);
    sqlDb = QSqlDatabase::addDatabase("QSQLITE");//사용할 데이터 베이스 목록(여기에서)
    sqlDb.setDatabaseName("study_room_info_2.db");//file_name
    if(sqlDb.open()){
        //if ok
        qDebug()<<"success to open db";
    }
    else{
        //if not okay
        qDebug()<<"fail to open db";
    }
    QString query ="CREATE TABLE study_room_info_db ("
                   "id integer auto_increment primary key,"
                   "date DATETIME,"
                   "lux VARCHAR(10),"
                   "temp VARCHAR(10),"
                   "hum VARCHAR(10))";//make db query
    QSqlQuery qry;

    //create table
    if(!qry.exec(query)){
        //error
        //qDebug()<<"fail to make db";
    }else{//only one work!
        qDebug()<<"success to make tabel";
    }

    connect(ui->pPB_search,SIGNAL(clicked()),this,SLOT(slotsearchdb()));
    connect(ui->pPB_delete,SIGNAL(clicked()),this,SLOT(slotdeletdb()));
}

tab6_DB_View::~tab6_DB_View()
{
    delete ui;
}
void tab6_DB_View::slotsearchdb(){
    //if click serach button
    QString query;
    QSqlQuery qry;

    QDateTime dateTimefrom = ui->pdateTimeEdit_from->dateTime();
    QString str_from = dateTimefrom.toString("yy/MM/dd hh:mm:ss");
    QDateTime dateTimeto = ui->pdateTimeEdit_to->dateTime();
    QString str_to = dateTimeto.toString("yy/MM/dd hh:mm:ss");

    int rowCount = 0;
    ui->pTableWidget->clearContents();

    query = "select * from study_room_info_db where date > '"+
            str_from+"' AND date < '"+str_to +"'";

    qDebug() << "select_query" <<query;

    if(qry.exec(query)){
        //done search
        while(qry.next()){
            rowCount++;
            ui->pTableWidget->setRowCount(rowCount);
            QTableWidgetItem *id = new QTableWidgetItem();
            QTableWidgetItem *date = new QTableWidgetItem();
            QTableWidgetItem *lux = new QTableWidgetItem();
            QTableWidgetItem *temp = new QTableWidgetItem();
            QTableWidgetItem *hum = new QTableWidgetItem();
            id->setText(qry.value("id").toString());
            qDebug() <<"id : " <<id->text();
            date->setText(qry.value("date").toString());
            lux->setText(qry.value("lux").toString());
            temp->setText(qry.value("temp").toString());
            hum->setText(qry.value("hum").toString());

            ui->pTableWidget->setItem(rowCount-1,0,id);
            ui->pTableWidget->setItem(rowCount-1,1,date);
            ui->pTableWidget->setItem(rowCount-1,2,lux);
            ui->pTableWidget->setItem(rowCount-1,3,temp);
            ui->pTableWidget->setItem(rowCount-1,4,hum);
        }
    }else{
        //fail to search
    }

}

void tab6_DB_View::slotdeletdb(){
    //if click delete button
    QString query;
    QSqlQuery qry;

    QDateTime dateTimefrom = ui->pdateTimeEdit_from->dateTime();
    QString str_from = dateTimefrom.toString("yy/MM/dd hh:mm:ss");
    QDateTime dateTimeto = ui->pdateTimeEdit_to->dateTime();
    QString str_to = dateTimeto.toString("yy/MM/dd hh:mm:ss");

    query = "delete from study_room_info_db where date > '"+
            str_from+"' AND date < '"+str_to +"'";
    qDebug()<<"delet_query" << query;

    if(qry.exec(query)){
        qDebug()<<"delete done";
        ui->pTableWidget->clearContents();
    }else{
        qDebug()<<"fail to delete";
    }

}

void tab6_DB_View::slotTab6RecvData(QString msg){
    QString lux,temp, hum, query,id;
    QSqlQuery qry;

    msg.replace("[","@");//문자 치환
    msg.replace("]","@");//문자 치환
    QStringList qlist = msg.split("@");//문자 자르기 @12@13 -> (12,13)

    //get current time and date
    QDateTime dateTime = QDateTime::currentDateTime();


//    qDebug()<<"lux : "<<qlist[3];//lux
//    qDebug()<<"temp : "<<qlist[4];//tmp
//    qDebug()<<"hum : "<<qlist[5];//hum
//    qDebug()<<"time : "<<dateTime.toMSecsSinceEpoch();//time

    lux = qlist[3];
    temp = qlist[4];
    hum = qlist[5];
    id = "";

    query = "insert into study_room_info_db( id ,date, lux, temp, hum) values('"+ id +"','"+dateTime.toString("yy/MM/dd hh:mm:ss")+"','"+lux+"','"+temp+"','" + hum + "')";
    qDebug() << "inserect_query" <<query;
    if(qry.exec(query)){
        qDebug()<<"lux : "<<qlist[3];//lux
        qDebug()<<"temp : "<<qlist[4];//tmp
        qDebug()<<"hum : "<<qlist[5];//hum
        qDebug()<<"time : "<<dateTime.toMSecsSinceEpoch();//time

        qDebug()<<"upload done!";
    }else{
        qDebug()<<"upload fail!";
        qDebug()<<qry.lastError().text();
    }


}
