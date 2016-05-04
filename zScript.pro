TARGET = zScript

QT += core concurrent
QT -= gui

CONFIG += c++11

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

include($$PWD/lexical/lexical.pri)
include($$PWD/syntax/syntax.pri)
include($$PWD/common/common.pri)
include($$PWD/base/base.pri)

#DESTDIR = $$shadowed($$PWD/../bin)

SOURCES += \
    main.cpp

target.path = /usr/bin/

INSTALLS += target
