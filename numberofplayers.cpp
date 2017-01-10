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
    QGroupBox *g = new QGroupBox();
    QVBoxLayout *vbox = new QVBoxLayout;

    /*
    vbox->setStretch(0,0);
    vbox->setStretchFactor(g,0);
    */



    g->setLayout(vbox);


    QGroupBox *groupBox = new QGroupBox("Select the number of players for the new game");

    m_button = new QPushButton("Ok", this);
    m_button->setDisabled(true);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNamesOfThePlayersWindow()));

    /*
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_button->sizePolicy().hasHeightForWidth());
    m_button->setSizePolicy(sizePolicy);
    */

    m_button->setFixedSize(QSize(150,50));
    vbox->setAlignment(Qt::AlignCenter);

    vbox->setStretch(0,0);



    //m_button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QHBoxLayout *hbox = new QHBoxLayout;
    //vbox->setAlignment(Qt::AlignLeft);

    //vbox->addStretch(1);


    for(int i=0; i<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++) {
        std::string numberString = boost::lexical_cast<std::string>(i+MIN_NUMBER_OF_PLAYERS);
        QString numberQString = QString::fromStdString(numberString);
        numberOfPlayersRadioButton[i] = new QRadioButton(numberQString);
        //numberOfPlayersRadioButton[i] = new QRadioButton("Test");
        connect(numberOfPlayersRadioButton[i], SIGNAL (clicked()), this, SLOT (activateConfirmButton()));
        hbox->addWidget(numberOfPlayersRadioButton[i]);
    }

    groupBox->setLayout(hbox);
    vbox->addWidget(groupBox, 0, Qt::AlignCenter);
    vbox->addWidget(m_button, 1, Qt::AlignCenter);

    return g;
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

void NumberOfPlayers::activateConfirmButton()
{
    m_button->setDisabled(false);

}
