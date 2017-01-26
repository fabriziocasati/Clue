#include "CardsOfTheUserWindow.h"

#include "NumberOfCardsForEachPlayerWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QCheckBox>

#include "NamesOfThePlayersWindow.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>

CardsOfTheUserWindow::CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : NewGameCreationWindow(parent)
{
    this->newGameCreator = newGameCreator;
    this->userCardCount = newGameCreator->getNumberOfCardsForEachPlayer().front();
    checkedCheckBoxCount = 0;


    confirmButton = new QPushButton("Ok", this);
    confirmButton->setEnabled(false);
    connect(confirmButton, SIGNAL (clicked()), this, SLOT (confirmButtonClicked()));

    QVBoxLayout *grid = new QVBoxLayout;
    grid->addWidget(createNumberOfPlayersGroup(6), 0, Qt::AlignCenter);
    grid->addWidget(confirmButton, 1, Qt::AlignCenter);

    setLayout(grid);

    setWindowTitle("Your Cards");
}

void CardsOfTheUserWindow::confirmButtonClicked() {

    std::vector<QString> userCards;
    for(int i=0; i<6; i++) {
        if(roomCardCheckBox[i]->isChecked())
            userCards.push_back(roomCardCheckBox[i]->text());
        if(suspectCardCheckBox[i]->isChecked())
            userCards.push_back(suspectCardCheckBox[i]->text());
        if(weaponCardCheckBox[i]->isChecked())
            userCards.push_back(weaponCardCheckBox[i]->text());
    }
    for(int i=6; i<9; i++)
        if(roomCardCheckBox[i]->isChecked())
            userCards.push_back(roomCardCheckBox[i]->text());

    newGameCreator->setCardsOfTheUser(userCards);
    newGameCreator->openNextWindow();
    destroy();

}


QGroupBox* CardsOfTheUserWindow::createNumberOfPlayersGroup(int numberOfPlayers)
{

    std::string numberString = boost::lexical_cast<std::string>(userCardCount);
    QString numberQString = QString::fromStdString("Select the " + numberString + " cards you were given");

    QGroupBox *groupBox = new QGroupBox(numberQString);

    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->setSpacing(30);
    //vbox->setAlignment(Qt::AlignLeft);
    vbox->addWidget(confirmButton);
    //vbox->addStretch(1);

    {
        QGroupBox *v = new QGroupBox("Room Cards");

        QVBoxLayout *vl = new QVBoxLayout;

        std::vector<QString> roomCardList = newGameCreator->getRoomCardList();
        std::vector<QString>::iterator it = roomCardList.begin();

        for(int i=0; i<9; i++, ++it) {
            roomCardCheckBox[i] = new QCheckBox(*it);
            connect(roomCardCheckBox[i], SIGNAL(clicked()), this, SLOT (checkEnablingConditions()));
            vl->addWidget(roomCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    {
        QGroupBox *v = new QGroupBox("Suspect Cards");

        QVBoxLayout *vl = new QVBoxLayout;

        std::vector<QString> suspectCardList = newGameCreator->getSuspectCardList();
        std::vector<QString>::iterator it = suspectCardList.begin();

        for(int i=0; i<6; i++, ++it) {
            suspectCardCheckBox[i] = new QCheckBox(*it);
            connect(suspectCardCheckBox[i], SIGNAL(clicked()), this, SLOT (checkEnablingConditions()));
            vl->addWidget(suspectCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    {
        QGroupBox *v = new QGroupBox("Weapon Cards");

        QVBoxLayout *vl = new QVBoxLayout;

        std::vector<QString> weaponCardList = newGameCreator->getWeaponCardList();
        std::vector<QString>::iterator it = weaponCardList.begin();

        for(int i=0; i<6; i++, ++it) {
            weaponCardCheckBox[i] = new QCheckBox(*it);
            connect(weaponCardCheckBox[i], SIGNAL(clicked()), this, SLOT (checkEnablingConditions()));
            vl->addWidget(weaponCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    groupBox->setLayout(vbox);

    return groupBox;
}

void CardsOfTheUserWindow::checkEnablingConditions() {
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
