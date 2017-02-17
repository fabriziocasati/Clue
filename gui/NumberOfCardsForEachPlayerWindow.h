#ifndef NUMBEROFCARDSFOREACHPLAYERWINDOW_H
#define NUMBEROFCARDSFOREACHPLAYERWINDOW_H

#include "ClueSolver.h"
#include "NewGameCreationWindow.h"
#include "game/NewGameCreator.h"

class NewGameCreator;
class CustomRadioButton;

/*!
 * \brief Window used to specify, for each player, the number of held cards
 *
 * The user can use this window to specify for each player the number of held cards: since a player
 * may hold a different number of cards with respect to the other players, the user has to specify
 * these values for any player.
 *
 *
 * The window contains a groubox for each player to insert the number of held cards: each groupbox
 * (all equal) provides some radio buttons to specify this number (3 cards, 4 cards, ...).
 */
class NumberOfCardsForEachPlayerWindow : public NewGameCreationWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Create the window
     * \param newGameCreator pointer to the NewGameCreator instance
     * \param parent parent of the window
     */
    NumberOfCardsForEachPlayerWindow(NewGameCreator* newGameCreator, QWidget* parent = 0);

private:
    /* Pointer to the NewGameCreator instance */
    NewGameCreator* newGameCreator;

    /* Number of players in game */
    int numberOfPlayers;

    /* Vector of the names of the players */
    std::vector<QString> playerName;

    /* Matrix (array of arrays) of radio buttons (or better, CustomRadioButton instances) */
    CustomRadioButton* radioButton[6][4];

    /*! For each groupbox, keep note if there is one radio button that is checked: if the cell
     * is true, the corresponding groupbox contains a checked radio button */
    bool checked[6];

    /*!
     * \brief Create the groupbox containing groupboxs of radio buttons
     * \return a groupbox of groupboxs of radio buttons
     *
     * The returned groupbox contains as many groupboxs as the number of players in game
     * (numberOfPlayers): each of this sub groubox is associated to a player and contains some
     * radio buttons that allows the player to specify, for each player, the number of cards
     * that he holds.
     */
    QGroupBox* createNumberOfPlayersGroupBox();

private slots:
    /*!
     * \brief Function called when the confirm button of the window is clicked
     *
     * When the confirm button of the window is clicked, this function detects which radio
     * buttons were checked by the user in order to compute the number of cards held by each
     * player; these data are then passed to the Game instance, and then signals to MainWindow
     * that the next window for data insertion must be shown.
     */
    void confirmButtonClicked();

    /*!
     * \brief Check if the confirm button of the window can be enabled
     *
     * If for each player the number of held cards has been inserted, the confirm button of the
     * window can be enabled, otherwise it must remain disabled.
     */
    void checkEnablingConditions();
};

/*!
 * \brief Custom class for radio buttons
 *
 * Objects of this class are radio buttons that have associated an integer number representing a
 * player (0: first player; 1: second player; etc.). This index is used to check for which player
 * the number of held cards has been specified, i.e., in which groupboxs of the
 * NumberOfCardsForEachPlayerWindow instance (where there is a groupbox of radio buttons, more
 * precisely of CustomRadioButton instances, for each each player) a groupbox of radio button) a
 * radio button has been checked.
 */
class CustomRadioButton : public QRadioButton
{
    Q_OBJECT

public:
    /*!
     * \brief Construct the custom radio button
     * \param text of the radio button
     * \param playerIndex index of the associated player
     *
     * Construct the custom radio button by setting its text (the one that will be shown in the
     * NumberOfCardsForEachPlayerWindow window) and the index of the associated player.
     */
    CustomRadioButton(QString text, int playerIndex);

    /*!
     * \brief Return the index of the player associated to the groupbox contaning the radio
     * button
     * \return the index representing the player
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
