#ifndef QT_DELAY_H
#define QT_DELAY_H

#include <QTimer>

/**
  * @brief execute a part of the code after the specified delay.
  *
  * @param time_ delay
  * @param todo_ function block
  * @return created QTimer object
  *
  * @code{.cpp}
  * QtDelay(1000, {qDebug()<<"Hello";});
  * @endcode
  */
#define QtDelay(time_, todo_)\
[=](const int& qtdelay_t){\
QTimer* qtdelay_timer = new QTimer;\
qtdelay_timer->setSingleShot(true);\
QObject::connect(qtdelay_timer, &QTimer::timeout, [=](){ todo_; qtdelay_timer->deleteLater();});\
qtdelay_timer->start(qtdelay_t);\
return qtdelay_timer;}(time_)

/**
  * @brief make QtDelay cancel the execution.
  *
  * @param timer_ QTimer object which is created by QtDelay
  * @return cancel success/fail
  *
  * @code{.cpp}
  * QTimer* delayTimer = QtDelay(1000, {qDebug()<<"Hello";});
  * ...
  * QtDelayCancel(delayTimer);
  * ...
  * @endcode
  */
#define QtDelayCancel(timer_)\
[](QTimer* qtdelay_timer){\
if(qtdelay_timer != Q_NULLPTR){ qtdelay_timer->stop(); qtdelay_timer->deleteLater(); return true; }\
else return false;\
}(timer_)


#endif // QT_DELAY_H
