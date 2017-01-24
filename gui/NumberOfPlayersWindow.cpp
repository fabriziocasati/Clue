#include "NumberOfPlayersWindow.h"

#include <QtWidgets> // required by the QCloseEvent

#include "game/NewGameCreator.h"

NumberOfPlayersWindow::NumberOfPlayersWindow(NewGameCreator* newGameCreator, QWidget* parent)
    : NewGameCreationWindow(parent)
{
    /* Save pointer to the NewGameCreator instance */
    this->newGameCreator = newGameCreator;

    /* Create the main window layout */
    QVBoxLayout* windowLayout = new QVBoxLayout;

    /* Create radio buttons and add them to the window */
    windowLayout->addWidget(createRadioButtonGroupBox(), 0, Qt::AlignCenter);

    /* Create confirm button and add it to the window */
    confirmButton = createConfirmButton();
    windowLayout->addWidget(confirmButton, 1, Qt::AlignCenter);

    /* Window settings */
    setWindowTitle("Number of Players");
    setLayout(windowLayout);
}

void NumberOfPlayersWindow::confirmButtonClicked()
{
    /* Get the number of player selected by means of the radio buttons */
    int numberOfPlayers;
    for(numberOfPlayers = MIN_NUMBER_OF_PLAYERS; numberOfPlayers <= MAX_NUMBER_OF_PLAYERS;
        numberOfPlayers++)
        if(numberOfPlayersRadioButton[numberOfPlayers - MIN_NUMBER_OF_PLAYERS]->isChecked())
            break;

    /* Pass to the NewGameCreator instance the number of players and ask it to open the next
     * window */
    newGameCreator->setNumberOfPlayers(numberOfPlayers);
    newGameCreator->openNextWindow();

    /* Close and destroy window */
    destroy();
}

void NumberOfPlayersWindow::enableConfirmButton()
{
    confirmButton->setDisabled(false);
}

void NumberOfPlayersWindow::closeEvent(QCloseEvent* closeEvent)
{
    closeEvent->ignore();
}

QPushButton* NumberOfPlayersWindow::createConfirmButton()
{
    /* Create the button */
    QPushButton* confirmButton = new QPushButton("Ok", this);

    /* The confirm button is by default disabled to avoid that the user clicks it even when no
     * radio button has been selected */
    confirmButton->setDisabled(true);

    /* Invoke confirmButtonClicked() when the confirm button is clicked */
    connect(confirmButton, SIGNAL (clicked()), this, SLOT (confirmButtonClicked()));

    /* Return the button */
    return confirmButton;
}

QGroupBox* NumberOfPlayersWindow::createRadioButtonGroupBox()
{
    /* Create a vertical layout and a group box for the radio buttons */
    QVBoxLayout* layout = new QVBoxLayout;
    QGroupBox* groupBox = new QGroupBox("Select the number of players");

    /* Create the radio buttons and add them to the groupbox. Moreover, connect each of them
     * to the enableConfirmButton() slot, which is invoked when the user clicks a radio
     * button. */
    for(int i = 0; i < MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++)
    {
        numberOfPlayersRadioButton[i] =
            new QRadioButton(intToQString(i + MIN_NUMBER_OF_PLAYERS) + " players");
        connect(numberOfPlayersRadioButton[i], SIGNAL (clicked()), this,
                SLOT (enableConfirmButton()));
        layout->addWidget(numberOfPlayersRadioButton[i]);
    }

    /* Set groupbox layout and return the groupbox */
    groupBox->setLayout(layout);
    return groupBox;
}
