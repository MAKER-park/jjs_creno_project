/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButtonInversion;
    QPushButton *pushButtonBlending;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(288, 154);
        pushButtonInversion = new QPushButton(Dialog);
        pushButtonInversion->setObjectName(QString::fromUtf8("pushButtonInversion"));
        pushButtonInversion->setGeometry(QRect(50, 60, 75, 23));
        pushButtonBlending = new QPushButton(Dialog);
        pushButtonBlending->setObjectName(QString::fromUtf8("pushButtonBlending"));
        pushButtonBlending->setGeometry(QRect(140, 60, 75, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButtonInversion->setText(QCoreApplication::translate("Dialog", "Inversion", nullptr));
        pushButtonBlending->setText(QCoreApplication::translate("Dialog", "Blending", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
