#ifndef NUMBEROFCARDSFOREACHPLAYERWINDOW_H
#define NUMBEROFCARDSFOREACHPLAYERWINDOW_H

#include <QDialog>
#include <QGroupBox>
#include <QHash>
#include <QObject>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>

#include "ClueSolver.h"
#include "NewGameCreationWindow.h"
#include "game/NewGameCreator.h"
#include "gui/MainWindow.h"

class NewGameCreator;

class NumberOfCardsForEachPlayerWindow : public NewGameCreationWindow
{
    Q_OBJECT

public:
    NumberOfCardsForEachPlayerWindow(NewGameCreator* newGameCreator, QWidget* parent = 0);

private:
    NewGameCreator* newGameCreator;
    QGroupBox* createNumberOfPlayersGroupBox();
    int nonEmptyName[6];
    int nonEmptyNames = 0;
    QHash<QLineEdit**, int> hash;
    QLineEdit* playerNameLineEdit[6];
    QLabel* playerNameLabel[6];
    MainWindow* mainWindow;
    std::vector<QString> playerName;
    int numberOfPlayers;
    QRadioButton* radioButton[6][4];

private slots:
    void confirmButtonClicked();
};

#endif // NUMBEROFCARDSFOREACHPLAYERWINDOW_H
