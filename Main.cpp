#include "Main.h"
#include "game/Game.h"
#include "game/NewGameCreator.h"

Main::Main()
{

}

void Main::createNewGame() {
    NewGameCreator *newGameCreator = new NewGameCreator(mainWindow);
}

void Main::setMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}
