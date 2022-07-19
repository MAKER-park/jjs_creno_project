#ifndef TAB6DATABASE_H
#define TAB6DATABASE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class Tab6Database;
}

class Tab6Database : public QWidget
{
    Q_OBJECT

public:
    explicit Tab6Database(QWidget *parent = nullptr);
    ~Tab6Database();

private:
    Ui::Tab6Database *ui;
    QSqlDatabase sqlDb;

private slots:
    void slotTab6RecvData(QString);
    void slotSearchDb();
    void slotDeleteDb();


};

#endif // TAB6DATABASE_H
