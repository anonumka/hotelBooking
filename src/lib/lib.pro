QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    auth.cpp \
    bookedroom.cpp \
    bookingroom.cpp \
    database.cpp \
    editroom.cpp \
    listusers.cpp \
    main.cpp \
    mainwindow.cpp \
    recordingusers.cpp \
    room.cpp \
    user.cpp

HEADERS += \
    auth.hpp \
    bookedroom.hpp \
    bookingroom.hpp \
    config.hpp \
    database.hpp \
    editroom.hpp \
    listusers.hpp \
    mainwindow.hpp \
    recordingusers.hpp \
    room.hpp \
    user.hpp

FORMS += \
    auth.ui \
    bookingroom.ui \
    dialogbkdroom.ui \
    editroom.ui \
    listusers.ui \
    mainwindow.ui \
    recordingusers.ui

CONFIG += c++17

RESOURCES += \
    resources.qrc
