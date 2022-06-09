QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwidget.cpp \
    socketclient.cpp \
    tab1opencv_stream_test.cpp \
    tab2socketclient.cpp \
    tab3controlpannel.cpp \
    tab4sensordisplay.cpp

HEADERS += \
    mainwidget.h \
    socketclient.h \
    tab1opencv_stream_test.h \
    tab2socketclient.h \
    tab3controlpannel.h \
    tab4sensordisplay.h

FORMS += \
    mainwidget.ui \
    tab1opencv_stream_test.ui \
    tab2socketclient.ui \
    tab3controlpannel.ui \
    tab4sensordisplay.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IotQtClient.qrc
