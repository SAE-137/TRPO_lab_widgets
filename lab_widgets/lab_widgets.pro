QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Добавьте эти строки для корректной работы с кириллицей
CONFIG += utf8_source
QMAKE_CXXFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
DEFINES += QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII

SOURCES += \
    main.cpp \
    squaring.cpp \
    strvalidator.cpp \
    widget.cpp \
    win.cpp

HEADERS += \
    squaring.h \
    strvalidator.h \
    widget.h \
    win.h

FORMS += \
    widget.ui
