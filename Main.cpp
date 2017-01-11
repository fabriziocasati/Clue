#include "Main.h"
#include "Game.h"
#include "NewGameCreator.h"

Main::Main()
{

}

void Main::createNewGame() {
    NewGameCreator *newGameCreator = new NewGameCreator(mainWindow);
}

void Main::setMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}
