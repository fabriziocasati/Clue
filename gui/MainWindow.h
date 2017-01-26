#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMdiArea>
#include "game/Game.h"
#include "gui/InquiryHistoryWindow.h"
#include "gui/GameWindow.h"
#include "game/NewGameCreator.h"

class QPushButton;
class QRadioButton;
class QGroupBox;
class QGridLayout;
class Main;
class QMdiArea;
class Game;
class GameWindow;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void resizeEvent (QResizeEvent* event);
    QPixmap* m_pPixmap;
    QPalette* m_pPalette;

    void setSubwindow(QWidget *q);
    void createNewGame();
    void setGame(Game *game);

    void myupdate();

private:
    Main *main;
    QMenu *fileMenu;
    QPushButton *m_button;
    QRadioButton *r_button;
    QGroupBox *createFirstExclusiveGroup();
    QMdiArea *area;

    Game *game;

    void createMenus();

    InquiryHistoryWindow *i;

    GameWindow *g;



private slots:
    void showCardTableWindow();
    void showNewInquiryInsertionWindow();
    void showInquiryHistoryWindow();

};

#endif // MAINWINDOW_H
