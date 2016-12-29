#include <QtWidgets>
#include "numberofplayers.h"
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
    QGroupBox *groupBox = new QGroupBox("Select the number of players for the new game");

    //QRadioButton *radio1 = new QRadioButton(groupBox->title());
    QRadioButton *number3RadioButton = new QRadioButton("3");
    QRadioButton *radio2 = new QRadioButton("4");
    QRadioButton *radio3 = new QRadioButton("5");
    QRadioButton *radio4 = new QRadioButton("6");

    QRadioButton *numberOfPlayersRadioButton[4];



    QPushButton *m_button = new QPushButton("Ok", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNewWindow()));

    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->addWidget(number3RadioButton);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    vbox->addWidget(m_button);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    for(int i=0; i<4; i++) {
        std::string numberString = boost::lexical_cast<std::string>(i+3);
        QString numberQString = QString::fromStdString(numberString);
        numberOfPlayersRadioButton[i] = new QRadioButton(numberQString);
        vbox->addWidget(numberOfPlayersRadioButton[i]);
    }

    return groupBox;
}

void NumberOfPlayers::openNewWindow()
{
    radio3->setEnabled(not(radio3->isEnabled()));
    radio3->setChecked(false);
}

//virtual ~Communicate() {};
