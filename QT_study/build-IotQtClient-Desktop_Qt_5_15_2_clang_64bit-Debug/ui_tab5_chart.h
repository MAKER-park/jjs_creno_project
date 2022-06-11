/********************************************************************************
** Form generated from reading UI file 'tab5_chart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB5_CHART_H
#define UI_TAB5_CHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab5_chart
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *pL_temp_input;
    QLabel *label_2;
    QLineEdit *pL_hum_input;
    QLabel *label_3;
    QLineEdit *pL_lux_input;
    QPushButton *pPB_add;
    QPushButton *pPB_clear;
    QHBoxLayout *pChart_H;

    void setupUi(QWidget *tab5_chart)
    {
        if (tab5_chart->objectName().isEmpty())
            tab5_chart->setObjectName(QString::fromUtf8("tab5_chart"));
        tab5_chart->resize(921, 518);
        verticalLayout = new QVBoxLayout(tab5_chart);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(tab5_chart);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);

        horizontalLayout->addWidget(label, 0, Qt::AlignHCenter);

        pL_temp_input = new QLineEdit(tab5_chart);
        pL_temp_input->setObjectName(QString::fromUtf8("pL_temp_input"));

        horizontalLayout->addWidget(pL_temp_input);

        label_2 = new QLabel(tab5_chart);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        pL_hum_input = new QLineEdit(tab5_chart);
        pL_hum_input->setObjectName(QString::fromUtf8("pL_hum_input"));

        horizontalLayout->addWidget(pL_hum_input);

        label_3 = new QLabel(tab5_chart);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        pL_lux_input = new QLineEdit(tab5_chart);
        pL_lux_input->setObjectName(QString::fromUtf8("pL_lux_input"));

        horizontalLayout->addWidget(pL_lux_input);

        pPB_add = new QPushButton(tab5_chart);
        pPB_add->setObjectName(QString::fromUtf8("pPB_add"));

        horizontalLayout->addWidget(pPB_add);

        pPB_clear = new QPushButton(tab5_chart);
        pPB_clear->setObjectName(QString::fromUtf8("pPB_clear"));

        horizontalLayout->addWidget(pPB_clear);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);
        horizontalLayout->setStretch(6, 1);
        horizontalLayout->setStretch(7, 1);

        verticalLayout->addLayout(horizontalLayout);

        pChart_H = new QHBoxLayout();
        pChart_H->setObjectName(QString::fromUtf8("pChart_H"));

        verticalLayout->addLayout(pChart_H);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);

        retranslateUi(tab5_chart);

        QMetaObject::connectSlotsByName(tab5_chart);
    } // setupUi

    void retranslateUi(QWidget *tab5_chart)
    {
        tab5_chart->setWindowTitle(QCoreApplication::translate("tab5_chart", "Form", nullptr));
        label->setText(QCoreApplication::translate("tab5_chart", "temp", nullptr));
        label_2->setText(QCoreApplication::translate("tab5_chart", "hum", nullptr));
        label_3->setText(QCoreApplication::translate("tab5_chart", "LUX", nullptr));
        pPB_add->setText(QCoreApplication::translate("tab5_chart", "add", nullptr));
        pPB_clear->setText(QCoreApplication::translate("tab5_chart", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tab5_chart: public Ui_tab5_chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB5_CHART_H
