#include "RecapWindow.h"
#include <boost/lexical_cast.hpp>
#include <QDebug>

RecapWindow::RecapWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QWidget(parent)
{
    this->newGameCreator = newGameCreator;
    int numberOfPlayers = newGameCreator->getNumberOfPlayers();
    std::vector<int> playerCardsNumber = newGameCreator->getNumberOfCardsForEachPlayer();

    QGroupBox *groupBox = new QGroupBox("Insert the number of cards held by each player");
    QVBoxLayout *vbox = new QVBoxLayout;

    /*
    for(int i=0; i < numberOfPlayers; i++) {
        qDebug() << "3: " << playerCardsNumber[i];
        std::string numberString = boost::lexical_cast<std::string>(playerCardsNumber[i]);
        QString numberQString = QString::fromStdString(numberString);
        QLabel *l = new QLabel(numberQString);
        vbox->addWidget(l);
    }
    */

    for (std::vector<int>::iterator it = playerCardsNumber.begin() ; it != playerCardsNumber.end(); ++it) {
        qDebug() << "3: " << *it;
        std::string numberString = boost::lexical_cast<std::string>(*it);
        QString numberQString = QString::fromStdString(numberString);
        QLabel *l = new QLabel(numberQString);
        vbox->addWidget(l);
    }

    setLayout(vbox);
}

