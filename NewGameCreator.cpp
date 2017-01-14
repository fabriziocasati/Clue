#include "NewGameCreator.h"

NewGameCreator::NewGameCreator(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
    this->numberOfOpenedWindows = 0;
    game = new Game();

    openNextWindow();

}

void NewGameCreator::openNextWindow() {

    QWidget *subWindow;

    switch(numberOfOpenedWindows) {
        case 0 : subWindow = new NumberOfPlayersWindow(this); break;
        case 1 : subWindow = new NamesOfThePlayersWindow(this); break;
        case 2 : subWindow = new NumberOfCardsForEachPlayerWindow(this); break;
        case 3 : subWindow = new CardsOfTheUserWindow(this); break;
        default : break;
    }

    numberOfOpenedWindows++;
    mainWindow->setSubwindow(subWindow);
}

void NewGameCreator::setNumberOfPlayers(int numberOfPlayers) {
    this->numberOfPlayers = numberOfPlayers;
}

int NewGameCreator::getNumberOfPlayers() {
    return this->numberOfPlayers;
}

void NewGameCreator::setNamesOfThePlayers(std::string *playerName) {
    this->playerName = playerName;
}
