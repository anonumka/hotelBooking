QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    auth.cpp \
    bookedroom.cpp \
    bookingroom.cpp \
    editroom.cpp \
    listusers.cpp \
    main.cpp \
    mainwindow.cpp \
    recordingusers.cpp \
    room.cpp \
    roomtable.cpp \
    user.cpp

HEADERS += \
    auth.hpp \
    bookedroom.hpp \
    bookingroom.hpp \
    config.hpp \
    editroom.hpp \
    listusers.hpp \
    mainwindow.hpp \
    recordingusers.hpp \
    room.hpp \
    roomtable.hpp \
    user.hpp

FORMS += \
    auth.ui \
    bookingroom.ui \
    dialogbkdroom.ui \
    editroom.ui \
    listusers.ui \
    mainwindow.ui \
    recordingusers.ui

CONFIG += c++11

RESOURCES += \
    resources.qrc