QT += core
QT -= gui

CONFIG += c++11

TARGET = Polynomial
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    polynomial.cpp

HEADERS += \
    polynomial.h
