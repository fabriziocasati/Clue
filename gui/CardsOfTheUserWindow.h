#ifndef CARDSOFTHEUSERWINDOW_H
#define CARDSOFTHEUSERWINDOW_H

#include <QObject>
#include <QWidget>
#include "NewGameCreator.h"
#include <QPushButton>

class CardsOfTheUserWindow : public QWidget
{
public:
    CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

private:
    NewGameCreator *newGameCreator;
    QPushButton *m_button;

    void openNextWindow();
};

#endif // CARDSOFTHEUSERWINDOW_H
