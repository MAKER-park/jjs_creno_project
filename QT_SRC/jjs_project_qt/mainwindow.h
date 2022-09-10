#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tab1_camera_view.h"
#include "tab2_connecting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //set tab 1
    Tab1_Camera_view* pTab1_Camera_View;
    tab2_connecting* pTab2_Setting;

};
#endif // MAINWINDOW_H
