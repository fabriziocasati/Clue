#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T23:34:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clue_Solver
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
    sheet.cpp \
    playercards.cpp \
    player.cpp \
    solver.cpp \
    newgamecreator.cpp \
    reasoner.cpp \
    newinquirywindow.cpp \
    inquiry.cpp \
    gamewindow.cpp \
    inquiryhistorywindow.cpp

HEADERS  += mainwindow.h \
    window.h \
    window2.h \
    numberofplayers.h \
    namesoftheplayers.h \
    numberofcardsforeachplayerwindow.h \
    game.h \
    querylist.h \
    sheet.h \
    playercards.h \
    player.h \
    solver.h \
    newgamecreator.h \
    reasoner.h \
    newinquirywindow.h \
    inquiry.h \
    gamewindow.h \
    inquiryhistorywindow.h

FORMS    += mainwindow.ui
