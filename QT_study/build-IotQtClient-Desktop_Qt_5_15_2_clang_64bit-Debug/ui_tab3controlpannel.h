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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab3ControlPannel
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QPushButton *pPB_Light;
    QPushButton *pPB_Plug;

    void setupUi(QWidget *tab3ControlPannel)
    {
        if (tab3ControlPannel->objectName().isEmpty())
            tab3ControlPannel->setObjectName(QString::fromUtf8("tab3ControlPannel"));
        tab3ControlPannel->resize(909, 465);
        verticalLayout = new QVBoxLayout(tab3ControlPannel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(tab3ControlPannel);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 883, 439));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 891, 431));
        label->setAutoFillBackground(false);
        label->setPixmap(QPixmap(QString::fromUtf8(":/IotQtClient/Image/room.png")));
        label->setScaledContents(true);
        pPB_Light = new QPushButton(scrollAreaWidgetContents);
        pPB_Light->setObjectName(QString::fromUtf8("pPB_Light"));
        pPB_Light->setGeometry(QRect(190, 80, 71, 81));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IotQtClient/Image/light_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/IotQtClient/Image/light_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPB_Light->setIcon(icon);
        pPB_Light->setIconSize(QSize(60, 60));
#if QT_CONFIG(shortcut)
        pPB_Light->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)
        pPB_Light->setCheckable(true);
        pPB_Plug = new QPushButton(scrollAreaWidgetContents);
        pPB_Plug->setObjectName(QString::fromUtf8("pPB_Plug"));
        pPB_Plug->setGeometry(QRect(460, 300, 71, 81));
        pPB_Plug->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IotQtClient/Image/plug_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/IotQtClient/Image/plug_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPB_Plug->setIcon(icon1);
        pPB_Plug->setIconSize(QSize(60, 60));
#if QT_CONFIG(shortcut)
        pPB_Plug->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)
        pPB_Plug->setCheckable(true);
        pPB_Plug->setFlat(false);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(tab3ControlPannel);

        QMetaObject::connectSlotsByName(tab3ControlPannel);
    } // setupUi

    void retranslateUi(QWidget *tab3ControlPannel)
    {
        tab3ControlPannel->setWindowTitle(QCoreApplication::translate("tab3ControlPannel", "Form", nullptr));
        label->setText(QString());
        pPB_Light->setText(QString());
        pPB_Plug->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tab3ControlPannel: public Ui_tab3ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB3CONTROLPANNEL_H
