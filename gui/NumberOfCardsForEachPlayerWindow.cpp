#include "NumberOfCardsForEachPlayerWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QRadioButton>

#include "NamesOfThePlayersWindow.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>
#include <QDebug>
#include "ClueSolver.h"

NumberOfCardsForEachPlayerWindow::NumberOfCardsForEachPlayerWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QDialog(parent) {

    this->newGameCreator = newGameCreator;
    this->numberOfPlayers = newGameCreator->getNumberOfPlayers();
    this->playerName = newGameCreator->getNamesOfThePlayers();

    QVBoxLayout *v = new QVBoxLayout;

    m_button = new QPushButton("Ok", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (confirmButtonClicked()));

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

    int i=0, j;
     for (std::vector<QString>::iterator it = playerName.begin() ; it != playerName.end(); ++it, i++) {
        QGroupBox *v = new QGroupBox(*it);

        QVBoxLayout *vl = new QVBoxLayout;

        for(j=3; j<=6; j++) {
            radioButton[i][j - 3] = new QRadioButton(intToQString(j) + " cards");
            vl->addWidget(radioButton[i][j - 3]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

        QFrame* line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        vbox->addWidget(line);

        vbox->addSpacing(10);

    }

    groupBox->setLayout(vbox);

    return groupBox;

}

void NumberOfCardsForEachPlayerWindow::confirmButtonClicked() {
    std::vector<int> playerCardsNumber;
    int i, j;
    for(i=0; i<numberOfPlayers; i++)
        for(j=0; j<=6 - 3; j++)
            if(radioButton[i][j]->isChecked())
                playerCardsNumber.push_back(j + 3);
    newGameCreator->setNumberOfCardsForEachPlayer(playerCardsNumber);
    newGameCreator->openNextWindow();
    close();
}
