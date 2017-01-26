#include "NamesOfThePlayersWindow.h"
#include "NumberOfCardsForEachPlayerWindow.h"
#include <QString>
#include <QtWidgets>
#include <boost/lexical_cast.hpp>

NamesOfThePlayersWindow::NamesOfThePlayersWindow(NewGameCreator* newGameCreator, QWidget* parent)
    : NewGameCreationWindow(parent)
{
    this->newGameCreator = newGameCreator;
    this->numberOfPlayers = newGameCreator->getNumberOfPlayers();

    nonEmptyNames = 0;

    m_button = new QPushButton("Ok", this);

    for(int i = 0; i < 6; i++)
        nonEmptyName[i] = 0;

    QVBoxLayout* grid = new QVBoxLayout;
    grid->addWidget(createNumberOfPlayersGroup(), 0, Qt::AlignCenter);
    grid->addWidget(m_button, 1, Qt::AlignCenter);

    setLayout(grid);

    setWindowTitle("Names of the Players");
}

QGroupBox* NamesOfThePlayersWindow::createNumberOfPlayersGroup()
{
    std::string numberString = boost::lexical_cast<std::string>(numberOfPlayers);
    QString numberQString = QString::fromStdString(numberString);

    QGroupBox* groupBox = new QGroupBox("Insert the names of the players");

    m_button->setDisabled(true);
    connect(m_button, SIGNAL (clicked()), this, SLOT (confirmButtonClicked()));

    QGridLayout* vbox = new QGridLayout();
    vbox->addWidget(m_button);
    vbox->setSpacing(10);

    for(int i = 0; i < numberOfPlayers; i++)
    {
        QGroupBox* v = new QGroupBox();
        QHBoxLayout* vl = new QHBoxLayout;
        playerNameLineEdit[i] = new QLineEdit();
        std::string numberString = "Player #" + boost::lexical_cast<std::string>(i + 1) +
                                   ":";
        QString numberQString = QString::fromStdString(numberString);
        playerNameLabel[i] = new QLabel(numberQString);
        //vbox->addWidget(playerNameLineEdit[i]);
        //vbox->addWidget(playerNameLabel[i]);
        //vl->addWidget(playerNameLabel[i]);
        //vl->addWidget(playerNameLineEdit[i]);
        //v->setLayout(vl);
        //vbox->addWidget(v);
        vbox->addWidget(playerNameLabel[i], i * 2, 0);
        vbox->addWidget(playerNameLineEdit[i], i * 2, 1);
        /*
         *    QFrame* line = new QFrame();
         *    line->setFrameShape(QFrame::HLine);
         *    line->setFrameShadow(QFrame::Sunken);
         *    vbox->addWidget(line);
         */
        connect(playerNameLineEdit[i], SIGNAL (textEdited(const QString&)), this,
                SLOT (enableOrDisableConfirmButton(const QString&)));
        hash[&playerNameLineEdit[i]] = i;
    }

    /*
     *    for(int i=numberOfPlayers; i<6; i++) {
     *     playerNameLabel[i]->setDisabled(true);
     *     playerNameLineEdit[i]->setDisabled(true);
     *    }
     */

    groupBox->setLayout(vbox);

    return groupBox;
}

void NamesOfThePlayersWindow::confirmButtonClicked()
{
    std::vector<QString> playerName;
    for(int i = 0; i < numberOfPlayers; i++)
        playerName.push_back(playerNameLineEdit[i]->text());
    newGameCreator->setNamesOfThePlayers(playerName);
    newGameCreator->openNextWindow();

    //this->parentWidget()->close();
    destroy();
}

void NamesOfThePlayersWindow::enableOrDisableConfirmButton(const QString &text)
{
    QLineEdit** obj = (QLineEdit**) sender();
    if(text.isEmpty())
    {
        if(hash[obj] != 0)
        {
            hash[obj] = 0;
            nonEmptyNames = nonEmptyNames - 1;
        }
    }
    else if(hash[obj] == 0)
    {
        hash[obj] = 1;
        nonEmptyNames = nonEmptyNames + 1;
    }
    if(nonEmptyNames == newGameCreator->getNumberOfPlayers())
        m_button->setDisabled(false);
    else
        m_button->setDisabled(true);
}
