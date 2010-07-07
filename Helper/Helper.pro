# -------------------------------------------------
# Project created by QtCreator 2010-06-30T12:00:52
# -------------------------------------------------
QT += xml
TARGET = dou
TEMPLATE = app
FORMS += mainwindow.ui
HEADERS += helpermainwindow.h \
    objects.h \
    persistence.h
SOURCES += helpermainwindow.cpp \
    main.cpp \
    persistence.cpp \
    objects.cpp
INCLUDEPATH += ../libdou/include
debug:LIBS += -ldou \
    -L../libdou/debug
release:LIBS += -ldou \
    -L../libdou/release
RESOURCES += resource.qrc
