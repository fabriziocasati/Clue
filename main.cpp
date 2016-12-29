#include "mainwindow.h"
#include "numberofplayers.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    NumberOfPlayers numberOfPlayersWindow;
    numberOfPlayersWindow.show();

    return a.exec();
}
