#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T10:32:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drum.cpp \
    start.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    drum.h \
    start.h \
    result.h

FORMS    += mainwindow.ui \
    start.ui \
    result.ui

RESOURCES += \
    resource.qrc
