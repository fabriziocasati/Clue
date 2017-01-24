#ifndef NUMBEROFCARDSFOREACHPLAYERWINDOW_H
#define NUMBEROFCARDSFOREACHPLAYERWINDOW_H

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QHash>
#include "gui/MainWindow.h"
#include "game/NewGameCreator.h"
#include <QDialog>

#include "NewGameCreationWindow.h"

class NewGameCreator;

class NumberOfCardsForEachPlayerWindow : public NewGameCreationWindow
{
    Q_OBJECT

    public:
        NumberOfCardsForEachPlayerWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

    private:
        NewGameCreator *newGameCreator;
        QGroupBox *createNumberOfPlayersGroupBox();
        QPushButton *confirmButton;
        int nonEmptyName[6];
        int nonEmptyNames = 0;
        QHash<QLineEdit**, int> hash;
        QLineEdit *playerNameLineEdit[6];
        QLabel *playerNameLabel[6];
        MainWindow *mainWindow;
        std::vector<QString> playerName;
        int numberOfPlayers;
        QRadioButton *radioButton[6][4];

        QPushButton* createConfirmButton();

    private slots:
        void confirmButtonClicked();
};

#endif // NUMBEROFCARDSFOREACHPLAYERWINDOW_H
