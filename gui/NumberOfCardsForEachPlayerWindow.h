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
class CustomRadioButton;

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
    CustomRadioButton* radioButton[6][4];
    bool checked[6];

private slots:
    void confirmButtonClicked();
    void enableOrDisableConfirmButton();
};

/*!
 * \brief Custom class for radio buttons
 *
 * Objects of the class are radio buttons that have associated an integer number representing a
 * player (0: first player; 1: second player; etc.). This index is used to check for which player
 * the number of held cards has been specified, i.e., in which groupboxs (each player has associated
 * a groupbox of radio button) a radio button has been checked.
 */
class CustomRadioButton : public QRadioButton
{
    Q_OBJECT

public:
    CustomRadioButton(QString text, int playerNumber);

    /*!
     * \brief Return the index of the player associated to the groupbox contaning the radio
     * button
     * \return The index representing the player
     *
     * Return the index of the player associated to the groupbox contaning this instance (a
     * radio button that may be checked or not)
     */
    int getPlayerNumber();

private:
    /*! Index representing a player (0: first player; 1: second player; etc.). */
    int playerIndex;
};

#endif // NUMBEROFCARDSFOREACHPLAYERWINDOW_H
