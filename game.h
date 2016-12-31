#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include "inquiry.h"
#include "player.h"
#include "gamewindow.h"

class Inquiry;

class Game
{
public:
    Game();
    std::string playerName[6];
    int playerNumberOfCards[];
    int numberOfPlayers;
    std::list<Inquiry*> *inquiryList;
    Player player[6];

    void addInquiry(Inquiry *q);

};

#endif // GAME_H
