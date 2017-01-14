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
        case 1 : subWindow = new NamesOfThePlayers(numberOfPlayers + MIN_NUMBER_OF_PLAYERS, mainWindow, this); break;
        case 2 : subWindow = new NumberOfCardsForEachPlayerWindow(); break;
        default : break;
    }

    numberOfOpenedWindows++;
    mainWindow->setSubwindow(subWindow);
}

void NewGameCreator::setNumberOfPlayers(int numberOfPlayers) {
    this->numberOfPlayers = numberOfPlayers;
}

void NewGameCreator::setNamesOfThePlayers(std::string *playerName) {
    this->playerName = playerName;
}
