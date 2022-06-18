QT += widgets

HEADERS       = 
SOURCES       =  opencvCam.cpp
               
#INCLUDEPATH += . /usr/local/include
#LIBS += `pkg-config opencv --cflags --libs`

INCLUDEPATH += /opt/homebrew/opt/opencv@4/include/opencv4
LIBS += `pkg-config opencv4 --cflags --libs`

#LIBS += `pkg-config --libs opencv4`
#LIBS += -L/opt/homebrew/opt/opencv/lib
#LIBS += "/opt/homebrew/opt/opencv/lib"
