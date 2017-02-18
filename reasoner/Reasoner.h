#ifndef REASONER_H
#define REASONER_H

#include "game/Inquiry.h"
#include "game/Game.h"

class Game;
class MainWindow;

class Reasoner
{
public:
    Reasoner(Game *game, MainWindow *mainWindow);

    void signalNewInquiry(Inquiry *inquiry);
    void foo(QString card, QString owner);

private:
    Game *game;
    MainWindow *mainWindow;
    std::vector<QString> userCards;
    QHash< QString, QHash<QString, QString> > roomCardTable;
    //std::vector<QString> roomCards;

    QList<QString> roomCardQList;
    QList<QString> suspectCardQList;
    QList<QString> weaponCardQList;
    QList<QString> userCardQList;

    QString userName;

    void setUserCards();
};

#endif // REASONER_H
