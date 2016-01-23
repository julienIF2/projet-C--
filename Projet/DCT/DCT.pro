#-------------------------------------------------
#
# Project created by QtCreator 2016-01-13T20:01:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DCT
TEMPLATE = app


SOURCES += main.cpp\
        ihm.cpp \
    qcustomplot.cpp \
    transform.cpp \
    signaux.cpp \
    signalcsv.cpp \
    signaltxt.cpp \
    signalwav.cpp

HEADERS  += ihm.h \
    qcustomplot.h \
    transform.h \
    signaux.h \
    signalcsv.h \
    signaltxt.h \
    signalwav.h

FORMS    += ihm.ui

QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp
