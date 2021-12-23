QT += testlib
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase
CONFIG += c++17

TEMPLATE = app

SOURCES += \
    tst_operationwithusers.cpp \
    ../../lib/bookedroom.cpp \
    ../../lib/recordingusers.cpp \
    ../../lib/user.cpp


HEADERS += \
    ../../lib/recordingusers.hpp \
    ../../lib/bookedroom.hpp \
    ../../lib/user.hpp

FORMS += \
    ../../lib/recordingusers.ui \
