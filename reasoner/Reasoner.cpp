#include "Reasoner.h"
#include <QDebug>

Reasoner::Reasoner(Game* game, MainWindow *mainWindow)
{
    //std::vector< std::vector<QString> > roomCardTable;

    this->game = game;
    this->mainWindow = mainWindow;
    this->userName = game->getPlayerList().front();
    qDebug() << userName;

    userCards = game->getUserCards();
    userCardQList = game->getUserCardQList();

    /*
    roomCards = game->getRoomCardList();
    std::vector<QString>::iterator it = roomCards.begin();

    for(; it != roomCards.end(); ++it) {
        qDebug() << *it;
        roomCardTable[*it]["Player"] = "No";
    }

    it = userCards.begin();

    for(; it != userCards.end(); ++it) {
        qDebug() << *it;
        roomCardTable[*it]["Player"] = "Yes";
    }

    QHash< QString, QHash<QString, QString> >::iterator it2 = roomCardTable.begin();
    for(; it2 != roomCardTable.end(); ++it2)
        qDebug() << (*it2)["Player"];

    */

    roomCardQList = game->getRoomCardQList();
    suspectCardQList = game->getSuspectCardQList();
    weaponCardQList = game->getWeaponCardQList();

    QList<QString>::iterator it = roomCardQList.begin();

    for(; it != roomCardQList.end(); ++it) {
        roomCardTable[*it]["Player"] = "No";
    }


    std::vector<QString>::iterator it2 = userCards.begin();
    for(; it2 != userCards.end(); ++it2) {
        qDebug() << "User card: " << *it2;
        roomCardTable[*it2]["Player"] = "Yes";
    }


    QHash< QString, QHash<QString, QString> >::iterator it3 = roomCardTable.begin();
    for(; it3 != roomCardTable.end(); ++it3)
        qDebug() << (*it3)["Player"];

    setUserCards();

}

void Reasoner::signalNewInquiry(Inquiry* inquiry) {

}

void Reasoner::setUserCards() {
    std::vector<QString>::iterator it = userCards.begin();
    for(; it != userCards.end(); ++it) {
        qDebug() << *it;
        //mainWindow->getCardTableWindow()->updateCardTable(*it, "Fabrizio", "Yes");
        foo(*it, userName);
    }

    QList<QString>::iterator it2 = roomCardQList.begin();

    for(; it2 != roomCardQList.end(); ++it2)
        if (!(userCardQList.contains(*it2)))
            mainWindow->getCardTableWindow()->updateCardTable(*it2, userName, "No");

    it2 = suspectCardQList.begin();
    for(; it2 != suspectCardQList.end(); ++it2)
        if (!(userCardQList.contains(*it2)))
            mainWindow->getCardTableWindow()->updateCardTable(*it2, userName, "No");

    it2 = weaponCardQList.begin();
    for(; it2 != weaponCardQList.end(); ++it2) {
        if (!(userCardQList.contains(*it2)))
            mainWindow->getCardTableWindow()->updateCardTable(*it2, userName, "No");
    }

}

void Reasoner::foo(QString card, QString owner) {
    std::vector<QString> list = game->getPlayerList();
    std::vector<QString>::iterator it = list.begin();
    QString value;
    for(; it != list.end(); ++it) {
        if ((*it).compare(owner) == 0)
            value = "Yes";
        else
            value = "No";
        mainWindow->getCardTableWindow()->updateCardTable(card, *it, value);
        roomCardTable[card][*it] = value;
    }


    /*
    std::vector<QString> userCards = game->getUserCards();
    std::vector<QString>::iterator it = game->getRoomCardList().begin();
    int ok = 0;
    int i=0;
    while(!ok && it != roomCardList.end())
    if((*it).compare(card) == 0)
      ok=1;
    else {
    ++it, i++;
    }

    qDebug() << i;

    std::vector<QString>::iterator it2;
    QTableWidgetItem *q;
    for(it = roomCardList.begin(); !ok && it != roomCardList.end(); ++it)
      if((*it).compare(*it2) == 0)
          ok = 1;
    /*
    if(value.compare("Yes") == 0) {
      q = new QTableWidgetItem("Yes");
      q->setTextColor(QColor(Qt::green));
      q->setTextAlignment(Qt::AlignCenter);
      roomCardTable->setItem(i, 3, q);
      q = new QTableWidgetItem("No");
      q->setTextColor(QColor(Qt::red));
      q->setTextAlignment(Qt::AlignCenter);
      roomCardTable->setItem(i, 0, q);
      q = new QTableWidgetItem("No");
      q->setTextColor(QColor(Qt::red));
      q->setTextAlignment(Qt::AlignCenter);
      roomCardTable->setItem(i, 1, q);
      q = new QTableWidgetItem("No");
      q->setTextColor(QColor(Qt::red));
      q->setTextAlignment(Qt::AlignCenter);
      roomCardTable->setItem(i, 2, q);
      q = new QTableWidgetItem("No");
      q->setTextColor(QColor(Qt::red));
      q->setTextAlignment(Qt::AlignCenter);
      roomCardTable->setItem(i, 4, q);
    } else {
      q = new QTableWidgetItem("No");
      q->setTextColor(QColor(Qt::red));
      q->setTextAlignment(Qt::AlignCenter);
      roomCardTable->setItem(i, 3, q);
    }
    */
}
