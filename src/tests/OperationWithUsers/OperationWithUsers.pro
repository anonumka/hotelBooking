QT += testlib
QT += testlib
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase
CONFIG += c++17

TEMPLATE = app

SOURCES += \
    ../../testlib/testlib.cpp \
    tst_operationwithusers.cpp \
    ../../lib/bookedroom.cpp \
    ../../lib/recordingusers.cpp \
    ../../lib/user.cpp


HEADERS += \
    ../../testlib/testlib.hpp \
    ../../lib/recordingusers.hpp \
    ../../lib/bookedroom.hpp \
    ../../lib/user.hpp

FORMS += \
    ../../lib/recordingusers.ui \
