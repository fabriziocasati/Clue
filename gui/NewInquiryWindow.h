#ifndef NEWINQUIRYWINDOW_H
#define NEWINQUIRYWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QHBoxLayout>
#include <Game.h>
#include <gui/GameWindow.h>
#include <QRadioButton>
#include <boost/lexical_cast.hpp>

class Game;
class GameWindow;

class NewInquiryWindow : public QWidget
{
    Q_OBJECT

public:
    NewInquiryWindow(Game *g, QWidget *parent = 0);
    Game *game;
    GameWindow *gw;

private:
    QRadioButton *callerRadioButton[6];
    QRadioButton *roomCardCheckBox[10];
    QRadioButton *suspectCardCheckBox[6];
    QRadioButton *weaponCardCheckBox[6];
    QRadioButton *giverRadioButton[7];

public slots:
    void openNewWindow();
};

#endif // NEWINQUIRYWINDOW_H
