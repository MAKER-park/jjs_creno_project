/********************************************************************************
** Form generated from reading UI file 'tab4sensordisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB4SENSORDISPLAY_H
#define UI_TAB4SENSORDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab4SensorDisplay
{
public:
    QGridLayout *gridLayout;
    QTextEdit *pTETemp;
    QTextEdit *pTEPhoto;
    QLabel *pLtemp;
    QLabel *pLHumi;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QLabel *pLPhoto;
    QTextEdit *pTEHumi;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Tab4SensorDisplay)
    {
        if (Tab4SensorDisplay->objectName().isEmpty())
            Tab4SensorDisplay->setObjectName(QString::fromUtf8("Tab4SensorDisplay"));
        Tab4SensorDisplay->resize(544, 355);
        gridLayout = new QGridLayout(Tab4SensorDisplay);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 30, 9, 30);
        pTETemp = new QTextEdit(Tab4SensorDisplay);
        pTETemp->setObjectName(QString::fromUtf8("pTETemp"));
        pTETemp->setEnabled(true);
        QPalette palette;
        QBrush brush(QColor(0, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 255, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pTETemp->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        pTETemp->setFont(font);
        pTETemp->setFocusPolicy(Qt::NoFocus);
        pTETemp->setFrameShape(QFrame::NoFrame);
        pTETemp->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(pTETemp, 2, 1, 1, 1);

        pTEPhoto = new QTextEdit(Tab4SensorDisplay);
        pTEPhoto->setObjectName(QString::fromUtf8("pTEPhoto"));
        pTEPhoto->setEnabled(true);
        QPalette palette1;
        QBrush brush4(QColor(255, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush4);
        QBrush brush5(QColor(170, 170, 255, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pTEPhoto->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(28);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        pTEPhoto->setFont(font1);
        pTEPhoto->setFocusPolicy(Qt::NoFocus);
        pTEPhoto->setContextMenuPolicy(Qt::DefaultContextMenu);
        pTEPhoto->setLayoutDirection(Qt::LeftToRight);
        pTEPhoto->setFrameShape(QFrame::NoFrame);
        pTEPhoto->setFrameShadow(QFrame::Plain);
        pTEPhoto->setLineWidth(0);
        pTEPhoto->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        pTEPhoto->setUndoRedoEnabled(false);
        pTEPhoto->setMarkdown(QString::fromUtf8(""));
        pTEPhoto->setAcceptRichText(true);

        gridLayout->addWidget(pTEPhoto, 0, 1, 1, 1);

        pLtemp = new QLabel(Tab4SensorDisplay);
        pLtemp->setObjectName(QString::fromUtf8("pLtemp"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pLtemp->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\355\234\264\353\250\274\353\252\250\354\235\214T"));
        font2.setPointSize(36);
        pLtemp->setFont(font2);
        pLtemp->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(pLtemp, 2, 0, 1, 1);

        pLHumi = new QLabel(Tab4SensorDisplay);
        pLHumi->setObjectName(QString::fromUtf8("pLHumi"));
        QPalette palette3;
        QBrush brush6(QColor(0, 0, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        QBrush brush7(QColor(0, 0, 255, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pLHumi->setPalette(palette3);
        pLHumi->setFont(font2);
        pLHumi->setTabletTracking(false);
        pLHumi->setAutoFillBackground(false);
        pLHumi->setScaledContents(false);
        pLHumi->setAlignment(Qt::AlignCenter);
        pLHumi->setWordWrap(false);

        gridLayout->addWidget(pLHumi, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pLPhoto = new QLabel(Tab4SensorDisplay);
        pLPhoto->setObjectName(QString::fromUtf8("pLPhoto"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        QBrush brush8(QColor(255, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pLPhoto->setPalette(palette4);
        pLPhoto->setFont(font2);
        pLPhoto->setLayoutDirection(Qt::LeftToRight);
        pLPhoto->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(pLPhoto, 0, 0, 1, 1);

        pTEHumi = new QTextEdit(Tab4SensorDisplay);
        pTEHumi->setObjectName(QString::fromUtf8("pTEHumi"));
        pTEHumi->setEnabled(true);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pTEHumi->setPalette(palette5);
        pTEHumi->setFont(font);
        pTEHumi->setMouseTracking(true);
        pTEHumi->setFocusPolicy(Qt::NoFocus);
        pTEHumi->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(pTEHumi, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(Tab4SensorDisplay);

        QMetaObject::connectSlotsByName(Tab4SensorDisplay);
    } // setupUi

    void retranslateUi(QWidget *Tab4SensorDisplay)
    {
        Tab4SensorDisplay->setWindowTitle(QCoreApplication::translate("Tab4SensorDisplay", "Form", nullptr));
#if QT_CONFIG(whatsthis)
        pTEPhoto->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pTEPhoto->setHtml(QCoreApplication::translate("Tab4SensorDisplay", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Agency FB'; font-size:28pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pLtemp->setText(QCoreApplication::translate("Tab4SensorDisplay", "\354\230\250\353\217\204", nullptr));
        pLHumi->setText(QCoreApplication::translate("Tab4SensorDisplay", "\354\212\265\353\217\204", nullptr));
        pLPhoto->setText(QCoreApplication::translate("Tab4SensorDisplay", "\354\241\260\353\217\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab4SensorDisplay: public Ui_Tab4SensorDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB4SENSORDISPLAY_H
