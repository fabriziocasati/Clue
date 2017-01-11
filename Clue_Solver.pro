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
    Game.cpp \
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
    Game.h \
    Inquiry.h \
    NewGameCreator.h \
    Reasoner.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

# Subfolders
include(reasoner/reasoner.pri)
include(gui/gui.pri)
