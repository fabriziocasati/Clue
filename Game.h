#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include "Inquiry.h"
#include "player.h"
#include "gui/GameWindow.h"

class Inquiry;

class Game
{
public:
    Game();
    std::string playerName[6];
    std::string roomCardName[9];
    std::string suspectCardName[6];
    std::string weaponCardName[6];
    int playerNumberOfCards[];
    int numberOfPlayers;
    std::list<Inquiry*> *inquiryList;
    Player player[6];

    void addInquiry(Inquiry *q);

};

#endif // GAME_H

