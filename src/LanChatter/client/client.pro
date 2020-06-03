######################################################################
# Automatically generated by qmake (3.1) Tue Jun 2 13:27:50 2020
######################################################################

QT += widgets gui core
TEMPLATE = app
TARGET = client
INCLUDEPATH +=  . \
            ../../../3rdparty/

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
# HEADERS += client.h ../../../3rdparty/json.hpp
HEADERS += \
    ../../../3rdparty/json.hpp  \
    clientwin.h \
    menubutton.h 
# SOURCES +=  main.cpp client.cpp
SOURCES += \
    main.cpp \
    clientwin.cpp \
    menubutton.cpp

CONFIG += c++11
LIBS += libws2_32

FORMS += \
    clientwin.ui

HEADERS += \
    clientwin.h

RESOURCES += images.qrc