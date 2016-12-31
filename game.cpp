#include "game.h"

Game::Game()
{
    int numberOfPlayers = 4;
    playerName[0] = "Fabrizio";
    playerName[1] = "Cristina";
    playerName[2] = "Nerone";
    playerName[3] = "Grigina";

    GameWindow *g = new GameWindow(this);
    //GameWindow *g = new GameWindow(3);
    g->show();

    inquiryList = new std::list<Inquiry*>();


}


void Game::addInquiry(Inquiry *q) {
    inquiryList->push_back(q);
}


