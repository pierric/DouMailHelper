#-------------------------------------------------
#
# Project created by QtCreator 2010-06-30T22:10:42
#
#-------------------------------------------------

TARGET = tests
TEMPLATE = app

SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

INCLUDEPATH += ../include
LIBS += -ldou -L../debug
