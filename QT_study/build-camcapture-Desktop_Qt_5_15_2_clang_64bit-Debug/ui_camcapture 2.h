/********************************************************************************
** Form generated from reading UI file 'camcapture.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMCAPTURE_H
#define UI_CAMCAPTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamCapture
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CamCapture)
    {
        if (CamCapture->objectName().isEmpty())
            CamCapture->setObjectName(QString::fromUtf8("CamCapture"));
        CamCapture->resize(800, 600);
        centralwidget = new QWidget(CamCapture);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CamCapture->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CamCapture);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        CamCapture->setMenuBar(menubar);
        statusbar = new QStatusBar(CamCapture);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CamCapture->setStatusBar(statusbar);

        retranslateUi(CamCapture);

        QMetaObject::connectSlotsByName(CamCapture);
    } // setupUi

    void retranslateUi(QMainWindow *CamCapture)
    {
        CamCapture->setWindowTitle(QCoreApplication::translate("CamCapture", "CamCapture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CamCapture: public Ui_CamCapture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMCAPTURE_H
