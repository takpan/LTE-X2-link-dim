#-------------------------------------------------
#
# Project created by QtCreator 2015-11-24T12:09:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = X2_link
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tablemanipulation.cpp \
    tablemodel.cpp \
    mathfunctions.cpp \
    plotgraphs.cpp \
    qcustomplot.cpp \
    plotoutputdialog.cpp \
    exportdialog.cpp

HEADERS  += mainwindow.h \
    tablemanipulation.h \
    tablemodel.h \
    mathfunctions.h \
    plotgraphs.h \
    qcustomplot.h \
    plotoutputdialog.h \
    exportdialog.h

FORMS    += mainwindow.ui \
    plotoutputdialog.ui \
    exportdialog.ui
