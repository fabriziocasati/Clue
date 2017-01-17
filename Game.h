#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include "Inquiry.h"
#include "Player.h"
#include "gui/GameWindow.h"
#include "gui/MainWindow.h"
#include <QString>

class Inquiry;
class MainWindow;

class Game
{
public:
    Game(MainWindow *mainWindow, int numberOfPlayers, std::vector<QString> playerName, std::vector<int> playerCardsNumber, std::vector<QString> userCards);
    std::string playerName[6];
    std::string roomCardName[9];
    std::string suspectCardName[6];
    std::string weaponCardName[6];
    int playerNumberOfCards[];
    int numberOfPlayers;
    std::list<Inquiry*> *inquiryList;
    Player player[6];

    void addInquiry(Inquiry *q);
    std::vector<QString> getUserCards();

    std::vector<QString> userCards;

};

#endif // GAME_H

