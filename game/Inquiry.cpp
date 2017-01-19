#include "Inquiry.h"

Inquiry::Inquiry(int turn, std::string inquirer, std::string giver, std::string room, std::string suspect, std::string weaopon)
{
    this->turn = turn;

    this->inquirer = inquirer;
    this->giver = giver;
    this->room = room;
    this->suspect = suspect;
    this->weaopon = weaopon;
}

