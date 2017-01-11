#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "gui/NewInquiryWindow.h"
#include <Game.h>
#include <QLabel>
#include <QTableWidget>
#include <gui/InquiryHistoryWindow.h>

class Game;
class QPushButton;

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(Game *game, QWidget *parent = 0);

    Game *game;
    QLabel *label;
    QPushButton *m_button2;
    QTableWidget *cardTable;

    void myupdate();

public slots:
    void openQueryListWindow();
    void test();
};

#endif // GAMEWINDOW_H
