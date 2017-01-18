#include "Game.h"
#include <QHash>
#include <QDebug>

Game::Game(MainWindow *mainWindow, int numberOfPlayers, std::vector<QString> playerName, std::vector<int> playerCardsNumber, std::vector<QString> userCards)
{

    QHash<QString, QString> hash;

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

    std::vector<QString> roomCard;
    roomCard.push_back(QString("Kitchen"));
    roomCard.push_back(QString("Ballroom"));
    roomCard.push_back(QString("Conservatory"));
    roomCard.push_back(QString("Dining Room"));
    roomCard.push_back(QString("Billiard Room"));
    roomCard.push_back(QString("Library"));
    roomCard.push_back(QString("Lounge"));
    roomCard.push_back(QString("Hall"));
    roomCard.push_back(QString("Study"));

    this->userCards = userCards;

    GameWindow *g = new GameWindow(this);
    inquiryList = new std::list<Inquiry*>();
    mainWindow->setSubwindow(g);
    g->show();


    std::vector<QString>::iterator it = userCards.begin();
    std::vector<QString>::iterator it2 = roomCard.begin();
    int ok;
    for(int i=0; it2 != roomCard.end(); ++it2, i++) {
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

std::vector<QString> Game::getUserCards() {
    return userCards;
}



