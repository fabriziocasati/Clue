#include "NumberOfCardsForEachPlayerWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QRadioButton>

#include <QDebug>

#include "ClueSolver.h"

#define SPACING 10

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

    /* Initialize flag array */
    for(int i = 0; i < numberOfPlayers; i++)
        checked[i] = false;
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

        /* Fill the groupbox with radio buttons to select the number of cards of the player
         * */
        for(j = 3; j <= 6; j++)
        {
            radioButton[i][j -
                           3] = new CustomRadioButton(intToQString(j) + " cards", i);
            connect(radioButton[i][j - 3], SIGNAL (clicked()), this,
                    SLOT (enableOrDisableConfirmButton()));
            playerGroupBoxLayout->addWidget(radioButton[i][j - 3]);
        }
        playerGroupBox->setLayout(playerGroupBoxLayout);
        layout->addWidget(playerGroupBox);
        layout->addSpacing(SPACING);
    }
    groupBox->setLayout(layout);
    return groupBox;
}

void NumberOfCardsForEachPlayerWindow::enableOrDisableConfirmButton()
{
    /* Retrieve the pointer to the radio button that was clicked */
    CustomRadioButton* obj = (CustomRadioButton*) sender();

    /* Retrieve the index of the player associated to the groupbox containing the clicked radio
     * button */
    int playerIndex = obj->getPlayerNumber();

    /* A radio button was clicked, which means that the number of cards of the player associated
     * to the groupbox containing the clicked radio button has been specified */
    checked[playerIndex] = true;

    /* Check if a number of cards for each player has been specified (i.e., if there is a
     * checked radio button in each groupbox) */
    bool flag = true;
    for(int i = 0; i < numberOfPlayers && flag; i++)
        if(checked[i] == false)
            flag = false;

    /* If all the data have been inserted, enable the confirm button, otherwise do nothing */
    confirmButton->setEnabled(flag);
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

CustomRadioButton::CustomRadioButton(QString text, int playerIndex) : QRadioButton(text)
{
    this->playerIndex = playerIndex;
}

int CustomRadioButton::getPlayerNumber()
{
    return playerIndex;
}
