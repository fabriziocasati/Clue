#ifndef RECAPWINDOW_H
#define RECAPWINDOW_H

#include <QWindow>
#include "NewGameCreator.h"

class RecapWindow : public QWidget
{
public:
    RecapWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

private:
    NewGameCreator *newGameCreator;
};

#endif // RECAPWINDOW_H
