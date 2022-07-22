/********************************************************************************
** Form generated from reading UI file 'tab7databasechartplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB7DATABASECHARTPLOT_H
#define UI_TAB7DATABASECHARTPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab7DatabaseChartPlot
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pPBRefresh;
    QHBoxLayout *pHLayoutChart;

    void setupUi(QWidget *Tab7DatabaseChartPlot)
    {
        if (Tab7DatabaseChartPlot->objectName().isEmpty())
            Tab7DatabaseChartPlot->setObjectName(QString::fromUtf8("Tab7DatabaseChartPlot"));
        Tab7DatabaseChartPlot->resize(544, 355);
        verticalLayout = new QVBoxLayout(Tab7DatabaseChartPlot);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Tab7DatabaseChartPlot);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Tw Cen MT Condensed Extra Bold"));
        font.setPointSize(28);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        pPBRefresh = new QPushButton(Tab7DatabaseChartPlot);
        pPBRefresh->setObjectName(QString::fromUtf8("pPBRefresh"));

        horizontalLayout->addWidget(pPBRefresh);

        horizontalLayout->setStretch(0, 9);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        pHLayoutChart = new QHBoxLayout();
        pHLayoutChart->setObjectName(QString::fromUtf8("pHLayoutChart"));

        verticalLayout->addLayout(pHLayoutChart);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);

        retranslateUi(Tab7DatabaseChartPlot);

        QMetaObject::connectSlotsByName(Tab7DatabaseChartPlot);
    } // setupUi

    void retranslateUi(QWidget *Tab7DatabaseChartPlot)
    {
        Tab7DatabaseChartPlot->setWindowTitle(QCoreApplication::translate("Tab7DatabaseChartPlot", "Form", nullptr));
        label->setText(QCoreApplication::translate("Tab7DatabaseChartPlot", "DataBase Chart", nullptr));
        pPBRefresh->setText(QCoreApplication::translate("Tab7DatabaseChartPlot", "\354\203\210\353\241\234\352\263\240\354\271\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab7DatabaseChartPlot: public Ui_Tab7DatabaseChartPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB7DATABASECHARTPLOT_H
