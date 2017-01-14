#ifndef NUMBEROFCARDSFOREACHPLAYERWINDOW_H
#define NUMBEROFCARDSFOREACHPLAYERWINDOW_H

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>

#include <QHash>
#include "gui/MainWindow.h"
#include "NewGameCreator.h"

class NewGameCreator;

class NumberOfCardsForEachPlayerWindow : public QWidget
{
    Q_OBJECT

    public:
        NumberOfCardsForEachPlayerWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

    private:
        NewGameCreator *newGameCreator;
        QGroupBox *createNumberOfPlayersGroup(int numberOfPlayers);
        QPushButton *m_button;
        int nonEmptyName[6];
        int nonEmptyNames = 0;
        QHash<QLineEdit**, int> hash;
        QLineEdit *playerNameLineEdit[6];
        QLabel *playerNameLabel[6];
        MainWindow *mainWindow;

        void openNextWindow();
};

#endif // NUMBEROFCARDSFOREACHPLAYERWINDOW_H
