#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "gui/NewInquiryWindow.h"
#include <Game.h>
#include <QLabel>
#include <QTableWidget>
#include <gui/InquiryHistoryWindow.h>
#include <QString>

class Game;
class QPushButton;

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(Game *game, QWidget *parent = 0);

    Game *game;
    QTableWidget *roomCardTable;

    void myupdate();
    void updateCardTable(QString card, QString player, QString value);

private:
    std::vector<QString> roomCardList;
    std::vector<QString> suspectCardList;
    std::vector<QString> weaponCardList;

};

#endif // GAMEWINDOW_H
