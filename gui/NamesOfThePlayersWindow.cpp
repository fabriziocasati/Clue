#include "NamesOfThePlayersWindow.h"
#include <QtWidgets>
#include <boost/lexical_cast.hpp>
#include "NumberOfCardsForEachPlayerWindow.h"

NamesOfThePlayers::NamesOfThePlayers(int numberOfPlayers, MainWindow *mainWindow, QWidget *parent)
    : QWidget(parent)
{
    this->mainWindow = mainWindow;

    QString key="1";

    int p = 1914;

    //hash.insert(key,p);
    //hash["1"] = 10;

    nonEmptyNames = 0;

    //std::string numberString = boost::lexical_cast<std::string>(hash["1"]);
    //QString numberQString = QString::fromStdString(numberString);
    m_button = new QPushButton("numberQString", this);

    for(int i=0; i<6; i++)
    nonEmptyName[i] = 0;


    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createNumberOfPlayersGroup(numberOfPlayers), 2, 0);

    setLayout(grid);

    setWindowTitle("Number of Players");
    //resize(480, 320);

}

QGroupBox *NamesOfThePlayers::createNumberOfPlayersGroup(int numberOfPlayers)
{

    std::string numberString = boost::lexical_cast<std::string>(numberOfPlayers);
    QString numberQString = QString::fromStdString(numberString);

    QGroupBox *groupBox = new QGroupBox("Insert the names of the players");

    //QPushButton *m_button = new QPushButton(numberQString, this);

    m_button->setDisabled(true);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNumberOfCardsForEachPlayerWindow()));

    QVBoxLayout *vbox = new QVBoxLayout;
    //vbox->setAlignment(Qt::AlignLeft);
    vbox->addWidget(m_button);
    //vbox->addStretch(1);



    for(int i=0; i<6; i++) {
        QGroupBox *v = new QGroupBox("Player");
        QHBoxLayout *vl = new QHBoxLayout;
        playerNameLineEdit[i] = new QLineEdit();
        //std::string numberString = "Name of the player #" + boost::lexical_cast<std::string>(i+1) + ":";
        std::string numberString = boost::lexical_cast<std::string>(&playerNameLabel[i]);
        QString numberQString = QString::fromStdString(numberString);
        playerNameLabel[i] = new QLabel(numberQString);
        //vbox->addWidget(playerNameLineEdit[i]);
        //vbox->addWidget(playerNameLabel[i]);
        vl->addWidget(playerNameLabel[i]);
        vl->addWidget(playerNameLineEdit[i]);
        v->setLayout(vl);
        vbox->addWidget(v);
        connect(playerNameLineEdit[i], SIGNAL (textEdited( const QString &)), this, SLOT (enableOrDisableConfirmButton( const QString &)));
        hash[&playerNameLineEdit[i]] = i;
    }

    for(int i=numberOfPlayers; i<6; i++) {
        playerNameLabel[i]->setDisabled(true);
        playerNameLineEdit[i]->setDisabled(true);
    }


    groupBox->setLayout(vbox);

    return groupBox;
}

void NamesOfThePlayers::openNumberOfCardsForEachPlayerWindow()
{
    std::string playerName[6];
    for(int i=0; i<6; i++) {
        //playerName[i] = playerNameLineEdit[i]->selectedText();
        playerNameLabel[i]->setText(playerNameLineEdit[i]->text());
    }
    NumberOfCardsForEachPlayerWindow *w = new NumberOfCardsForEachPlayerWindow();
    //w->show();
    mainWindow->setSubwindow(w);
    //this->close();
}

void NamesOfThePlayers::enableOrDisableConfirmButton(const QString &text)
{
    QLineEdit** obj = (QLineEdit**) sender();
    if(text.isEmpty()) {
        if(hash[obj] != 0) {
            hash[obj] = 0;
            nonEmptyNames = nonEmptyNames - 1;
        }
    } else {
        if(hash[obj] == 0) {
            hash[obj] = 1;
            nonEmptyNames = nonEmptyNames + 1;
        }
    }
    if(nonEmptyNames > 0)
        m_button->setDisabled(false);
    else
        m_button->setDisabled(true);
    std::string numberString = boost::lexical_cast<std::string>(nonEmptyNames) ;
    QString numberQString = QString::fromStdString(numberString);
    m_button->setText(numberQString);
}
