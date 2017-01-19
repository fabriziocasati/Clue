#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include "Inquiry.h"
#include "game/Player.h"
#include "gui/GameWindow.h"
#include "gui/MainWindow.h"
#include <QString>

class Inquiry;
class MainWindow;

class Game
{
public:
    Game(MainWindow *mainWindow, int numberOfPlayers, std::vector<QString> playerName, std::vector<int> playerCardsNumber, std::vector<QString> userCards);

    std::vector<QString> suspectCardList;
    std::vector<QString> weaponCardList;
    std::vector<QString> roomCardList;
    int playerNumberOfCards[];
    int numberOfPlayers;
    std::list<Inquiry*> *inquiryList;
    Player player[6];

    void addInquiry(Inquiry *q);
    std::vector<QString> getUserCards();

    std::vector<QString> userCards;
    std::vector<QString> playerName;

    std::vector<QString> getRoomCardList();
    std::vector<QString> getSuspectCardList();
    std::vector<QString> getWeaponCardList();
    std::vector<QString> getPlayerList();

};

#endif // GAME_H

