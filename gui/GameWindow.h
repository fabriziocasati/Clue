#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "gui/NewInquiryWindow.h"
#include <game/Game.h>
#include <QLabel>
#include <QTableWidget>
#include <gui/InquiryHistoryWindow.h>
#include <QString>
#include <QDialog>
#include <gui/GameWindow.h>

class Game;
class QPushButton;

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    GameWindow(Game *game, QWidget *parent = 0);

    Game *game;
    QTableWidget *roomCardTable;

    void myupdate();
    void updateCardTable(QString card, QString player, QString value);

    void closeEvent(QCloseEvent *e);

    void myupdate2();

private:
    std::vector<QString> playerList;
    std::vector<QString> roomCardList;
    std::vector<QString> suspectCardList;
    std::vector<QString> weaponCardList;

    GameWindow *g;

};

#endif // GAMEWINDOW_H
