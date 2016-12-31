#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include "query.h"
#include "player.h"

class Game
{
public:
    Game();
    std::string playerName[6];
    int playerNumberOfCards[];
    int numberOfPlayers;
    std::list<Query> queryList;
    Player player[6];
};

#endif // GAME_H
