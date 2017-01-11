#include <QtWidgets>
#include "NumberOfPlayersWindow.h"
#include "gui/NamesOfThePlayersWindow.h"
#include <string>
#include <boost/lexical_cast.hpp>

NumberOfPlayers::NumberOfPlayers(QWidget *parent)
    : QWidget(parent)
{

    move(300,300);

    /*
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createNumberOfPlayersGroup(), 2, 0);

    setLayout(grid);
    */

    QVBoxLayout *vbox = new QVBoxLayout;


    /*
    vbox->setStretch(0,0);
    vbox->setStretchFactor(g,0);
    */



    //g->setLayout(vbox);

    QLabel *l = new QLabel("Select the number of players for the new game");
    l->setStyleSheet("font-weight: bold;");
    QGroupBox *groupBox = new QGroupBox("Select the number of players");
    //groupBox->setStyleSheet("border: 1px solid gray; border-radius: 9px; font-weight: normal;");
    //groupBox->setFlat(true);

    m_button = new QPushButton("Ok", this);
    m_button->setDisabled(true);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNamesOfThePlayersWindow()));


    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(1);
    //sizePolicy.setHeightForWidth(m_button->sizePolicy().hasHeightForWidth());
    //groupBox->setSizePolicy(sizePolicy);

    //groupBox->setFixedWidth(this->width());
    //groupBox->setFixedWidth(l->width()/2);


    //m_button->setFixedSize(QSize(150,50));
    //vbox->setAlignment(Qt::AlignLeft);

    //vbox->setStretch(0,0);



    //m_button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QVBoxLayout *hbox = new QVBoxLayout;
    //groupBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //hbox->setAlignment(Qt::AlignCenter);

    //vbox->addStretch(1);


    for(int i=0; i<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++) {
        std::string numberString = boost::lexical_cast<std::string>(i+MIN_NUMBER_OF_PLAYERS) + " players";
        QString numberQString = QString::fromStdString(numberString);
        numberOfPlayersRadioButton[i] = new QRadioButton(numberQString);
        connect(numberOfPlayersRadioButton[i], SIGNAL (clicked()), this, SLOT (activateConfirmButton()));
        //hbox->addWidget(numberOfPlayersRadioButton[i], i, Qt::AlignCenter);
        hbox->addWidget(numberOfPlayersRadioButton[i]);
        hbox->addStretch(1);
    }

    groupBox->setLayout(hbox);

    //vbox->addWidget(l, 0, Qt::AlignLeft);
    vbox->addWidget(groupBox, 0, Qt::AlignCenter);
    vbox->addWidget(m_button, 1, Qt::AlignCenter);

    /*
    QPushButton *m_button2 = new QPushButton("Ciao ciao ciao ciao!", this);
    vbox->addWidget(m_button2, 3, Qt::AlignCenter);
    */

    setWindowTitle("Number of Players");

    setLayout(vbox);

    move(300,300);


}






QGroupBox *NumberOfPlayers::createNumberOfPlayersGroup()
{
    QGroupBox *g = new QGroupBox();
    QVBoxLayout *vbox = new QVBoxLayout;

    /*
    vbox->setStretch(0,0);
    vbox->setStretchFactor(g,0);
    */



    g->setLayout(vbox);

    QLabel *l = new QLabel("Select the number of players for the new game");
    l->setStyleSheet("font-weight: bold;");
    QGroupBox *groupBox = new QGroupBox("Number orf player");
    groupBox->setStyleSheet("border: 1px solid gray; border-radius: 9px; font-weight: normal;");
    //groupBox->setFlat(true);

    m_button = new QPushButton("Ok", this);
    m_button->setDisabled(true);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNamesOfThePlayersWindow()));

    /*
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_button->sizePolicy().hasHeightForWidth());
    m_button->setSizePolicy(sizePolicy);
    */

    //m_button->setFixedSize(QSize(150,50));
    //vbox->setAlignment(Qt::AlignLeft);

    //vbox->setStretch(0,0);



    //m_button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QHBoxLayout *hbox = new QHBoxLayout;
    //hbox->setAlignment(Qt::AlignCenter);

    //vbox->addStretch(1);


    for(int i=0; i<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++) {
        std::string numberString = boost::lexical_cast<std::string>(i+MIN_NUMBER_OF_PLAYERS);
        QString numberQString = QString::fromStdString(numberString);
        numberOfPlayersRadioButton[i] = new QRadioButton(numberQString);
        connect(numberOfPlayersRadioButton[i], SIGNAL (clicked()), this, SLOT (activateConfirmButton()));
        hbox->addWidget(numberOfPlayersRadioButton[i]);
        hbox->addStretch(1);
    }

    groupBox->setLayout(hbox);
    vbox->addWidget(l, 0, Qt::AlignLeft);
    vbox->addWidget(groupBox, 1, Qt::AlignLeft);
    vbox->addWidget(m_button, 2, Qt::AlignCenter);

    QPushButton *m_button2 = new QPushButton("Ciao ciao ciao ciao!", this);
    vbox->addWidget(m_button2, 3, Qt::AlignCenter);

    return g;
}

void NumberOfPlayers::openNamesOfThePlayersWindow()
{
    int i;
    for(i=0; i<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++) {
        if(numberOfPlayersRadioButton[i]->isChecked())
            break;
    }

    NamesOfThePlayers *w = new NamesOfThePlayers(i + MIN_NUMBER_OF_PLAYERS);
    w->show();

    this->close();

}

void NumberOfPlayers::activateConfirmButton()
{
    m_button->setDisabled(false);

}
