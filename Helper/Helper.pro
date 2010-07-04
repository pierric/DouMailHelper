# -------------------------------------------------
# Project created by QtCreator 2010-06-30T12:00:52
# -------------------------------------------------
QT += xml
TARGET = dou
TEMPLATE = app
FORMS += mainwindow.ui
HEADERS += helpermainwindow.h
SOURCES += helpermainwindow.cpp \
    main.cpp
INCLUDEPATH += ../libdou/include
debug:LIBS += -ldou \
    -L../libdou/debug
release:LIBS += -ldou \
    -L../libdou/release
