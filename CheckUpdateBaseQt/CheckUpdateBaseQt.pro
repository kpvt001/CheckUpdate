#-------------------------------------------------
#
# Project created by QtCreator 2016-10-20T05:26:46
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = CheckUpdateBaseQt
TEMPLATE = lib

DEFINES += CHECKUPDATEBASEQT_LIBRARY

SOURCES += CheckUpdateBaseQt.cpp \
    CheckUpdateBaseQtImpl.cpp \
    CheckUpdateBaseQtResult.cpp \
    CheckUpdateBaseQtError.cpp \
    CheckUpdateBaseQtErrorImpl.cpp \
    CheckUpdateBaseQtResultImpl.cpp

HEADERS += CheckUpdateBaseQt.h\
        checkupdatebaseqt_global.h \
    CheckUpdateBaseQtImpl.h \
    CheckUpdateBaseQtResult.h \
    CheckUpdateBaseQtError.h \
    CheckUpdateBaseQtErrorImpl.h \
    CheckUpdateBaseQtResultImpl.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
