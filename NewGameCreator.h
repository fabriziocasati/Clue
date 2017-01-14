#ifndef NEWGAMECREATOR_H
#define NEWGAMECREATOR_H

#include "gui/MainWindow.h"
#include "Game.h"
#include "gui/NumberOfPlayersWindow.h"
#include "gui/NamesOfThePlayersWindow.h"

class MainWindow;

class NewGameCreator
{
public:
    NewGameCreator(MainWindow *mainWindow);
    void openNextWindow(int numberOfPlayers);

private:
    Game *game;
    MainWindow *mainWindow;
    int numberOfPlayers;
};

#endif // NEWGAMECREATOR_H
