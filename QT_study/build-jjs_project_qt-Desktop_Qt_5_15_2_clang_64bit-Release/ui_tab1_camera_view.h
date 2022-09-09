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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *pLE_MOVE;
    QLabel *label_4;
    QLineEdit *pLE_TO;
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

        horizontalLayout->setStretch(0, 8);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(Tab1_Camera_view);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        pLE_MOVE = new QLineEdit(Tab1_Camera_view);
        pLE_MOVE->setObjectName(QString::fromUtf8("pLE_MOVE"));

        horizontalLayout_5->addWidget(pLE_MOVE);

        label_4 = new QLabel(Tab1_Camera_view);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        pLE_TO = new QLineEdit(Tab1_Camera_view);
        pLE_TO->setObjectName(QString::fromUtf8("pLE_TO"));

        horizontalLayout_5->addWidget(pLE_TO);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pPB_START = new QPushButton(Tab1_Camera_view);
        pPB_START->setObjectName(QString::fromUtf8("pPB_START"));
        QFont font;
        font.setPointSize(30);
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

        verticalLayout_3->setStretch(0, 8);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);

        retranslateUi(Tab1_Camera_view);

        QMetaObject::connectSlotsByName(Tab1_Camera_view);
    } // setupUi

    void retranslateUi(QWidget *Tab1_Camera_view)
    {
        Tab1_Camera_view->setWindowTitle(QCoreApplication::translate("Tab1_Camera_view", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Tab1_Camera_view", "MOVE", nullptr));
        label_4->setText(QCoreApplication::translate("Tab1_Camera_view", "TO", nullptr));
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
