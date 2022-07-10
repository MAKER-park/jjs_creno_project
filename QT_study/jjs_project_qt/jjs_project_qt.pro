QT       += core gui network charts sql webenginewidgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    socketclient.cpp \
    tab1_camera_view.cpp \
    tab2_connecting.cpp

HEADERS += \
    mainwindow.h \
    socketclient.h \
    tab1_camera_view.h \
    tab2_connecting.h

FORMS += \
    mainwindow.ui \
    tab1_camera_view.ui \
    tab2_connecting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
