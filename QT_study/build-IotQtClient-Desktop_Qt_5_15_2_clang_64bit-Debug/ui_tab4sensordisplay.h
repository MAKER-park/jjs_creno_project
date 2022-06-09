/********************************************************************************
** Form generated from reading UI file 'tab4sensordisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB4SENSORDISPLAY_H
#define UI_TAB4SENSORDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab4SensorDisplay
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *pLB_LUX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *pLB_TEMP;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *pLB_HUM;

    void setupUi(QWidget *tab4SensorDisplay)
    {
        if (tab4SensorDisplay->objectName().isEmpty())
            tab4SensorDisplay->setObjectName(QString::fromUtf8("tab4SensorDisplay"));
        tab4SensorDisplay->resize(933, 533);
        verticalLayout = new QVBoxLayout(tab4SensorDisplay);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(tab4SensorDisplay);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        pLB_LUX = new QLabel(tab4SensorDisplay);
        pLB_LUX->setObjectName(QString::fromUtf8("pLB_LUX"));
        QFont font1;
        font1.setPointSize(45);
        pLB_LUX->setFont(font1);

        horizontalLayout->addWidget(pLB_LUX);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(tab4SensorDisplay);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        pLB_TEMP = new QLabel(tab4SensorDisplay);
        pLB_TEMP->setObjectName(QString::fromUtf8("pLB_TEMP"));
        pLB_TEMP->setFont(font1);

        horizontalLayout_2->addWidget(pLB_TEMP);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(tab4SensorDisplay);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        pLB_HUM = new QLabel(tab4SensorDisplay);
        pLB_HUM->setObjectName(QString::fromUtf8("pLB_HUM"));
        pLB_HUM->setFont(font1);

        horizontalLayout_3->addWidget(pLB_HUM);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(tab4SensorDisplay);

        QMetaObject::connectSlotsByName(tab4SensorDisplay);
    } // setupUi

    void retranslateUi(QWidget *tab4SensorDisplay)
    {
        tab4SensorDisplay->setWindowTitle(QCoreApplication::translate("tab4SensorDisplay", "Form", nullptr));
        label->setText(QCoreApplication::translate("tab4SensorDisplay", "LUX", nullptr));
        pLB_LUX->setText(QCoreApplication::translate("tab4SensorDisplay", "0", nullptr));
        label_3->setText(QCoreApplication::translate("tab4SensorDisplay", "TEMP", nullptr));
        pLB_TEMP->setText(QCoreApplication::translate("tab4SensorDisplay", "0", nullptr));
        label_5->setText(QCoreApplication::translate("tab4SensorDisplay", "HUM", nullptr));
        pLB_HUM->setText(QCoreApplication::translate("tab4SensorDisplay", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tab4SensorDisplay: public Ui_tab4SensorDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB4SENSORDISPLAY_H
