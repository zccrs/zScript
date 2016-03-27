QT += core
QT -= gui

CONFIG += c++11

TARGET = syntax
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lfl

HEADERS += \
        $$PWD/zScript.tab.h

SOURCES += \
        $$PWD/zScript.tab.c

OTHER_FILES += $$PWD/zScript.y

system(bison -d -v $$PWD/zScript.y)

DESTDIR = $$shadowed($$PWD/../bin)
