#include <QtWidgets>
#include "NumberOfPlayersWindow.h"
#include "gui/NamesOfThePlayersWindow.h"
#include <string>
#include <boost/lexical_cast.hpp>

NumberOfPlayersWindow::NumberOfPlayersWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QWidget(parent) {

    this->newGameCreator = newGameCreator;

    //setAttribute(Qt::WA_DeleteOnClose);
    //move(300,300);

    QVBoxLayout *vbox = new QVBoxLayout;

    QLabel *l = new QLabel("Select the number of players for the new game");
    l->setStyleSheet("font-weight: bold;");
    QGroupBox *groupBox = new QGroupBox("Select the number of players");
    //groupBox->setStyleSheet("border: 1px solid gray; border-radius: 9px; font-weight: normal;");
    //groupBox->setFlat(true);

    m_button = new QPushButton("Ok", this);
    m_button->setDisabled(true);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNamesOfThePlayersWindow()));
    //connect(m_button, SIGNAL (clicked()), this->parent(), SLOT (setSubwindow(w)));

    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(1);

    QVBoxLayout *hbox = new QVBoxLayout;

    for(int i=0; i<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++) {
        std::string numberString = boost::lexical_cast<std::string>(i+MIN_NUMBER_OF_PLAYERS) + " players";
        QString numberQString = QString::fromStdString(numberString);
        numberOfPlayersRadioButton[i] = new QRadioButton(numberQString);
        connect(numberOfPlayersRadioButton[i], SIGNAL (clicked()), this, SLOT (activateConfirmButton()));
        hbox->addWidget(numberOfPlayersRadioButton[i]);
        hbox->addStretch(1);
    }

    groupBox->setLayout(hbox);

    vbox->addWidget(groupBox, 0, Qt::AlignCenter);
    vbox->addWidget(m_button, 1, Qt::AlignCenter);

    setWindowTitle("Number of Players");

    setLayout(vbox);

}

void NumberOfPlayersWindow::openNamesOfThePlayersWindow() {
    int numberOfPlayers;
    for(numberOfPlayers=0; numberOfPlayers<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; numberOfPlayers++) {
        if(numberOfPlayersRadioButton[numberOfPlayers]->isChecked())
            break;
    }

    newGameCreator->setNumberOfPlayers(numberOfPlayers);
    newGameCreator->openNextWindow();

}

void NumberOfPlayersWindow::activateConfirmButton() {
    m_button->setDisabled(false);
}
