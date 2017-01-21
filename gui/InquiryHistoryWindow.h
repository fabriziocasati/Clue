#ifndef INQUIRYHISTORYWINDOW_H
#define INQUIRYHISTORYWINDOW_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include "game/Game.h"
#include <QDialog>

class Game;

class InquiryHistoryWindow : public QDialog
{
public:
    InquiryHistoryWindow(Game *g, QWidget *parent = 0);
    Game *g;

    QTableWidget *inquiryHistoryTable;

    void closeEvent(QCloseEvent *e);
    void myupdate();
};

#endif // INQUIRYHISTORYWINDOW_H
