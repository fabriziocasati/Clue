#include <QApplication>

#include "gui/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow();
    mainWindow->showMaximized();

    return a.exec();
}
