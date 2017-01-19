#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>


class Player
{
public:
    Player();

private:
    std::string name;
    int numberOfCards;
    int weaponCardSet;
    int suspectCard[9];
    int roomCard[9];
};

#endif // PLAYER_H
