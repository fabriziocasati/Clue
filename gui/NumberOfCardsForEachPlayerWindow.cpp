#include "NumberOfCardsForEachPlayerWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QRadioButton>

#include "ClueSolver.h"

NumberOfCardsForEachPlayerWindow::NumberOfCardsForEachPlayerWindow(NewGameCreator* newGameCreator,
                                                                   QWidget* parent)
    : NewGameCreationWindow(parent)
{
    /* Store pointer to the NewGameCreator instance and use it to retrieve the necessary data */
    this->newGameCreator = newGameCreator;
    this->numberOfPlayers = newGameCreator->getNumberOfPlayers();
    this->playerName = newGameCreator->getNamesOfThePlayers();

    /* Create window layout */
    QVBoxLayout* windowLayout = new QVBoxLayout;

    /* Create the groupbox containing the radio buttons to select the number of cards for each
     * player */
    windowLayout->addWidget(createNumberOfPlayersGroupBox(), 0, Qt::AlignCenter);

    /* Create confirm button and add it to the window */
    confirmButton = createConfirmButton();
    windowLayout->addWidget(confirmButton, 1, Qt::AlignCenter);

    /* Window settings */
    setWindowTitle("Number of Cards for each Player");
    setLayout(windowLayout);
    setModal(true);
}

QGroupBox* NumberOfCardsForEachPlayerWindow::createNumberOfPlayersGroupBox()
{
    /* Create all necessary instances */
    QGroupBox* groupBox = new QGroupBox("Insert the number of cards held by each player");
    QHBoxLayout* layout = new QHBoxLayout;
    QGroupBox* playerGroupBox;
    QVBoxLayout* playerGroupBoxLayout;

    /* Create all the sub groupboxs */
    int i = 0, j;
    for (std::vector<QString>::iterator it = playerName.begin(); it != playerName.end();
         ++it, i++)
    {
        /* Create a groupbox for the player currently considered by the for cycle */
        playerGroupBox = new QGroupBox(*it);
        playerGroupBoxLayout = new QVBoxLayout;

        /* Fill the groupbox with radio buttons to select the number of cards of the player */
        for(j = 3; j <= 6; j++)
        {
            radioButton[i][j - 3] = new QRadioButton(intToQString(j) + " cards");
            playerGroupBoxLayout->addWidget(radioButton[i][j - 3]);
        }
        playerGroupBox->setLayout(playerGroupBoxLayout);
        layout->addWidget(playerGroupBox);
        layout->addSpacing(10);
    }
    groupBox->setLayout(layout);
    return groupBox;
}

void NumberOfCardsForEachPlayerWindow::confirmButtonClicked()
{
    /* Check which radio buttons have been selected to retrieve the number of cards for each
     * player */
    std::vector<int> playerCardsNumber;
    int i, j;
    for(i = 0; i < numberOfPlayers; i++)
        for(j = 0; j <= MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS; j++)
            if(radioButton[i][j]->isChecked())
                playerCardsNumber.push_back(j + MIN_NUMBER_OF_PLAYERS);

    /* Pass data to the NewGameCreator instance, ask it to show the next window and then close
     * the current window */
    newGameCreator->setNumberOfCardsForEachPlayer(playerCardsNumber);
    newGameCreator->openNextWindow();
    destroy();
}
