/********************************************************************************
** Form generated from reading UI file 'tab2socketclient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2SOCKETCLIENT_H
#define UI_TAB2SOCKETCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab2SocketClient
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *pLabel;
    QPushButton *pPBRecvDataClear;
    QPushButton *pPBServerConnect;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *pTERecvData;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pLERecvId;
    QLineEdit *pLESendData;
    QPushButton *pPBSendButton;

    void setupUi(QWidget *Tab2SocketClient)
    {
        if (Tab2SocketClient->objectName().isEmpty())
            Tab2SocketClient->setObjectName(QString::fromUtf8("Tab2SocketClient"));
        Tab2SocketClient->resize(554, 344);
        verticalLayout = new QVBoxLayout(Tab2SocketClient);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, 5, 5);
        pLabel = new QLabel(Tab2SocketClient);
        pLabel->setObjectName(QString::fromUtf8("pLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("HY\352\266\201\354\204\234"));
        font.setPointSize(14);
        pLabel->setFont(font);

        horizontalLayout->addWidget(pLabel);

        pPBRecvDataClear = new QPushButton(Tab2SocketClient);
        pPBRecvDataClear->setObjectName(QString::fromUtf8("pPBRecvDataClear"));

        horizontalLayout->addWidget(pPBRecvDataClear);

        pPBServerConnect = new QPushButton(Tab2SocketClient);
        pPBServerConnect->setObjectName(QString::fromUtf8("pPBServerConnect"));
        pPBServerConnect->setCheckable(true);

        horizontalLayout->addWidget(pPBServerConnect);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pTERecvData = new QTextEdit(Tab2SocketClient);
        pTERecvData->setObjectName(QString::fromUtf8("pTERecvData"));
#if QT_CONFIG(accessibility)
        pTERecvData->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)

        horizontalLayout_2->addWidget(pTERecvData);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(8);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pLERecvId = new QLineEdit(Tab2SocketClient);
        pLERecvId->setObjectName(QString::fromUtf8("pLERecvId"));

        horizontalLayout_3->addWidget(pLERecvId);

        pLESendData = new QLineEdit(Tab2SocketClient);
        pLESendData->setObjectName(QString::fromUtf8("pLESendData"));

        horizontalLayout_3->addWidget(pLESendData);

        pPBSendButton = new QPushButton(Tab2SocketClient);
        pPBSendButton->setObjectName(QString::fromUtf8("pPBSendButton"));

        horizontalLayout_3->addWidget(pPBSendButton);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 7);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Tab2SocketClient);

        QMetaObject::connectSlotsByName(Tab2SocketClient);
    } // setupUi

    void retranslateUi(QWidget *Tab2SocketClient)
    {
        Tab2SocketClient->setWindowTitle(QCoreApplication::translate("Tab2SocketClient", "Form", nullptr));
        pLabel->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240\353\215\260\354\235\264\355\204\260", nullptr));
        pPBRecvDataClear->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240\354\202\255\354\240\234", nullptr));
        pPBServerConnect->setText(QCoreApplication::translate("Tab2SocketClient", "\354\204\234\353\262\204\354\227\260\352\262\260", nullptr));
        pPBSendButton->setText(QCoreApplication::translate("Tab2SocketClient", "\354\240\204\354\206\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab2SocketClient: public Ui_Tab2SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2SOCKETCLIENT_H
