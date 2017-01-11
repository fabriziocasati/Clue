#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T23:34:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clue_Solver
TEMPLATE = app


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    window.cpp \
    window2.cpp \
    numberofcardsforeachplayerwindow.cpp \
    game.cpp \
    querylist.cpp \
    sheet.cpp \
    playercards.cpp \
    player.cpp \
    newgamecreator.cpp \
    reasoner.cpp \
    inquiry.cpp \
    gamewindow.cpp \
    inquiryhistorywindow.cpp \
    mysubwindow.cpp \

HEADERS += \
    mainwindow.h \
    window.h \
    window2.h \
    numberofcardsforeachplayerwindow.h \
    game.h \
    querylist.h \
    sheet.h \
    playercards.h \
    player.h \
    newgamecreator.h \
    reasoner.h \
    inquiry.h \
    gamewindow.h \
    inquiryhistorywindow.h \
    mysubwindow.h \

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

# Subfolders
include(reasoner/reasoner.pri)
include(gui/gui.pri)
