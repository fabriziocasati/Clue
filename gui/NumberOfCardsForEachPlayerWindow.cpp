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

    /* Store pointer to the NewGameCreator instance and use it to retrieve the necessary data */
    this->newGameCreator = newGameCreator;
    this->numberOfPlayers = newGameCreator->getNumberOfPlayers();
    this->playerName = newGameCreator->getNamesOfThePlayers();

    /* Create window layout */
    QVBoxLayout *windowLayout = new QVBoxLayout;

    /* Create the groupbox containing the radio buttons to select the number of cards for each player */
    windowLayout->addWidget(createNumberOfPlayersGroupBox(), 0, Qt::AlignCenter);

    /* Create confirm button and add it to the window */
    confirmButton = createConfirmButton();
    windowLayout->addWidget(confirmButton, 1, Qt::AlignCenter);

    /* Window settings */
    setWindowTitle("Number of Cards for each Player");
    setLayout(windowLayout);
    setModal(true);

}

QPushButton* NumberOfCardsForEachPlayerWindow::createConfirmButton() {
    QPushButton* confirmButton = new QPushButton("Ok", this);
    connect(confirmButton, SIGNAL (clicked()), this, SLOT (confirmButtonClicked()));
    return confirmButton;
}

QGroupBox* NumberOfCardsForEachPlayerWindow::createNumberOfPlayersGroupBox() {

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
