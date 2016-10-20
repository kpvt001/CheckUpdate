#-------------------------------------------------
#
# Project created by QtCreator 2016-10-20T09:42:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestGui
TEMPLATE = app

#LIBS += $$PWD/CheckUpdateBaseQt.lib
LIBS += -L$$PWD -lCheckUpdateBaseQt
SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    CheckUpdateBaseQt.h \
    checkupdatebaseqt_global.h \
    CheckUpdateBaseQtError.h \
    CheckUpdateBaseQtResult.h

FORMS    += mainwindow.ui

message($$PWD)


