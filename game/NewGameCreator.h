#ifndef NEWGAMECREATOR_H
#define NEWGAMECREATOR_H

#include "gui/MainWindow.h"
#include "Game.h"
#include "gui/NumberOfPlayersWindow.h"
#include "gui/NamesOfThePlayersWindow.h"
#include "gui/NumberOfCardsForEachPlayerWindow.h"
#include "gui/CardsOfTheUserWindow.h"
#include "gui/RecapWindow.h"

class MainWindow;

class NewGameCreator
{
public:
    NewGameCreator(MainWindow *mainWindow);
    void openNextWindow();
    void setNumberOfPlayers(int numberOfPlayers);
    int getNumberOfPlayers();
    void setNamesOfThePlayers(std::vector<QString> playerName);
    std::vector<QString> getNamesOfThePlayers();
    void setNumberOfCardsForEachPlayer(std::vector<int> playerCardsNumber);
    void setCardsOfTheUser(std::vector<QString> userCards);
    std::vector<QString> getCardsOfTheUser();
    std::vector<int> getNumberOfCardsForEachPlayer();

    std::vector<QString> suspectCardList;
    std::vector<QString> weaponCardList;
    std::vector<QString> roomCardList;

    std::vector<QString> getRoomCardList();
    std::vector<QString> getSuspectCardList();
    std::vector<QString> getWeaponCardList();

private:
    int numberOfOpenedWindows;
    Game *game;
    MainWindow *mainWindow;
    int numberOfPlayers;
    std::vector<QString> playerName;
    std::vector<int> playerCardsNumber;
    std::vector<QString> userCards;

private slots:

};

#endif // NEWGAMECREATOR_H
