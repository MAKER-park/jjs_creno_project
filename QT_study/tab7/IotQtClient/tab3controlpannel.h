#ifndef TAB3CONTROLPANNEL_H
#define TAB3CONTROLPANNEL_H

#include <QDebug>
#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Tab3ControlPannel;
}

class Tab3ControlPannel : public QWidget
{
    Q_OBJECT

public:
    explicit Tab3ControlPannel(QWidget *parent = nullptr);
    ~Tab3ControlPannel();

private:
    Ui::Tab3ControlPannel *ui;

private slots:
    void slotLampOnOff(bool);
    void slotPlugOnOff(bool);
    void slotTab3RecvData(QString);

signals:
    void sigSocketSendData(QString);


};

#endif // TAB3CONTROLPANNEL_H
