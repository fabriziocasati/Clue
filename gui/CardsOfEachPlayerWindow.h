#ifndef CARDSOFEACHPLAYERWINDOW_H
#define CARDSOFEACHPLAYERWINDOW_H

#include <QObject>
#include <QWidget>
#include "NewGameCreator.h"

class CardsOfEachPlayerWindow : public QWidget
{
public:
    CardsOfEachPlayerWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);
};

#endif // CARDSOFEACHPLAYERWINDOW_H
