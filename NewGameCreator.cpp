#include "NewGameCreator.h"

NewGameCreator::NewGameCreator(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
    game = new Game();

    NumberOfPlayers *numberOfPlayersWindow = new NumberOfPlayers(mainWindow, this);
    //numberOfPlayersWindow->setFixedSize(600,300);
    //numberOfPlayersWindow->move(300,300);
    //numberOfPlayersWindow->move(QPoint(300,300));
    //numberOfPlayersWindow->move(parentWidget()->window()->frameGeometry().topLeft() + parentWidget()->window()->rect().center() - rect().center());
    mainWindow->setSubwindow(numberOfPlayersWindow);
}

void NewGameCreator::openNextWindow(int numberOfPlayers) {
    this->numberOfPlayers = numberOfPlayers;
    QWidget *w = new NamesOfThePlayers(numberOfPlayers + MIN_NUMBER_OF_PLAYERS, mainWindow);
    mainWindow->setSubwindow(w);
}
