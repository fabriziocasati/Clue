#include "gui/MainWindow.h"
#include "Main.h"
#include "ClueSolver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Main *main = new Main();

    MainWindow *w = new MainWindow(main);
    w->showMaximized();

    return a.exec();
}
