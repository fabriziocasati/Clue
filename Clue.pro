#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T23:34:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clue
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    window.cpp \
    window2.cpp \
    numberofplayers.cpp \
    namesoftheplayers.cpp \
    numberofcardsforeachplayerwindow.cpp \
    game.cpp \
    querylist.cpp \
    query.cpp \
    sheet.cpp \
    playercards.cpp \
    player.cpp \
    solver.cpp

HEADERS  += mainwindow.h \
    window.h \
    window2.h \
    numberofplayers.h \
    namesoftheplayers.h \
    numberofcardsforeachplayerwindow.h \
    game.h \
    querylist.h \
    query.h \
    sheet.h \
    playercards.h \
    player.h \
    solver.h

FORMS    += mainwindow.ui
