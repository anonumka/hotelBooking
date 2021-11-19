QT += testlib
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

CONFIG += c++17

TEMPLATE = lib

SOURCES +=  testlib.cpp

HEADERS +=  testlib.hpp
