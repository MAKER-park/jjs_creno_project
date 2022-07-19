QT       += core gui network charts sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwidget.cpp \
    socketclient.cpp \
    tab2socketclient.cpp \
    tab3controlpannel.cpp \
    tab4sensordisplay.cpp \
    tab5chatplot.cpp \
    tab6database.cpp \
    tab7databasechartplot.cpp

HEADERS += \
    mainwidget.h \
    socketclient.h \
    tab2socketclient.h \
    tab3controlpannel.h \
    tab4sensordisplay.h \
    tab5chatplot.h \
    tab6database.h \
    tab7databasechartplot.h

FORMS += \
    mainwidget.ui \
    tab2socketclient.ui \
    tab3controlpannel.ui \
    tab4sensordisplay.ui \
    tab5chatplot.ui \
    tab6database.ui \
    tab7databasechartplot.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IotQtClient.qrc
