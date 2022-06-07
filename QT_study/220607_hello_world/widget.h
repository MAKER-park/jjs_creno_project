#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>// label 사용하기 위한 라이브러리 추가

class Widget : public QWidget
{
    Q_OBJECT
    QLabel *hello;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
