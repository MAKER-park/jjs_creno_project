/********************************************************************************
** Form generated from reading UI file 'tab5chatplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB5CHATPLOT_H
#define UI_TAB5CHATPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab5ChatPlot
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *LyName;
    QLabel *LTitle;
    QLineEdit *pLExPosition;
    QLabel *LxName;
    QLineEdit *pLEyPosition;
    QSpacerItem *verticalSpacer;
    QPushButton *pPBAddButton;
    QPushButton *pPBClearButton;
    QHBoxLayout *pChartHLayout;

    void setupUi(QWidget *Tab5ChatPlot)
    {
        if (Tab5ChatPlot->objectName().isEmpty())
            Tab5ChatPlot->setObjectName(QString::fromUtf8("Tab5ChatPlot"));
        Tab5ChatPlot->resize(554, 344);
        verticalLayout = new QVBoxLayout(Tab5ChatPlot);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(20, -1, 20, -1);
        LyName = new QLabel(Tab5ChatPlot);
        LyName->setObjectName(QString::fromUtf8("LyName"));
        QFont font;
        font.setFamily(QString::fromUtf8("HY\352\266\201\354\204\234B"));
        font.setPointSize(20);
        LyName->setFont(font);

        horizontalLayout->addWidget(LyName);

        LTitle = new QLabel(Tab5ChatPlot);
        LTitle->setObjectName(QString::fromUtf8("LTitle"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        LTitle->setFont(font1);
        LTitle->setLayoutDirection(Qt::LeftToRight);
        LTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(LTitle);

        pLExPosition = new QLineEdit(Tab5ChatPlot);
        pLExPosition->setObjectName(QString::fromUtf8("pLExPosition"));
        pLExPosition->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(pLExPosition);

        LxName = new QLabel(Tab5ChatPlot);
        LxName->setObjectName(QString::fromUtf8("LxName"));
        LxName->setFont(font1);
        LxName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(LxName);

        pLEyPosition = new QLineEdit(Tab5ChatPlot);
        pLEyPosition->setObjectName(QString::fromUtf8("pLEyPosition"));

        horizontalLayout->addWidget(pLEyPosition);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        pPBAddButton = new QPushButton(Tab5ChatPlot);
        pPBAddButton->setObjectName(QString::fromUtf8("pPBAddButton"));

        horizontalLayout->addWidget(pPBAddButton);

        pPBClearButton = new QPushButton(Tab5ChatPlot);
        pPBClearButton->setObjectName(QString::fromUtf8("pPBClearButton"));

        horizontalLayout->addWidget(pPBClearButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 2);
        horizontalLayout->setStretch(7, 2);

        verticalLayout->addLayout(horizontalLayout);

        pChartHLayout = new QHBoxLayout();
        pChartHLayout->setObjectName(QString::fromUtf8("pChartHLayout"));

        verticalLayout->addLayout(pChartHLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);

        retranslateUi(Tab5ChatPlot);

        QMetaObject::connectSlotsByName(Tab5ChatPlot);
    } // setupUi

    void retranslateUi(QWidget *Tab5ChatPlot)
    {
        Tab5ChatPlot->setWindowTitle(QCoreApplication::translate("Tab5ChatPlot", "Form", nullptr));
        LyName->setText(QCoreApplication::translate("Tab5ChatPlot", "Line Chat", nullptr));
        LTitle->setText(QCoreApplication::translate("Tab5ChatPlot", "X", nullptr));
        LxName->setText(QCoreApplication::translate("Tab5ChatPlot", "Y", nullptr));
        pPBAddButton->setText(QCoreApplication::translate("Tab5ChatPlot", "Add", nullptr));
        pPBClearButton->setText(QCoreApplication::translate("Tab5ChatPlot", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab5ChatPlot: public Ui_Tab5ChatPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB5CHATPLOT_H
