/********************************************************************************
** Form generated from reading UI file 'tab1_camera_view.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1_CAMERA_VIEW_H
#define UI_TAB1_CAMERA_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1_Camera_view
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *pVL_Cam;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLCDNumber *pLN_Xpos;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLCDNumber *pLN_Ypos;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pPB_START;
    QPushButton *pPB_PAUSE;
    QPushButton *pPB_CAPTURE;
    QPushButton *pPB_MOVE;

    void setupUi(QWidget *Tab1_Camera_view)
    {
        if (Tab1_Camera_view->objectName().isEmpty())
            Tab1_Camera_view->setObjectName(QString::fromUtf8("Tab1_Camera_view"));
        Tab1_Camera_view->resize(1116, 707);
        verticalLayout_3 = new QVBoxLayout(Tab1_Camera_view);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pVL_Cam = new QVBoxLayout();
        pVL_Cam->setObjectName(QString::fromUtf8("pVL_Cam"));

        horizontalLayout->addLayout(pVL_Cam);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Tab1_Camera_view);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        pLN_Xpos = new QLCDNumber(Tab1_Camera_view);
        pLN_Xpos->setObjectName(QString::fromUtf8("pLN_Xpos"));
        QFont font1;
        font1.setPointSize(40);
        pLN_Xpos->setFont(font1);
        pLN_Xpos->setDigitCount(3);

        horizontalLayout_2->addWidget(pLN_Xpos);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 8);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Tab1_Camera_view);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        pLN_Ypos = new QLCDNumber(Tab1_Camera_view);
        pLN_Ypos->setObjectName(QString::fromUtf8("pLN_Ypos"));
        pLN_Ypos->setFont(font1);
        pLN_Ypos->setDigitCount(3);

        horizontalLayout_3->addWidget(pLN_Ypos);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 8);

        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 2);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 8);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pPB_START = new QPushButton(Tab1_Camera_view);
        pPB_START->setObjectName(QString::fromUtf8("pPB_START"));
        pPB_START->setFont(font);

        horizontalLayout_4->addWidget(pPB_START);

        pPB_PAUSE = new QPushButton(Tab1_Camera_view);
        pPB_PAUSE->setObjectName(QString::fromUtf8("pPB_PAUSE"));
        pPB_PAUSE->setFont(font);

        horizontalLayout_4->addWidget(pPB_PAUSE);

        pPB_CAPTURE = new QPushButton(Tab1_Camera_view);
        pPB_CAPTURE->setObjectName(QString::fromUtf8("pPB_CAPTURE"));
        pPB_CAPTURE->setFont(font);

        horizontalLayout_4->addWidget(pPB_CAPTURE);

        pPB_MOVE = new QPushButton(Tab1_Camera_view);
        pPB_MOVE->setObjectName(QString::fromUtf8("pPB_MOVE"));
        pPB_MOVE->setFont(font);
        pPB_MOVE->setCheckable(true);

        horizontalLayout_4->addWidget(pPB_MOVE);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_3->setStretch(0, 9);
        verticalLayout_3->setStretch(1, 1);

        retranslateUi(Tab1_Camera_view);

        QMetaObject::connectSlotsByName(Tab1_Camera_view);
    } // setupUi

    void retranslateUi(QWidget *Tab1_Camera_view)
    {
        Tab1_Camera_view->setWindowTitle(QCoreApplication::translate("Tab1_Camera_view", "Form", nullptr));
        label->setText(QCoreApplication::translate("Tab1_Camera_view", "X", nullptr));
        label_2->setText(QCoreApplication::translate("Tab1_Camera_view", "Y", nullptr));
        pPB_START->setText(QCoreApplication::translate("Tab1_Camera_view", "START", nullptr));
        pPB_PAUSE->setText(QCoreApplication::translate("Tab1_Camera_view", "PAUSE", nullptr));
        pPB_CAPTURE->setText(QCoreApplication::translate("Tab1_Camera_view", "CAPTURE", nullptr));
        pPB_MOVE->setText(QCoreApplication::translate("Tab1_Camera_view", "MOVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab1_Camera_view: public Ui_Tab1_Camera_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1_CAMERA_VIEW_H
