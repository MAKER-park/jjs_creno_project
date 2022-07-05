/********************************************************************************
** Form generated from reading UI file 'tab2_connecting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2_CONNECTING_H
#define UI_TAB2_CONNECTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab2_connecting
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pB_connect;
    QPushButton *pB_close;
    QTextBrowser *log;

    void setupUi(QWidget *tab2_connecting)
    {
        if (tab2_connecting->objectName().isEmpty())
            tab2_connecting->setObjectName(QString::fromUtf8("tab2_connecting"));
        tab2_connecting->resize(1071, 607);
        verticalLayout = new QVBoxLayout(tab2_connecting);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pB_connect = new QPushButton(tab2_connecting);
        pB_connect->setObjectName(QString::fromUtf8("pB_connect"));

        horizontalLayout->addWidget(pB_connect);

        pB_close = new QPushButton(tab2_connecting);
        pB_close->setObjectName(QString::fromUtf8("pB_close"));

        horizontalLayout->addWidget(pB_close);


        verticalLayout->addLayout(horizontalLayout);

        log = new QTextBrowser(tab2_connecting);
        log->setObjectName(QString::fromUtf8("log"));

        verticalLayout->addWidget(log);


        retranslateUi(tab2_connecting);

        QMetaObject::connectSlotsByName(tab2_connecting);
    } // setupUi

    void retranslateUi(QWidget *tab2_connecting)
    {
        tab2_connecting->setWindowTitle(QCoreApplication::translate("tab2_connecting", "Form", nullptr));
        pB_connect->setText(QCoreApplication::translate("tab2_connecting", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        pB_close->setText(QCoreApplication::translate("tab2_connecting", "\354\227\260\352\262\260 \355\225\264\354\240\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tab2_connecting: public Ui_tab2_connecting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2_CONNECTING_H
