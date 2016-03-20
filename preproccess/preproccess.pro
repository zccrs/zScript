QT += core
QT -= gui

CONFIG += c++11

TARGET = preproccess
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += $$PWD/main.cpp

include(../common.pri)
