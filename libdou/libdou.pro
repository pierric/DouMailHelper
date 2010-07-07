# -------------------------------------------------
# Project created by QtCreator 2010-06-30T12:00:52
# -------------------------------------------------
QT += xml
QT -= gui
TARGET = dou
TEMPLATE = lib
DEFINES += CURL_STATICLIB
DEFINES += LIBDOU_LIBRARY
SOURCES += src/mail.cpp \
    src/service.cpp \
    src/users.cpp
HEADERS += include/mail.h \
    include/libdou_global.h \
    include/libdou.h \
    include/service.h \
    include/users.h
INCLUDEPATH += "include"
INCLUDEPATH += D:/MSYS/MSYS/mingw/include
LIBS += -LD:/MSYS/MSYS/mingw/lib \
    -loauth \
    -lcurl \
    -lssl \
    -lcrypto \
    -lz \
    -lwldap32 \
    -lgdi32 \
    -lws2_32
debug:DLLDESTDIR   += ../Helper/debug tests/debug
release:DLLDESTDIR += ../Helper/release tests/release
