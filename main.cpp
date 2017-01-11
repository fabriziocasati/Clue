#include "gui/MainWindow.h"
#include "Main.h"
#include "ClueSolver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Main *main = new Main();

    MainWindow *mainWindow = new MainWindow(main);
    mainWindow->showMaximized();
    main->setMainWindow(mainWindow);

    return a.exec();
}
