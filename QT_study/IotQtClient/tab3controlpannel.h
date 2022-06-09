#ifndef TAB3CONTROLPANNEL_H
#define TAB3CONTROLPANNEL_H

#include <QWidget>
#include <QTime>
//for debug
#include <QtDebug>>
//
#include <QMessageBox>

namespace Ui {
class tab3ControlPannel;
}

class tab3ControlPannel : public QWidget
{
    Q_OBJECT

public:
    explicit tab3ControlPannel(QWidget *parent = nullptr);
    ~tab3ControlPannel();

private:
    Ui::tab3ControlPannel *ui;

private slots:
    void slotLightToggle(bool);
    void slotPlugToggle(bool);
    void slotTab3RecvData(QString);

signals:
    void sigSoketSendData(QString);
};

#endif // TAB3CONTROLPANNEL_H
