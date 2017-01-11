#include "NewGameCreator.h"

NewGameCreator::NewGameCreator(MainWindow *mainWindow)
{
    mainWindow = mainWindow;
    game = new Game();

    NumberOfPlayers *numberOfPlayersWindow = new NumberOfPlayers(mainWindow);
    //numberOfPlayersWindow->setFixedSize(600,300);
    //numberOfPlayersWindow->move(300,300);
    //numberOfPlayersWindow->move(QPoint(300,300));
    //numberOfPlayersWindow->move(parentWidget()->window()->frameGeometry().topLeft() + parentWidget()->window()->rect().center() - rect().center());
    mainWindow->setSubwindow(numberOfPlayersWindow);
}

