#ifndef CARDSOFTHEUSERWINDOW_H
#define CARDSOFTHEUSERWINDOW_H

#include <QObject>
#include <QWidget>
#include "game/NewGameCreator.h"
#include <QPushButton>
#include <QGroupBox>



class CardsOfTheUserWindow : public QWidget
{
    Q_OBJECT

    public:
        CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

    private:
        NewGameCreator *newGameCreator;
        QPushButton *m_button;

        QGroupBox* createNumberOfPlayersGroup(int numberOfPlayers);

        int nonEmptyName[6];
        int nonEmptyNames = 0;
        QHash<QLineEdit**, int> hash;
        QLineEdit *playerNameLineEdit[6];
        QLabel *playerNameLabel[6];
        MainWindow *mainWindow;

        QCheckBox *roomCardCheckBox[9];
        QCheckBox *suspectCardCheckBox[9];
        QCheckBox *weaponCardCheckBox[9];

    private slots:
        void openNextWindow();
};

#endif // CARDSOFTHEUSERWINDOW_H
