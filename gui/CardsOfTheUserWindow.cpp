#include "CardsOfTheUserWindow.h"

#include "NumberOfCardsForEachPlayerWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QCheckBox>

#include "NamesOfThePlayersWindow.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>

CardsOfTheUserWindow::CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QWidget(parent)
{
    this->newGameCreator = newGameCreator;
    m_button = new QPushButton("numberQString", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNextWindow()));

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createNumberOfPlayersGroup(6), 2, 0);

    setLayout(grid);

    setWindowTitle("Number of Players");
}

void CardsOfTheUserWindow::openNextWindow() {
    newGameCreator->openNextWindow();
}


QGroupBox* CardsOfTheUserWindow::createNumberOfPlayersGroup(int numberOfPlayers)
{

    std::string numberString = boost::lexical_cast<std::string>(numberOfPlayers);
    QString numberQString = QString::fromStdString(numberString);

    QGroupBox *groupBox = new QGroupBox("Insert the number of cards held by each player");

    QHBoxLayout *vbox = new QHBoxLayout;
    //vbox->setAlignment(Qt::AlignLeft);
    vbox->addWidget(m_button);
    //vbox->addStretch(1);

    for(int i=0; i<3; i++) {
        std::string numberString = "Player #" + boost::lexical_cast<std::string>(i+1);
        QString numberQString = QString::fromStdString(numberString);
        QGroupBox *v = new QGroupBox(numberQString);

        QVBoxLayout *vl = new QVBoxLayout;

        for(int i=0; i<9; i++) {
            std::string numberString = boost::lexical_cast<std::string>(i);
            QString numberQString = QString::fromStdString(numberString);
            QCheckBox *r = new QCheckBox(numberQString);
            vl->addWidget(r);
        }

        /*
        playerNameLineEdit[i] = new QLineEdit();
        //std::string numberString = "Name of the player #" + boost::lexical_cast<std::string>(i+1) + ":";
        std::string numberString = boost::lexical_cast<std::string>(&playerNameLabel[i]);
        QString numberQString = QString::fromStdString(numberString);
        playerNameLabel[i] = new QLabel(numberQString);
        //vbox->addWidget(playerNameLineEdit[i]);
        //vbox->addWidget(playerNameLabel[i]);
        vl->addWidget(playerNameLabel[i]);
        vl->addWidget(playerNameLineEdit[i]);
        */

        v->setLayout(vl);
        vbox->addWidget(v);
        //connect(playerNameLineEdit[i], SIGNAL (textEdited( const QString &)), this, SLOT (enableOrDisableConfirmButton( const QString &)));
        //hash[&playerNameLineEdit[i]] = i;

    }

    for(int i=numberOfPlayers; i<6; i++) {
        playerNameLabel[i]->setDisabled(true);
        playerNameLineEdit[i]->setDisabled(true);
    }


    groupBox->setLayout(vbox);

    return groupBox;
}
