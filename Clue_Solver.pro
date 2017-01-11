QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clue_Solver
TEMPLATE = app


SOURCES += \
    Game.cpp \
    Inquiry.cpp \
    NewGameCreator.cpp \
    Player.cpp \
    ClueSolver.cpp \
    main.cpp \
    Main.cpp

HEADERS += \
    Game.h \
    Inquiry.h \
    NewGameCreator.h \
    Player.h \
    ClueSolver.h \
    Main.h

RESOURCES += \
    resources.qrc

# Subfolders
include(reasoner/reasoner.pri)
include(gui/gui.pri)
