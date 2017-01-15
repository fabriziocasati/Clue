#ifndef CARDSOFTHEUSERWINDOW_H
#define CARDSOFTHEUSERWINDOW_H

#include <QObject>
#include <QWidget>
#include "NewGameCreator.h"
#include <QPushButton>
#include <QGroupBox>



class CardsOfTheUserWindow : public QWidget
{
public:
    CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

private:
    NewGameCreator *newGameCreator;
    QPushButton *m_button;

    void openNextWindow();
    QGroupBox* createNumberOfPlayersGroup(int numberOfPlayers);

    int nonEmptyName[6];
    int nonEmptyNames = 0;
    QHash<QLineEdit**, int> hash;
    QLineEdit *playerNameLineEdit[6];
    QLabel *playerNameLabel[6];
    MainWindow *mainWindow;
};

#endif // CARDSOFTHEUSERWINDOW_H
