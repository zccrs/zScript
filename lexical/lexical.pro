QT += core
QT -= gui

CONFIG += c++11

TARGET = lexical
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lfl

SOURCES += $$PWD/lex.yy.c

OTHER_FILES += zScript.lt

system(flex $$PWD/zScript.lt)

DESTDIR = $$shadowed($$PWD/../bin)
