#include <QtWidgets>
#include "numberofplayers.h"
#include "namesoftheplayers.h"
#include <string>
#include <boost/lexical_cast.hpp>

NumberOfPlayers::NumberOfPlayers(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createNumberOfPlayersGroup(), 2, 0);

    setLayout(grid);

    setWindowTitle("Number of Players");
    //resize(480, 320);


}

QGroupBox *NumberOfPlayers::createNumberOfPlayersGroup()
{
    QGroupBox *groupBox = new QGroupBox("Select the number of players for the new game");

    QPushButton *m_button = new QPushButton("Ok", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNamesOfThePlayersWindow()));

    QHBoxLayout *vbox = new QHBoxLayout;
    //vbox->setAlignment(Qt::AlignLeft);
    vbox->addWidget(m_button);
    //vbox->addStretch(1);


    for(int i=0; i<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++) {
        std::string numberString = boost::lexical_cast<std::string>(i+MIN_NUMBER_OF_PLAYERS);
        QString numberQString = QString::fromStdString(numberString);
        numberOfPlayersRadioButton[i] = new QRadioButton(numberQString);
        vbox->addWidget(numberOfPlayersRadioButton[i]);
    }

    groupBox->setLayout(vbox);

    return groupBox;
}

void NumberOfPlayers::openNamesOfThePlayersWindow()
{
    int i;
    for(i=0; i<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++) {
        if(numberOfPlayersRadioButton[i]->isChecked())
            break;
    }

    NamesOfThePlayers *w = new NamesOfThePlayers(i + MIN_NUMBER_OF_PLAYERS);
    w->show();

    this->close();

}
