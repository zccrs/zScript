QT += core
QT -= gui

CONFIG += c++11

TARGET = lexical
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lfl

SOURCES += $$PWD/lex.yy.c

OTHER_FILES += zScript.l

system(flex $$PWD/zScript.l)

DESTDIR = $$shadowed($$PWD/../bin)
