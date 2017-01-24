#ifndef NUMBEROFPLAYERSWINDOW_H
#define NUMBEROFPLAYERSWINDOW_H

#include <QDialog>
#include <QGroupBox>
#include <QRadioButton>

#include "ClueSolver.h"
#include "NewGameCreationWindow.h"

class NewGameCreator;

/*!
 * \brief Window used to insert the number of players in the game
 *
 * The valid numbers of players are shown to the user by means of radio buttons, and he can select
 * the correct number.
 */
class NumberOfPlayersWindow : public NewGameCreationWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Create a window to allow the player to specify the number of players in game
     * \param newGameCreator pointer to the NewGameCreator instance
     * \param parent the parent of the window
     *
     * The pointer to the NewGameCreator instance is necessary because the window calls this
     * object when all the data have been inserted.
     */
    explicit NumberOfPlayersWindow(NewGameCreator* newGameCreator, QWidget* parent = 0);

private:
    // Attributes
    //! Pointer to the NewGameCreator instance
    NewGameCreator* newGameCreator;

    //! The confirm button of the window
    QPushButton* confirmButton;

    //! Array to keep the pointers to the radio buttons in the window
    QRadioButton* numberOfPlayersRadioButton[MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1];

    // Functions
    /*!
     * \brief Create and return the confirm button of the window
     * \return the confirm button of the window
     *
     * A confirm button for the window is created and returned. This button is connected to the
     * confirmButtonClicked() slot, which is called when the button is clicked by the user.
     */
    QPushButton* createConfirmButton();

    /*!
     * \brief Create and return a groupbox containing all the radio buttons for the selectionf
     * of the number of players
     * \return the groupbox containing all the radio buttons
     *
     * The user can use the radio buttons added to the returned groupbox to select the number of
     * players in the game. When one of these radio buttons is clicked, the
     * enableConfirmButton() slot is invoked.
     */
    QGroupBox* createRadioButtonGroupBox();

    /*!
     * \brief Reimplementation of QDialog::closeEvent()
     * \param e The QCloseEvent instance
     *
     * To avoid that the window is closed by the user not in the proper way (i.e., by pressing
     * the confirm button), this function is reimplemented. In particular, when a close event is
     * created, it is ignored by the window and so the window doesn't close.
     */
    void closeEvent(QCloseEvent* closeEvent);

private slots:
    /*!
     * \brief Enable the confirm button
     *
     * By default, the confirm button of the window is disabled, since when the window is shown
     * no radio button is checked, which means that the number of players is at that moment not
     * selected. When one of these radio buttons is checked by the user, this radio button calls
     * activateConfirmButton() to enable the confirm button of the window to allow the user to
     * click it and confirm the selected number of players.
     */
    void enableConfirmButton();

    /*!
     * \brief Function called when the confirm button of the window is clicked
     *
     * When the confirm button of the window is clicked, this function detects which radio
     * button was selected by the user in order to discover the number of players in the game,
     * which is passed to the Game class, and then signals to MainWindow that the next window
     * for data insertion must be shown.
     */
    void confirmButtonClicked();
};

#endif // NUMBEROFPLAYERSWINDOW_H
