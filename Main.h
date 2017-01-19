#ifndef MAIN_H
#define MAIN_H

#include "game/Game.h"
#include "gui/MainWindow.h"

class MainWindow;

class Main
{
public:
    Main();
    void createNewGame();
    void setMainWindow(MainWindow *mainWindow);

private:
    MainWindow *mainWindow;
};

#endif // MAIN_H
