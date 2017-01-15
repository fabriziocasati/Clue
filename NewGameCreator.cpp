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

    if(numberOfOpenedWindows < 5) {
        switch(numberOfOpenedWindows) {
            case 0 : subWindow = new NumberOfPlayersWindow(this); break;
            case 1 : subWindow = new NamesOfThePlayersWindow(this); break;
            case 2 : subWindow = new NumberOfCardsForEachPlayerWindow(this); break;
            case 3 : subWindow = new CardsOfTheUserWindow(this); break;
            case 4 : subWindow = new RecapWindow(this); break;
        }
        numberOfOpenedWindows++;
        mainWindow->setSubwindow(subWindow);
    } else
        game = new Game();
}

void NewGameCreator::setNumberOfPlayers(int numberOfPlayers) {
    this->numberOfPlayers = numberOfPlayers;
}

int NewGameCreator::getNumberOfPlayers() {
    return numberOfPlayers;
}

void NewGameCreator::setNamesOfThePlayers(std::string *playerName) {
    this->playerName = playerName;
}

std::string* NewGameCreator::getNamesOfThePlayers() {
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

void NewGameCreator::setCardsOfTheUser(std::string *str) {

}
