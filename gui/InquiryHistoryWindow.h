#ifndef INQUIRYHISTORYWINDOW_H
#define INQUIRYHISTORYWINDOW_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include "game/Game.h"

class Game;

class InquiryHistoryWindow : public QWidget
{
public:
    InquiryHistoryWindow(Game *g, QWidget *parent = 0);
    Game *g;

    QTableWidget *inquiryHistoryTable;
};

#endif // INQUIRYHISTORYWINDOW_H
