#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T21:21:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Core.cpp

HEADERS  += mainwindow.h \
    Core.h


FORMS    += \
    gui.ui
