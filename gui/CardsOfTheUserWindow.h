#ifndef CARDSOFTHEUSERWINDOW_H
#define CARDSOFTHEUSERWINDOW_H

#include <QObject>
#include <QWidget>
#include "NewGameCreator.h"

class CardsOfTheUserWindow : public QWidget
{
public:
    CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);
};

#endif // CARDSOFTHEUSERWINDOW_H
