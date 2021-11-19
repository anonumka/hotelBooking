QT += testlib
QT += testlib
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase
CONFIG += c++17

TEMPLATE = app

SOURCES += \
    ../../testlib/testlib.cpp \
    tst_tst_operationwithrooms.cpp \
    ../../lib/editroom.cpp \
    ../../lib/room.cpp \

HEADERS += \
    ../../testlib/testlib.hpp \
    ../../lib/editroom.hpp \
    ../../lib/room.hpp \

FORMS += \
    ../../lib/editroom.ui
