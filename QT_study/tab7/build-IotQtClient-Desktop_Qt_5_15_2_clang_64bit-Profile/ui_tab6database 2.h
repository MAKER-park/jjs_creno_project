/********************************************************************************
** Form generated from reading UI file 'tab6database.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB6DATABASE_H
#define UI_TAB6DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab6Database
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *pDateTimeEditFrom;
    QDateTimeEdit *pDateTimeEditTo;
    QSpacerItem *horizontalSpacer;
    QPushButton *pPBSearchButton;
    QPushButton *pPBDeleteButton;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *pTableWidget;

    void setupUi(QWidget *Tab6Database)
    {
        if (Tab6Database->objectName().isEmpty())
            Tab6Database->setObjectName(QString::fromUtf8("Tab6Database"));
        Tab6Database->resize(602, 355);
        verticalLayout_2 = new QVBoxLayout(Tab6Database);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pDateTimeEditFrom = new QDateTimeEdit(Tab6Database);
        pDateTimeEditFrom->setObjectName(QString::fromUtf8("pDateTimeEditFrom"));
        pDateTimeEditFrom->setDateTime(QDateTime(QDate(2022, 6, 10), QTime(0, 0, 0)));

        horizontalLayout->addWidget(pDateTimeEditFrom);

        pDateTimeEditTo = new QDateTimeEdit(Tab6Database);
        pDateTimeEditTo->setObjectName(QString::fromUtf8("pDateTimeEditTo"));
        pDateTimeEditTo->setDateTime(QDateTime(QDate(2022, 12, 31), QTime(23, 59, 59)));

        horizontalLayout->addWidget(pDateTimeEditTo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pPBSearchButton = new QPushButton(Tab6Database);
        pPBSearchButton->setObjectName(QString::fromUtf8("pPBSearchButton"));

        horizontalLayout->addWidget(pPBSearchButton);

        pPBDeleteButton = new QPushButton(Tab6Database);
        pPBDeleteButton->setObjectName(QString::fromUtf8("pPBDeleteButton"));

        horizontalLayout->addWidget(pPBDeleteButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pTableWidget = new QTableWidget(Tab6Database);
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
        pTableWidget->setFrameShadow(QFrame::Sunken);
        pTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pTableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        pTableWidget->setTextElideMode(Qt::ElideMiddle);
        pTableWidget->setSortingEnabled(true);
        pTableWidget->setColumnCount(5);
        pTableWidget->horizontalHeader()->setVisible(false);
        pTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        pTableWidget->horizontalHeader()->setMinimumSectionSize(40);
        pTableWidget->horizontalHeader()->setDefaultSectionSize(160);
        pTableWidget->horizontalHeader()->setHighlightSections(false);
        pTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        pTableWidget->horizontalHeader()->setStretchLastSection(false);
        pTableWidget->verticalHeader()->setCascadingSectionResizes(true);
        pTableWidget->verticalHeader()->setMinimumSectionSize(32);
        pTableWidget->verticalHeader()->setDefaultSectionSize(32);

        horizontalLayout_2->addWidget(pTableWidget);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);

        retranslateUi(Tab6Database);

        QMetaObject::connectSlotsByName(Tab6Database);
    } // setupUi

    void retranslateUi(QWidget *Tab6Database)
    {
        Tab6Database->setWindowTitle(QCoreApplication::translate("Tab6Database", "Form", nullptr));
        pPBSearchButton->setText(QCoreApplication::translate("Tab6Database", "\354\241\260\355\232\214", nullptr));
        pPBDeleteButton->setText(QCoreApplication::translate("Tab6Database", "\354\202\255\354\240\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = pTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Tab6Database", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = pTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Tab6Database", "\353\202\240\354\247\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = pTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Tab6Database", "\354\241\260\353\217\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = pTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Tab6Database", "\354\230\250\353\217\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = pTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Tab6Database", "\354\212\265\353\217\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab6Database: public Ui_Tab6Database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB6DATABASE_H
