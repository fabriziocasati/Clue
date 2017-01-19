#include "Game.h"
#include <QHash>
#include <QDebug>

Game::Game(MainWindow *mainWindow, int numberOfPlayers, std::vector<QString> playerName, std::vector<int> playerCardsNumber, std::vector<QString> userCards)
{

    QHash<QString, QString> hash;

    suspectCardList.push_back(QString("Peacock"));
    suspectCardList.push_back(QString("White"));
    suspectCardList.push_back(QString("Plumb"));
    suspectCardList.push_back(QString("Green"));
    suspectCardList.push_back(QString("Scarlet"));
    suspectCardList.push_back(QString("Mustard"));

    weaponCardList.push_back(QString("Candeliere"));
    weaponCardList.push_back(QString("Tubo"));
    weaponCardList.push_back(QString("Rivoltella"));
    weaponCardList.push_back(QString("Fune"));
    weaponCardList.push_back(QString("Pugnale"));
    weaponCardList.push_back(QString("???"));

    roomCardList.push_back(QString("Kitchen"));
    roomCardList.push_back(QString("Ballroom"));
    roomCardList.push_back(QString("Conservatory"));
    roomCardList.push_back(QString("Dining Room"));
    roomCardList.push_back(QString("Billiard Room"));
    roomCardList.push_back(QString("Library"));
    roomCardList.push_back(QString("Lounge"));
    roomCardList.push_back(QString("Hall"));
    roomCardList.push_back(QString("Study"));

    this->userCards = userCards;
    this->playerName = playerName;

    GameWindow *g = new GameWindow(this);
    inquiryList = new std::list<Inquiry*>();
    mainWindow->setSubwindow(g);
    g->show();


    std::vector<QString>::iterator it = userCards.begin();
    std::vector<QString>::iterator it2 = roomCardList.begin();
    int ok;
    for(int i=0; it2 != roomCardList.end(); ++it2, i++) {
        ok = 0;
        it = userCards.begin();
        while( !ok && it != userCards.end())
            if((*it).compare(*it2) == 0) {
                ok = 1;
            } else
                ++it;
        qDebug() << "ok: " << ok;
        if(ok) {
            g->updateCardTable(*it, *it2, "Yes");
        } else {
            //for(i=0; it2 != roomCard.end(); ++it2, i++)
                g->updateCardTable(*it2, "Cristina", "No");
        }
    }


    //g->updateCardTable("Conservatory", "Cristina", "Yes");

}

void Game::addInquiry(Inquiry *q) {
    inquiryList->push_back(q);
}

std::vector<QString> Game::getPlayerList() {
    return playerName;
}

std::vector<QString> Game::getUserCards() {
    return userCards;
}

std::vector<QString> Game::getRoomCardList() {
    return roomCardList;
}

std::vector<QString> Game::getSuspectCardList() {
    return suspectCardList;
}

std::vector<QString> Game::getWeaponCardList() {
    return weaponCardList;
}


