#ifndef NAMESOFTHEPLAYERSWINDOW_H
#define NAMESOFTHEPLAYERSWINDOW_H

#include "NewGameCreationWindow.h"

class QGroupBox;
class QPushButton;
class QLineEdit;
class QLabel;
class NewGameCreator;

/*!
 * \brief Window to insert the names of the players
 *
 * The user can use this window to insert, for each player, his/her names. The first player is the
 * user himself/herself, the second player is the player that plays, during the game, immediately
 * after the user, and so on. The window takes into account the number of players that the user has
 * previously specify to display the corrent number of edit lanes (one for each player).
 */
class NamesOfThePlayersWindow : public NewGameCreationWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Create the window
     * \param newGameCreator pointer to the NewGameCreator instance
     * \param parent the parent of the window
     */
    NamesOfThePlayersWindow(NewGameCreator* newGameCreator, QWidget* parent = 0);

private:
    QGroupBox* createNumberOfPlayersGroup();
    QPushButton* m_button;
    int nonEmptyName[6];
    int nonEmptyNames = 0;
    QHash<QLineEdit**, int> hash;
    QLineEdit* playerNameLineEdit[6];
    QLabel* playerNameLabel[6];
    NewGameCreator* newGameCreator;
    int numberOfPlayers;

private slots:
    void enableOrDisableConfirmButton(const QString &text);

    /*!
     * \brief Function called when the confirm button of the window is clicked
     *
     * When the confirm button of the window is clicked, this function detects which radio
     * buttons were checked by the user in order to compute the number of cards held by each
     * player; these data are then passed to the Game instance, and then signals to MainWindow
     * that the next window for data insertion must be shown.
     */
    void confirmButtonClicked();
};

#endif // NAMESOFTHEPLAYERSWINDOW_H
