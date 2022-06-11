/********************************************************************************
** Form generated from reading UI file 'tab6_db_view.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB6_DB_VIEW_H
#define UI_TAB6_DB_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab6_DB_View
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *pdateTimeEdit_from;
    QDateTimeEdit *pdateTimeEdit_to;
    QPushButton *pPB_search;
    QPushButton *pPB_delete;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *pTableWidget;

    void setupUi(QWidget *tab6_DB_View)
    {
        if (tab6_DB_View->objectName().isEmpty())
            tab6_DB_View->setObjectName(QString::fromUtf8("tab6_DB_View"));
        tab6_DB_View->resize(874, 495);
        verticalLayout = new QVBoxLayout(tab6_DB_View);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pdateTimeEdit_from = new QDateTimeEdit(tab6_DB_View);
        pdateTimeEdit_from->setObjectName(QString::fromUtf8("pdateTimeEdit_from"));
        pdateTimeEdit_from->setDateTime(QDateTime(QDate(2022, 6, 10), QTime(16, 0, 0)));

        horizontalLayout->addWidget(pdateTimeEdit_from);

        pdateTimeEdit_to = new QDateTimeEdit(tab6_DB_View);
        pdateTimeEdit_to->setObjectName(QString::fromUtf8("pdateTimeEdit_to"));
        pdateTimeEdit_to->setDateTime(QDateTime(QDate(2022, 6, 10), QTime(16, 0, 0)));

        horizontalLayout->addWidget(pdateTimeEdit_to);

        pPB_search = new QPushButton(tab6_DB_View);
        pPB_search->setObjectName(QString::fromUtf8("pPB_search"));

        horizontalLayout->addWidget(pPB_search);

        pPB_delete = new QPushButton(tab6_DB_View);
        pPB_delete->setObjectName(QString::fromUtf8("pPB_delete"));

        horizontalLayout->addWidget(pPB_delete);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pTableWidget = new QTableWidget(tab6_DB_View);
        if (pTableWidget->columnCount() < 5)
            pTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        pTableWidget->setObjectName(QString::fromUtf8("pTableWidget"));
        pTableWidget->horizontalHeader()->setDefaultSectionSize(170);

        horizontalLayout_2->addWidget(pTableWidget);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(tab6_DB_View);

        QMetaObject::connectSlotsByName(tab6_DB_View);
    } // setupUi

    void retranslateUi(QWidget *tab6_DB_View)
    {
        tab6_DB_View->setWindowTitle(QCoreApplication::translate("tab6_DB_View", "Form", nullptr));
        pPB_search->setText(QCoreApplication::translate("tab6_DB_View", "\354\241\260\355\232\214", nullptr));
        pPB_delete->setText(QCoreApplication::translate("tab6_DB_View", "\354\202\255\354\240\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = pTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("tab6_DB_View", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = pTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("tab6_DB_View", "date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = pTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("tab6_DB_View", "lux", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = pTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("tab6_DB_View", "temp", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = pTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("tab6_DB_View", "hum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tab6_DB_View: public Ui_tab6_DB_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB6_DB_VIEW_H
