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
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *pLabel;
    QPushButton *pPB_RecvDataClear;
    QPushButton *pPB_ServerConnect;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *pTE_RecvData;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pLE_Recvid;
    QLineEdit *pLE_SendData;
    QPushButton *pPB_SendButton;

    void setupUi(QWidget *Tab2SocketClient)
    {
        if (Tab2SocketClient->objectName().isEmpty())
            Tab2SocketClient->setObjectName(QString::fromUtf8("Tab2SocketClient"));
        Tab2SocketClient->resize(591, 484);
        verticalLayout_2 = new QVBoxLayout(Tab2SocketClient);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        pLabel = new QLabel(Tab2SocketClient);
        pLabel->setObjectName(QString::fromUtf8("pLabel"));

        horizontalLayout->addWidget(pLabel);

        pPB_RecvDataClear = new QPushButton(Tab2SocketClient);
        pPB_RecvDataClear->setObjectName(QString::fromUtf8("pPB_RecvDataClear"));

        horizontalLayout->addWidget(pPB_RecvDataClear);

        pPB_ServerConnect = new QPushButton(Tab2SocketClient);
        pPB_ServerConnect->setObjectName(QString::fromUtf8("pPB_ServerConnect"));
        pPB_ServerConnect->setCheckable(true);

        horizontalLayout->addWidget(pPB_ServerConnect);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pTE_RecvData = new QTextEdit(Tab2SocketClient);
        pTE_RecvData->setObjectName(QString::fromUtf8("pTE_RecvData"));
        pTE_RecvData->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(pTE_RecvData);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pLE_Recvid = new QLineEdit(Tab2SocketClient);
        pLE_Recvid->setObjectName(QString::fromUtf8("pLE_Recvid"));

        horizontalLayout_3->addWidget(pLE_Recvid);

        pLE_SendData = new QLineEdit(Tab2SocketClient);
        pLE_SendData->setObjectName(QString::fromUtf8("pLE_SendData"));

        horizontalLayout_3->addWidget(pLE_SendData);

        pPB_SendButton = new QPushButton(Tab2SocketClient);
        pPB_SendButton->setObjectName(QString::fromUtf8("pPB_SendButton"));

        horizontalLayout_3->addWidget(pPB_SendButton);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 6);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(Tab2SocketClient);

        QMetaObject::connectSlotsByName(Tab2SocketClient);
    } // setupUi

    void retranslateUi(QWidget *Tab2SocketClient)
    {
        Tab2SocketClient->setWindowTitle(QCoreApplication::translate("Tab2SocketClient", "Form", nullptr));
        pLabel->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240\353\215\260\354\235\264\355\204\260", nullptr));
        pPB_RecvDataClear->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240\354\202\255\354\240\234", nullptr));
        pPB_ServerConnect->setText(QCoreApplication::translate("Tab2SocketClient", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        pPB_SendButton->setText(QCoreApplication::translate("Tab2SocketClient", "\354\206\241\354\213\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab2SocketClient: public Ui_Tab2SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2SOCKETCLIENT_H
