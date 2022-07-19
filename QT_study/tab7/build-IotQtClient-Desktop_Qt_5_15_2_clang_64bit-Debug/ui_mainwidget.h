/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *pTab1;
    QLabel *label;
    QWidget *pTab2;
    QWidget *pTab3;
    QWidget *pTab4;
    QWidget *pTab5;
    QWidget *pTab6;
    QWidget *pTab7;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(587, 400);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(MainWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        pTab1 = new QWidget();
        pTab1->setObjectName(QString::fromUtf8("pTab1"));
        label = new QLabel(pTab1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 90, 261, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(5);
        tabWidget->addTab(pTab1, QString());
        pTab2 = new QWidget();
        pTab2->setObjectName(QString::fromUtf8("pTab2"));
        tabWidget->addTab(pTab2, QString());
        pTab3 = new QWidget();
        pTab3->setObjectName(QString::fromUtf8("pTab3"));
        tabWidget->addTab(pTab3, QString());
        pTab4 = new QWidget();
        pTab4->setObjectName(QString::fromUtf8("pTab4"));
        tabWidget->addTab(pTab4, QString());
        pTab5 = new QWidget();
        pTab5->setObjectName(QString::fromUtf8("pTab5"));
        tabWidget->addTab(pTab5, QString());
        pTab6 = new QWidget();
        pTab6->setObjectName(QString::fromUtf8("pTab6"));
        tabWidget->addTab(pTab6, QString());
        pTab7 = new QWidget();
        pTab7->setObjectName(QString::fromUtf8("pTab7"));
        tabWidget->addTab(pTab7, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MainWidget);

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
        label->setText(QCoreApplication::translate("MainWidget", "Iot Qt \354\213\244\354\212\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab1), QCoreApplication::translate("MainWidget", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab2), QCoreApplication::translate("MainWidget", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab3), QCoreApplication::translate("MainWidget", "Tab 3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab4), QCoreApplication::translate("MainWidget", "Tab 4", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab5), QCoreApplication::translate("MainWidget", "Tab 5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab6), QCoreApplication::translate("MainWidget", "Tab 6", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab7), QCoreApplication::translate("MainWidget", "Tab 7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
