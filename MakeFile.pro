#-------------------------------------------------
#
# Project created by QtCreator 2016-05-26T21:34:31
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app


SOURCES += main.cpp \
    gamewidget.cpp \
    loading.cpp \
    menu.cpp \
    game.cpp \
    play.cpp \
    snake.cpp \
    food.cpp \
    table.cpp

HEADERS  += gamewidget.h \
    game.h \
    state.h \
    loading.h \
    menu.h \
    play.h \
    snake.h \
    food.h \
    table.h

RESOURCES += img.qrc
