#ifndef RECAPWINDOW_H
#define RECAPWINDOW_H

#include <QWindow>
#include "game/NewGameCreator.h"
#include <QDialog>

class RecapWindow : public QDialog
{
    Q_OBJECT

public:
    RecapWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

private:
    NewGameCreator *newGameCreator;

private slots:
    void openNextWindow();
};

#endif // RECAPWINDOW_H
