#include "RecapWindow.h"

RecapWindow::RecapWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QWidget(parent)
{
    this->newGameCreator = newGameCreator;
}

