#include "namesoftheplayers.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>

NamesOfThePlayers::NamesOfThePlayers(int numberOfPlayers, QWidget *parent)
    : QWidget(parent)
{




    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createNumberOfPlayersGroup(numberOfPlayers), 2, 0);

    setLayout(grid);

    setWindowTitle("Number of Players");
    //resize(480, 320);


}

QGroupBox *NamesOfThePlayers::createNumberOfPlayersGroup(int numberOfPlayers)
{

    std::string numberString = boost::lexical_cast<std::string>(numberOfPlayers);
    QString numberQString = QString::fromStdString(numberString);

    QGroupBox *groupBox = new QGroupBox("Select the number of players for the new game");

    //QPushButton *m_button = new QPushButton(numberQString, this);
    QPushButton *m_button = new QPushButton(numberQString, this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNamesOfThePlayersWindow()));

    QVBoxLayout *vbox = new QVBoxLayout;
    //vbox->setAlignment(Qt::AlignLeft);
    vbox->addWidget(m_button);
    //vbox->addStretch(1);

    QLineEdit *playerNameLineEdit[6];
    QLabel *playerNameLabel[6];

    for(int i=0; i<6; i++) {
        QGroupBox *v = new QGroupBox;
        QHBoxLayout *vl = new QHBoxLayout;
        playerNameLineEdit[i] = new QLineEdit();
        std::string numberString = "Name of the player #" + boost::lexical_cast<std::string>(i+1) + ":";
        QString numberQString = QString::fromStdString(numberString);
        playerNameLabel[i] = new QLabel(numberQString);
        //vbox->addWidget(playerNameLineEdit[i]);
        //vbox->addWidget(playerNameLabel[i]);
        vl->addWidget(playerNameLabel[i]);
        vl->addWidget(playerNameLineEdit[i]);
        v->setLayout(vl);
        vbox->addWidget(v);
    }

    for(int i=numberOfPlayers; i<6; i++) {
        playerNameLabel[i]->setDisabled(true);
        playerNameLineEdit[i]->setDisabled(true);
    }


    groupBox->setLayout(vbox);

    return groupBox;
}

void NamesOfThePlayers::openNamesOfThePlayersWindow()
{

}


