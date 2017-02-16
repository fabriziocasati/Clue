#include "CardsOfTheUserWindow.h"

#include "NumberOfCardsForEachPlayerWindow.h"
#include <QCheckBox>
#include <QGridLayout>
#include <QPushButton>

#include "NamesOfThePlayersWindow.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>

#define SPACING 30

CardsOfTheUserWindow::CardsOfTheUserWindow(NewGameCreator* newGameCreator, QWidget* parent)
    : NewGameCreationWindow(parent)
{
    /* Store constructor arguments */
    this->newGameCreator = newGameCreator;
    this->userCardCount = newGameCreator->getNumberOfCardsForEachPlayer().front();

    /* Set to zero the number of currently checked check boxes */
    checkedCheckBoxCount = 0;

    /* Create and set window layout */
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);

    /* Create cards group boxes and add them to window */
    layout->addWidget(createGroupBoxes(), 0, Qt::AlignCenter);

    /* Create confirm button and add it to window */
    confirmButton = new QPushButton("Ok", this);
    confirmButton->setEnabled(false);
    connect(confirmButton, SIGNAL (clicked()), this, SLOT (confirmButtonClicked()));
    layout->addWidget(confirmButton, 1, Qt::AlignCenter);

    /* Window settings */
    setWindowTitle("Your Cards");
}

void CardsOfTheUserWindow::confirmButtonClicked()
{
    /* Detect the cards selected by the user and pass them to the newGameCreator instance */
    std::vector<QString> userCards;
    for(int i = 0; i < 6; i++)
    {
        if(roomCardCheckBox[i]->isChecked())
            userCards.push_back(roomCardCheckBox[i]->text());
        if(suspectCardCheckBox[i]->isChecked())
            userCards.push_back(suspectCardCheckBox[i]->text());
        if(weaponCardCheckBox[i]->isChecked())
            userCards.push_back(weaponCardCheckBox[i]->text());
    }
    for(int i = 6; i < 9; i++)
        if(roomCardCheckBox[i]->isChecked())
            userCards.push_back(roomCardCheckBox[i]->text());
    newGameCreator->setCardsOfTheUser(userCards);

    /* Open next window and close current one */
    newGameCreator->openNextWindow();
    destroy();
}

QGroupBox* CardsOfTheUserWindow::createGroupBoxes()
{
    /* Create main group box and its layout */
    QGroupBox* mainGroupBox = new QGroupBox("Select the " + intToQString(
                            userCardCount) + " cards you were given");
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->setSpacing(SPACING);
    mainGroupBox->setLayout(mainLayout);

    /* Create and add child group boxes */
    mainLayout->addWidget(foo("Room Cards",
                              newGameCreator->getRoomCardList(),
                              roomCardCheckBox));
    mainLayout->addWidget(foo("Suspect Cards",
                              newGameCreator->getSuspectCardList(),
                              suspectCardCheckBox));
    mainLayout->addWidget(foo("Weapon Cards",
                              newGameCreator->getWeaponCardList(),
                              weaponCardCheckBox));

    return mainGroupBox;
}

QGroupBox* CardsOfTheUserWindow::foo(QString string,
                                     std::vector<QString> cardList,
                                     QCheckBox* cardArray[])
{
    /* Create group box and set its layout */
    QGroupBox* v = new QGroupBox(string);
    QVBoxLayout* vl = new QVBoxLayout;
    v->setLayout(vl);

    /* Fill the group box */
    std::vector<QString>::iterator it = cardList.begin();
    int i = 0;
    for(; it != cardList.end(); i++, ++it)
    {
        cardArray[i] = new QCheckBox(*it);
        connect(cardArray[i], SIGNAL(clicked()), this, SLOT (checkEnablingConditions()));
        vl->addWidget(cardArray[i]);
    }

    return v;
}

void CardsOfTheUserWindow::checkEnablingConditions()
{
    QCheckBox* obj = (QCheckBox*) sender();

    if(obj->isChecked())
        checkedCheckBoxCount++;
    else
        checkedCheckBoxCount--;
    if(checkedCheckBoxCount == userCardCount)
        confirmButton->setEnabled(true);
    else
        confirmButton->setEnabled(false);
}
