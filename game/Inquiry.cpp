#include "Inquiry.h"

Inquiry::Inquiry(int turn, std::string inquirer, std::string room, std::string suspect, std::string weapon, std::string giver)
{
    this->turn = turn;

    this->inquirer = inquirer;
    this->giver = giver;
    this->room = room;
    this->suspect = suspect;
    this->weapon = weapon;
}

