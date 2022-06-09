#ifndef TAB4SENSORDISPLAY_H
#define TAB4SENSORDISPLAY_H

#include <QWidget>
#include <QTime>
//for debug
#include <QtDebug>
//
#include <QMessageBox>

namespace Ui {
class tab4SensorDisplay;
}

class tab4SensorDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit tab4SensorDisplay(QWidget *parent = nullptr);
    ~tab4SensorDisplay();
private:
    Ui::tab4SensorDisplay *ui;
private slots:
    void slotTab4RecvData(QString);

};

#endif // TAB4SENSORDISPLAY_H
