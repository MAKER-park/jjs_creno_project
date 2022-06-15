TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += /opt/homebrew/opt/opencv@4/include/opencv4/
LIBS += `pkg-config --libs opencv4`

