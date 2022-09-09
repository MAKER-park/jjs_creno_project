/********************************************************************************
** Form generated from reading UI file 'tab3controlpannel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB3CONTROLPANNEL_H
#define UI_TAB3CONTROLPANNEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab3ControlPannel
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QPushButton *pPBPlug;
    QPushButton *pPBLamp;

    void setupUi(QWidget *Tab3ControlPannel)
    {
        if (Tab3ControlPannel->objectName().isEmpty())
            Tab3ControlPannel->setObjectName(QString::fromUtf8("Tab3ControlPannel"));
        Tab3ControlPannel->resize(566, 373);
        gridLayout = new QGridLayout(Tab3ControlPannel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(Tab3ControlPannel);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 546, 353));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, -10, 544, 355));
        label->setPixmap(QPixmap(QString::fromUtf8(":/IotQtClient/Image/room.png")));
        pPBPlug = new QPushButton(scrollAreaWidgetContents);
        pPBPlug->setObjectName(QString::fromUtf8("pPBPlug"));
        pPBPlug->setGeometry(QRect(450, 230, 61, 61));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IotQtClient/Image/plug_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/IotQtClient/Image/plug_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBPlug->setIcon(icon);
        pPBPlug->setIconSize(QSize(50, 50));
        pPBPlug->setCheckable(true);
        pPBLamp = new QPushButton(scrollAreaWidgetContents);
        pPBLamp->setObjectName(QString::fromUtf8("pPBLamp"));
        pPBLamp->setGeometry(QRect(50, 60, 61, 61));
        pPBLamp->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IotQtClient/Image/light_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/IotQtClient/Image/light_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBLamp->setIcon(icon1);
        pPBLamp->setIconSize(QSize(50, 50));
        pPBLamp->setCheckable(true);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Tab3ControlPannel);

        QMetaObject::connectSlotsByName(Tab3ControlPannel);
    } // setupUi

    void retranslateUi(QWidget *Tab3ControlPannel)
    {
        Tab3ControlPannel->setWindowTitle(QCoreApplication::translate("Tab3ControlPannel", "Form", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("Tab3ControlPannel", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QString());
        pPBPlug->setText(QString());
        pPBLamp->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tab3ControlPannel: public Ui_Tab3ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB3CONTROLPANNEL_H
