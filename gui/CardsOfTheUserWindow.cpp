#include "CardsOfTheUserWindow.h"

#include "NumberOfCardsForEachPlayerWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QCheckBox>

#include "NamesOfThePlayersWindow.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>

CardsOfTheUserWindow::CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QDialog(parent)
{
    this->newGameCreator = newGameCreator;

    m_button = new QPushButton("Ok", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNextWindow()));

    QVBoxLayout *grid = new QVBoxLayout;
    grid->addWidget(createNumberOfPlayersGroup(6), 0, Qt::AlignCenter);
    grid->addWidget(m_button, 1, Qt::AlignCenter);

    setLayout(grid);

    setWindowTitle("Your Cards");
}

void CardsOfTheUserWindow::openNextWindow() {

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

}


QGroupBox* CardsOfTheUserWindow::createNumberOfPlayersGroup(int numberOfPlayers)
{

    std::string numberString = boost::lexical_cast<std::string>(numberOfPlayers);
    QString numberQString = QString::fromStdString(numberString);

    QGroupBox *groupBox = new QGroupBox("Select which cards you were given");

    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->setSpacing(30);
    //vbox->setAlignment(Qt::AlignLeft);
    vbox->addWidget(m_button);
    //vbox->addStretch(1);

    {
        QGroupBox *v = new QGroupBox("Room Cards");

        QVBoxLayout *vl = new QVBoxLayout;

        for(int i=0; i<9; i++) {
            std::string numberString = boost::lexical_cast<std::string>(i);
            QString numberQString = QString::fromStdString(numberString);
            roomCardCheckBox[i] = new QCheckBox(numberQString);
            vl->addWidget(roomCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    {
        QGroupBox *v = new QGroupBox("Suspect Cards");

        QVBoxLayout *vl = new QVBoxLayout;

        for(int i=0; i<6; i++) {
            std::string numberString = boost::lexical_cast<std::string>(i);
            QString numberQString = QString::fromStdString(numberString);
            suspectCardCheckBox[i] = new QCheckBox(numberQString);
            vl->addWidget(suspectCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    {
        QGroupBox *v = new QGroupBox("Weapon Cards");

        QVBoxLayout *vl = new QVBoxLayout;

        for(int i=0; i<6; i++) {
            std::string numberString = boost::lexical_cast<std::string>(i);
            QString numberQString = QString::fromStdString(numberString);
            weaponCardCheckBox[i] = new QCheckBox(numberQString);
            vl->addWidget(weaponCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    groupBox->setLayout(vbox);

    return groupBox;
}
