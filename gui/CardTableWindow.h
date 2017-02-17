#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "gui/NewInquiryWindow.h"
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QTableWidget>
#include <QWidget>
#include <game/Game.h>
#include <gui/CardTableWindow.h>
#include <gui/InquiryHistoryWindow.h>

class Game;
class QPushButton;

/*!
 * \brief Show the current knowledge about cards
 *
 * With this window the user can check what the program knows at the moment about the cards: by
 * means of tables, the window show for each card which is the owner or the possible owners
 * (considering also that a card can be "held", i.e. inserted, in the envelop).
 *
 *
 * The tables are updated by the program during the game every time new information is discovered.
 *
 */
class CardTableWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Create the window
     * \param game pointer to the Game instance
     * \param parent the parent of the window
     *
     */
    CardTableWindow(Game* game, QWidget* parent = 0);

    //void myupdate();
    //void updateCardTable(QString card, QString player, QString value);
    //void myupdate2();

private:
    Game* game;
    QTableWidget* cardSubTable;

    std::vector<QString> playerList;
    std::vector<QString> roomCardList;
    std::vector<QString> suspectCardList;
    std::vector<QString> weaponCardList;

    QTableWidget* createCardSubTable(std::vector<QString> cardList);
    void closeEvent(QCloseEvent* e);

    CardTableWindow* g;
};

#endif // GAMEWINDOW_H
