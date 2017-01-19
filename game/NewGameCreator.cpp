#include "NewGameCreator.h"
#include <QDebug>

NewGameCreator::NewGameCreator(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
    this->numberOfOpenedWindows = 0;

    openNextWindow();
}

void NewGameCreator::openNextWindow() {

    QWidget *subWindow;

    if(numberOfOpenedWindows < 2) {
        switch(numberOfOpenedWindows) {
            case 0 : subWindow = new NumberOfPlayersWindow(this); break;
            case 1 : subWindow = new NamesOfThePlayersWindow(this); break;
            case 2 : subWindow = new NumberOfCardsForEachPlayerWindow(this); break;
            case 3 : subWindow = new CardsOfTheUserWindow(this); break;
            case 4 : subWindow = new RecapWindow(this); break;
        }
        numberOfOpenedWindows++;
        mainWindow->setSubwindow(subWindow);
    } else {
        game = new Game(mainWindow, numberOfPlayers, playerName, playerCardsNumber, userCards);
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
