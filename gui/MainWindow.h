#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game/Game.h"
#include "game/NewGameCreator.h"
#include "gui/CardTableWindow.h"
#include "gui/InquiryHistoryWindow.h"
#include <QMainWindow>
#include <QMdiArea>
#include <QWidget>

class QPushButton;
class QRadioButton;
class QGroupBox;
class QGridLayout;
class Main;
class QMdiArea;
class Game;
class CardTableWindow;
class NewInquiryWindow;
class InquiryHistoryWindow;
class Reasoner;

/*!
 * \brief The main window
 *
 * This is the main window of the program: it is the first window that is shown, and it contains all
 * the other windows (i.e., subwindows) that are used by the user.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    void resizeEvent (QResizeEvent* event);
    QPixmap* m_pPixmap;
    QPalette* m_pPalette;

    void setSubwindow(QWidget* q);
    void createNewGame();
    void setGame(Game* game);

    void myupdate();

    CardTableWindow* getCardTableWindow();

private:
    Main* main;
    QMenu* fileMenu;
    QPushButton* m_button;
    QRadioButton* r_button;
    QGroupBox* createFirstExclusiveGroup();
    QMdiArea* area;

    Game* game;

    void createMenus();

    InquiryHistoryWindow* i;
    CardTableWindow* g;
    NewInquiryWindow* n;

    QMenu* windowMenu;

    Reasoner *reasoner;

private slots:
    void showCardTableWindow();
    void showNewInquiryInsertionWindow();
    void showInquiryHistoryWindow();
};

#endif // MAINWINDOW_H
