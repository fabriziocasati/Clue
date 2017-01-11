QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clue_Solver
TEMPLATE = app


SOURCES += \
    Game.cpp \
    Inquiry.cpp \
    Main.cpp \
    NewGameCreator.cpp \
    Player.cpp

HEADERS += \
    Game.h \
    Inquiry.h \
    NewGameCreator.h \
    Player.h

RESOURCES += \
    resources.qrc

# Subfolders
include(reasoner/reasoner.pri)
include(gui/gui.pri)
