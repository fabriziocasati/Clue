#ifndef NEWGAMECREATOR_H
#define NEWGAMECREATOR_H

#include "gui/MainWindow.h"
#include "Game.h"
#include "gui/NumberOfPlayersWindow.h"
#include "gui/NamesOfThePlayersWindow.h"
#include "gui/NumberOfCardsForEachPlayerWindow.h"

class MainWindow;

class NewGameCreator
{
public:
    NewGameCreator(MainWindow *mainWindow);
    void openNextWindow();
    void setNumberOfPlayers(int numberOfPlayers);
    void setNamesOfThePlayers(std::string *playerName);
    int getNumberOfPlayers();

private:
    int numberOfOpenedWindows;
    Game *game;
    MainWindow *mainWindow;
    int numberOfPlayers;
    std::string *playerName;
};

#endif // NEWGAMECREATOR_H
