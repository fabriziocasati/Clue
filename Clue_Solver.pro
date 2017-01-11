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
    window.cpp \
    window2.cpp \
    querylist.cpp \
    sheet.cpp \
    playercards.cpp \
    player.cpp \
    mysubwindow.cpp \
    InquiryHistoryWindow.cpp \
    MainWindow.cpp \
    NumberOfCardsForEachPlayerWindow.cpp \
    Game.cpp \
    GameWindow.cpp \
    Inquiry.cpp \
    Main.cpp \
    NewGameCreator.cpp \
    Reasoner.cpp

HEADERS += \
    window.h \
    window2.h \
    querylist.h \
    sheet.h \
    playercards.h \
    player.h \
    mysubwindow.h \
    InquiryHistoryWindow.h \
    MainWindow.h \
    NumberOfCardsForEachPlayerWindow.h \
    Game.h \
    GameWindow.h \
    Inquiry.h \
    NewGameCreator.h \
    Reasoner.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

# Subfolders
include(reasoner/reasoner.pri)
include(gui/gui.pri)
