QT += core widgets

CONFIG += c++11

TARGET = OpenCV-Player
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    player.cpp \
    framebuffer.cpp \
    framethread.cpp

LIBS += `pkg-config --libs opencv`

HEADERS += \
    player.h \
    framebuffer.h \
    framethread.h
