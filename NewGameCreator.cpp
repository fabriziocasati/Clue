#include "NewGameCreator.h"

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

void NewGameCreator::setNumberOfCardsForEachPlayer(int numbers[]) {

}

void NewGameCreator::setCardsOfTheUser(std::string *str) {

}
