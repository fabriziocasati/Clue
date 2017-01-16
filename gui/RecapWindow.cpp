#include "RecapWindow.h"
#include <boost/lexical_cast.hpp>
#include <QDebug>

RecapWindow::RecapWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QWidget(parent)
{
    this->newGameCreator = newGameCreator;
    int numberOfPlayers = newGameCreator->getNumberOfPlayers();
    std::vector<QString> userCards = newGameCreator->getCardsOfTheUser();
    std::vector<int> playerCardsNumber = newGameCreator->getNumberOfCardsForEachPlayer();

    QGroupBox *groupBox = new QGroupBox("Insert the number of cards held by each player");
    QVBoxLayout *vbox = new QVBoxLayout;

    QPushButton *m_button = new QPushButton("numberQString", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNextWindow()));

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
        std::string numberString = boost::lexical_cast<std::string>(*it);
        QString numberQString = QString::fromStdString(numberString);
        QLabel *l = new QLabel(numberQString);
        vbox->addWidget(l);
    }

    for (std::vector<QString>::iterator it = userCards.begin() ; it != userCards.end(); ++it) {
        qDebug() << "3: " << *it;
        QLabel *l = new QLabel(*it);
        vbox->addWidget(l);
    }

    vbox->addWidget(m_button);
    setLayout(vbox);
}

void RecapWindow::openNextWindow(){
    newGameCreator->openNextWindow();
}

