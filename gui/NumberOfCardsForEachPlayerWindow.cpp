#include "NumberOfCardsForEachPlayerWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QRadioButton>

#include "NamesOfThePlayersWindow.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>

NumberOfCardsForEachPlayerWindow::NumberOfCardsForEachPlayerWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QWidget(parent)
{
    this->newGameCreator = newGameCreator;
    //int numberOfPlayers = newGameCreator->getNumberOfPlayers();

    QString key="1";

    int p = 1914;

    //hash.insert(key,p);
    //hash["1"] = 10;

    //std::string numberString = boost::lexical_cast<std::string>(hash["1"]);
    //QString numberQString = QString::fromStdString(numberString);
    m_button = new QPushButton("numberQString", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNextWindow()));


    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createNumberOfPlayersGroup(6), 2, 0);

    setLayout(grid);

    setWindowTitle("Number of Players");
    //resize(480, 320);

}

QGroupBox* NumberOfCardsForEachPlayerWindow::createNumberOfPlayersGroup(int numberOfPlayers)
{

    std::string numberString = boost::lexical_cast<std::string>(numberOfPlayers);
    QString numberQString = QString::fromStdString(numberString);

    QGroupBox *groupBox = new QGroupBox("Insert the number of cards held by each player");

    QVBoxLayout *vbox = new QVBoxLayout;
    //vbox->setAlignment(Qt::AlignLeft);
    vbox->addWidget(m_button);
    //vbox->addStretch(1);

    for(int i=0; i<6; i++) {
        std::string numberString = "Player #" + boost::lexical_cast<std::string>(i+1);
        QString numberQString = QString::fromStdString(numberString);
        QGroupBox *v = new QGroupBox(numberQString);

        QHBoxLayout *vl = new QHBoxLayout;

        for(int i=0; i<6; i++) {
            std::string numberString = boost::lexical_cast<std::string>(i);
            QString numberQString = QString::fromStdString(numberString);
            QRadioButton *r = new QRadioButton(numberQString);
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

void NumberOfCardsForEachPlayerWindow::openNextWindow() {
    newGameCreator->openNextWindow();
}
