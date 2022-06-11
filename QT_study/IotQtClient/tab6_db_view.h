#ifndef TAB6_DB_VIEW_H
#define TAB6_DB_VIEW_H

#include <QWidget>
#include <QtDebug>
//for sql use
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

//for use time
#include <QDate>
#include <QTime>
#include <QDateTimeAxis>

namespace Ui {
class tab6_DB_View;
}

class tab6_DB_View : public QWidget
{
    Q_OBJECT

public:
    explicit tab6_DB_View(QWidget *parent = nullptr);
    ~tab6_DB_View();

private:
    Ui::tab6_DB_View *ui;
    QSqlDatabase sqlDb;

private slots:
    void slotTab6RecvData(QString);
    void slotsearchdb();
    void slotdeletdb();
};

#endif // TAB6_DB_VIEW_H
