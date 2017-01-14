#include "Game.h"

Game::Game()
{
    int numberOfPlayers = 4;
    playerName[0] = "Fabrizio";
    playerName[1] = "Cristina";
    playerName[2] = "Nerone";
    playerName[3] = "Grigina";

    roomCardName[0] = "???";
    roomCardName[1] = "Veranda";
    roomCardName[2] = "Camera";
    roomCardName[3] = "Studio";
    roomCardName[4] = "Cucina";
    roomCardName[5] = "Hall";
    roomCardName[6] = "Sala biliardo";
    roomCardName[7] = "Sala da pranzo";
    roomCardName[8] = "Sala da ballo";

    suspectCardName[0] = "Peacock";
    suspectCardName[1] = "White";
    suspectCardName[2] = "Green";
    suspectCardName[3] = "Plumb";
    suspectCardName[4] = "Scarlet";
    suspectCardName[5] = "Mustard";

    weaponCardName[0] = "Candeliere";
    weaponCardName[1] = "Tubo";
    weaponCardName[2] = "Rivoltella";
    weaponCardName[3] = "Fune";
    weaponCardName[4] = "Pugnale";
    weaponCardName[5] = "???";


    GameWindow *g = new GameWindow(this);
    inquiryList = new std::list<Inquiry*>();

}


void Game::addInquiry(Inquiry *q) {
    inquiryList->push_back(q);
}


