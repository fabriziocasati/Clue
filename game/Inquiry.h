#ifndef INQUIRY_H
#define INQUIRY_H

#include <iostream>

class Inquiry
{
public:
    Inquiry(int turn, std::string inquirer, std::string room, std::string suspect, std::string weapon, std::string giver);

    int turn;               //the number of turn (1 for first turn, etc.) in which the inquiry is made
    std::string inquirer;   //the player that makes the inquiry
    std::string giver;      //the player that shows to the inquirer player a card
    std::string room;       //the room that is called by the inquirer player
    std::string suspect;    //the suspect that is called by the inquirer player
    std::string weapon;    //the weapon that is called by the inquirer player

};

#endif // INQUIRY_H
