#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <newinquirywindow.h>
#include <game.h>
#include <QLabel>

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

    void myupdate();

public slots:
    void openQueryListWindow();
};

#endif // GAMEWINDOW_H
