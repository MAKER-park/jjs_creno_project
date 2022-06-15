/********************************************************************************
** Form generated from reading UI file 'tab1opencv_stream_test.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1OPENCV_STREAM_TEST_H
#define UI_TAB1OPENCV_STREAM_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab1opencv_stream_test
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pPB_Start;
    QPushButton *pushButton_3;
    QToolButton *toolButton;

    void setupUi(QWidget *tab1opencv_stream_test)
    {
        if (tab1opencv_stream_test->objectName().isEmpty())
            tab1opencv_stream_test->setObjectName(QString::fromUtf8("tab1opencv_stream_test"));
        tab1opencv_stream_test->resize(945, 475);
        verticalLayout_2 = new QVBoxLayout(tab1opencv_stream_test);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(tab1opencv_stream_test);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(tab1opencv_stream_test);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lcdNumber = new QLCDNumber(tab1opencv_stream_test);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setFont(font);
        lcdNumber->setDigitCount(3);

        horizontalLayout_2->addWidget(lcdNumber);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 9);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(tab1opencv_stream_test);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        lcdNumber_2 = new QLCDNumber(tab1opencv_stream_test);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setFont(font);
        lcdNumber_2->setDigitCount(3);

        horizontalLayout_3->addWidget(lcdNumber_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 9);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalLayout_4->setStretch(0, 8);
        horizontalLayout_4->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(tab1opencv_stream_test);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(tab1opencv_stream_test);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pPB_Start = new QPushButton(tab1opencv_stream_test);
        pPB_Start->setObjectName(QString::fromUtf8("pPB_Start"));

        horizontalLayout->addWidget(pPB_Start);

        pushButton_3 = new QPushButton(tab1opencv_stream_test);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        toolButton = new QToolButton(tab1opencv_stream_test);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 2);

        retranslateUi(tab1opencv_stream_test);

        QMetaObject::connectSlotsByName(tab1opencv_stream_test);
    } // setupUi

    void retranslateUi(QWidget *tab1opencv_stream_test)
    {
        tab1opencv_stream_test->setWindowTitle(QCoreApplication::translate("tab1opencv_stream_test", "Form", nullptr));
        label_3->setText(QString());
        label->setText(QCoreApplication::translate("tab1opencv_stream_test", "X", nullptr));
        label_2->setText(QCoreApplication::translate("tab1opencv_stream_test", "Y", nullptr));
        pushButton->setText(QCoreApplication::translate("tab1opencv_stream_test", "recorde", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tab1opencv_stream_test", "capture", nullptr));
        pPB_Start->setText(QCoreApplication::translate("tab1opencv_stream_test", "start", nullptr));
        pushButton_3->setText(QCoreApplication::translate("tab1opencv_stream_test", "pasue", nullptr));
        toolButton->setText(QCoreApplication::translate("tab1opencv_stream_test", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tab1opencv_stream_test: public Ui_tab1opencv_stream_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1OPENCV_STREAM_TEST_H
