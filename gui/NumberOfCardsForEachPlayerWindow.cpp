#include "NumberOfCardsForEachPlayerWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QRadioButton>

#include "NamesOfThePlayersWindow.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>
#include <QDebug>

NumberOfCardsForEachPlayerWindow::NumberOfCardsForEachPlayerWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QWidget(parent) {

    this->newGameCreator = newGameCreator;
    this->numberOfPlayers = newGameCreator->getNumberOfPlayers();
    this->playerName = newGameCreator->getNamesOfThePlayers();

    QVBoxLayout *v = new QVBoxLayout;

    m_button = new QPushButton("Ok", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNextWindow()));

    v->addWidget(createNumberOfPlayersGroup(), 0, Qt::AlignCenter);
    v->addWidget(m_button, 1, Qt::AlignCenter);

    setLayout(v);

    setWindowTitle("Number of Cards for each Player");

}

QGroupBox* NumberOfCardsForEachPlayerWindow::createNumberOfPlayersGroup() {

    std::string numberString = boost::lexical_cast<std::string>(numberOfPlayers);
    QString numberQString = QString::fromStdString(numberString);

    QGroupBox *groupBox = new QGroupBox("Insert the number of cards held by each player");

    QHBoxLayout *vbox = new QHBoxLayout;
    //vbox->setAlignment(Qt::AlignLeft);
    int i, j;
    for(i=0; i<numberOfPlayers; i++) {
        //std::string numberString = playerName[i] + " (Player #" + boost::lexical_cast<std::string>(i+1) + ")";
        std::string numberString = playerName[i];
        QString numberQString = QString::fromStdString(numberString);
        QGroupBox *v = new QGroupBox(numberQString);

        QVBoxLayout *vl = new QVBoxLayout;

        for(j=3; j<=6; j++) {
            std::string numberString = boost::lexical_cast<std::string>(j) + " cards";
            QString numberQString = QString::fromStdString(numberString);
            radioButton[i][j - 3] = new QRadioButton(numberQString);
            vl->addWidget(radioButton[i][j - 3]);
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

        QFrame* line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        vbox->addWidget(line);

        vbox->addSpacing(10);
        //connect(playerNameLineEdit[i], SIGNAL (textEdited( const QString &)), this, SLOT (enableOrDisableConfirmButton( const QString &)));
        //hash[&playerNameLineEdit[i]] = i;

    }

    /*
       for(int i=numberOfPlayers; i<6; i++) {
        playerNameLabel[i]->setDisabled(true);
        playerNameLineEdit[i]->setDisabled(true);
       }

     */
    groupBox->setLayout(vbox);

    return groupBox;

}

void NumberOfCardsForEachPlayerWindow::openNextWindow() {
    std::vector<int> playerCardsNumber;
    int i, j;
    for(i=0; i<numberOfPlayers; i++)
        for(j=0; j<=6 - 3; j++)
            if(radioButton[i][j]->isChecked())
                playerCardsNumber.push_back(j + 3);
    newGameCreator->setNumberOfCardsForEachPlayer(playerCardsNumber);
    newGameCreator->openNextWindow();
}
