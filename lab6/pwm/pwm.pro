#-------------------------------------------------
#
# Project created by QtCreator 2017-11-01T16:16:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pwm
TEMPLATE = app


SOURCES += main.cpp \
    bcm2835_stub.cpp \
    pin.cpp \
    pwm.cpp

HEADERS  += \
    pin.h \
    bcm2835.h \
    pwm.h

FORMS    += mainwindow.ui
