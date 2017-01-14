#include "CardsOfTheUserWindow.h"

CardsOfTheUserWindow::CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QWidget(parent)
{
    this->newGameCreator = newGameCreator;
    m_button = new QPushButton("numberQString", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNextWindow()));
}

void CardsOfTheUserWindow::openNextWindow() {
    newGameCreator->openNextWindow();
}
