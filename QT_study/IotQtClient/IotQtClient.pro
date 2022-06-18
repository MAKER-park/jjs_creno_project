QT       += core gui network charts sql webenginewidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwidget.cpp \
    socketclient.cpp \
    tab1_stream.cpp \
    tab2socketclient.cpp \
    tab3controlpannel.cpp \
    tab4sensordisplay.cpp \
    tab5_chart.cpp \
    tab6_db_view.cpp

HEADERS += \
    mainwidget.h \
    socketclient.h \
    tab1_stream.h \
    tab2socketclient.h \
    tab3controlpannel.h \
    tab4sensordisplay.h \
    tab5_chart.h \
    tab6_db_view.h

FORMS += \
    mainwidget.ui \
    tab1_stream.ui \
    tab2socketclient.ui \
    tab3controlpannel.ui \
    tab4sensordisplay.ui \
    tab5_chart.ui \
    tab6_db_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IotQtClient.qrc
