TARGET = zScript

QT += core
QT -= gui

CONFIG += c++11

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

include($$PWD/lexical/lexical.pri)
include($$PWD/syntax/syntax.pri)
include($$PWD/common.pri)

DESTDIR = $$shadowed($$PWD/../bin)
