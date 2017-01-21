#ifndef NEWINQUIRYWINDOW_H
#define NEWINQUIRYWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QHBoxLayout>
#include <game/Game.h>
#include <gui/GameWindow.h>
#include <QRadioButton>
#include <boost/lexical_cast.hpp>
#include <QDialog>
#include "gui/InquiryHistoryWindow.h"

class Game;
class GameWindow;
class InquiryHistoryWindow;

class NewInquiryWindow : public QDialog
{
    Q_OBJECT

public:
    NewInquiryWindow(Game *g, InquiryHistoryWindow *i, QWidget *parent = 0);
    Game *game;
    GameWindow *gw;

private:
    QRadioButton *callerRadioButton[6];
    QRadioButton *roomCardCheckBox[10];
    QRadioButton *suspectCardCheckBox[6];
    QRadioButton *weaponCardCheckBox[6];
    QRadioButton *giverRadioButton[7];
    InquiryHistoryWindow *i;

    void closeEvent(QCloseEvent *e);

public slots:
    void openNewWindow();

private slots:
    void mydo();
};

#endif // NEWINQUIRYWINDOW_H
