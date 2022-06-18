/********************************************************************************
** Form generated from reading UI file 'testwebview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWEBVIEW_H
#define UI_TESTWEBVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWebView
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *pTab1;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *pTab1VL1;
    QWidget *pTab2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *pTab2VL1;

    void setupUi(QWidget *TestWebView)
    {
        if (TestWebView->objectName().isEmpty())
            TestWebView->setObjectName(QString::fromUtf8("TestWebView"));
        TestWebView->resize(800, 600);
        verticalLayout = new QVBoxLayout(TestWebView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(TestWebView);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        pTab1 = new QWidget();
        pTab1->setObjectName(QString::fromUtf8("pTab1"));
        verticalLayout_4 = new QVBoxLayout(pTab1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pTab1VL1 = new QVBoxLayout();
        pTab1VL1->setObjectName(QString::fromUtf8("pTab1VL1"));

        verticalLayout_4->addLayout(pTab1VL1);

        tabWidget->addTab(pTab1, QString());
        pTab2 = new QWidget();
        pTab2->setObjectName(QString::fromUtf8("pTab2"));
        verticalLayout_3 = new QVBoxLayout(pTab2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pTab2VL1 = new QVBoxLayout();
        pTab2VL1->setObjectName(QString::fromUtf8("pTab2VL1"));

        verticalLayout_3->addLayout(pTab2VL1);

        tabWidget->addTab(pTab2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(TestWebView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TestWebView);
    } // setupUi

    void retranslateUi(QWidget *TestWebView)
    {
        TestWebView->setWindowTitle(QCoreApplication::translate("TestWebView", "TestWebView", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab1), QCoreApplication::translate("TestWebView", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab2), QCoreApplication::translate("TestWebView", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestWebView: public Ui_TestWebView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWEBVIEW_H
