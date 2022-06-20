/********************************************************************************
** Form generated from reading UI file 'web_view_cam.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEB_VIEW_CAM_H
#define UI_WEB_VIEW_CAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_web_view_cam
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *pL_cam_view;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *pL_xpos;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *pL_ypos;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QWidget *web_view_cam)
    {
        if (web_view_cam->objectName().isEmpty())
            web_view_cam->setObjectName(QString::fromUtf8("web_view_cam"));
        web_view_cam->resize(955, 544);
        verticalLayout_2 = new QVBoxLayout(web_view_cam);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pL_cam_view = new QVBoxLayout();
        pL_cam_view->setObjectName(QString::fromUtf8("pL_cam_view"));

        horizontalLayout_3->addLayout(pL_cam_view);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(web_view_cam);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        pL_xpos = new QLCDNumber(web_view_cam);
        pL_xpos->setObjectName(QString::fromUtf8("pL_xpos"));
        pL_xpos->setFont(font);
        pL_xpos->setDigitCount(3);

        horizontalLayout->addWidget(pL_xpos);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(web_view_cam);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        pL_ypos = new QLCDNumber(web_view_cam);
        pL_ypos->setObjectName(QString::fromUtf8("pL_ypos"));
        pL_ypos->setFont(font);
        pL_ypos->setDigitCount(3);

        horizontalLayout_2->addWidget(pL_ypos);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(0, 8);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton = new QPushButton(web_view_cam);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(web_view_cam);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(web_view_cam);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(web_view_cam);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(web_view_cam);

        QMetaObject::connectSlotsByName(web_view_cam);
    } // setupUi

    void retranslateUi(QWidget *web_view_cam)
    {
        web_view_cam->setWindowTitle(QCoreApplication::translate("web_view_cam", "Form", nullptr));
        label->setText(QCoreApplication::translate("web_view_cam", "X", nullptr));
        label_2->setText(QCoreApplication::translate("web_view_cam", "Y", nullptr));
        pushButton->setText(QCoreApplication::translate("web_view_cam", "start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("web_view_cam", "stop", nullptr));
        pushButton_4->setText(QCoreApplication::translate("web_view_cam", "capture", nullptr));
        pushButton_3->setText(QCoreApplication::translate("web_view_cam", "record", nullptr));
    } // retranslateUi

};

namespace Ui {
    class web_view_cam: public Ui_web_view_cam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEB_VIEW_CAM_H
