#include "Main.h"
#include "game/Game.h"
#include "game/NewGameCreator.h"
#include "gui/MainWindow.h"
#include <QApplication>

Main::Main()
{

}

void Main::createNewGame() {
    NewGameCreator *newGameCreator = new NewGameCreator(mainWindow);
}

void Main::setMainWindow(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Main *main = new Main();

    MainWindow *mainWindow = new MainWindow(main);
    mainWindow->showMaximized();
    main->setMainWindow(mainWindow);

    return a.exec();
}
