#include "NewGameCreator.h"
#include <QDebug>
#include "gui/NewInquiryWindow.h"
#include "gui/InquiryHistoryWindow.h"

class MainWindow;

NewGameCreator::NewGameCreator(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
    this->numberOfOpenedWindows = 0;

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

    openNextWindow();
}

void NewGameCreator::openNextWindow() {

    QWidget *subWindow, *old;

    if(numberOfOpenedWindows < 4) {
        switch(numberOfOpenedWindows) {
            case 0 : subWindow = new NumberOfPlayersWindow(this, mainWindow); break;
            case 1 : subWindow = new NamesOfThePlayersWindow(this, mainWindow); break;
            case 2 : subWindow = new NumberOfCardsForEachPlayerWindow(this, mainWindow); break;
            case 3 : subWindow = new CardsOfTheUserWindow(this, mainWindow); break;
            case 4 : subWindow = new RecapWindow(this, mainWindow); break;
        }
        numberOfOpenedWindows++;
        mainWindow->setSubwindow(subWindow);
    } else {
        game = new Game(mainWindow, numberOfPlayers, playerName, playerCardsNumber, userCards);
        mainWindow->setGame(game);
        GameWindow *g = new GameWindow(game, mainWindow);
        InquiryHistoryWindow *i = new InquiryHistoryWindow(game, mainWindow);
        NewInquiryWindow *n = new NewInquiryWindow(game, i, mainWindow);
        mainWindow->setSubwindow(g);
        mainWindow->setSubwindow(n);
        mainWindow->setSubwindow(i);
    }
}

void NewGameCreator::setNumberOfPlayers(int numberOfPlayers) {
    this->numberOfPlayers = numberOfPlayers;
}

int NewGameCreator::getNumberOfPlayers() {
    return numberOfPlayers;
}

void NewGameCreator::setNamesOfThePlayers(std::vector<QString> playerName) {
    this->playerName = playerName;
}

std::vector<QString> NewGameCreator::getNamesOfThePlayers() {
    return playerName;
}

void NewGameCreator::setNumberOfCardsForEachPlayer(std::vector<int> playerCardsNumber) {
    this->playerCardsNumber = playerCardsNumber;
    for(int i=0; i < 6; i++)
        qDebug() << "1: " << this->playerCardsNumber[i];
}

std::vector<int> NewGameCreator::getNumberOfCardsForEachPlayer() {
    for(int i=0; i < 6; i++)
        qDebug() << "2: " << this->playerCardsNumber[i];
    return playerCardsNumber;
}

void NewGameCreator::setCardsOfTheUser(std::vector<QString> userCards) {
    this->userCards = userCards;
}

std::vector<QString> NewGameCreator::getCardsOfTheUser() {
    return userCards;
}

std::vector<QString> NewGameCreator::getRoomCardList() {
    return roomCardList;
}

std::vector<QString> NewGameCreator::getSuspectCardList() {
    return suspectCardList;
}

std::vector<QString> NewGameCreator::getWeaponCardList() {
    return weaponCardList;
}
