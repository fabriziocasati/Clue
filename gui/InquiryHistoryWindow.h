#ifndef INQUIRYHISTORYWINDOW_H
#define INQUIRYHISTORYWINDOW_H

#include "game/Game.h"
#include <QDialog>
#include <QObject>
#include <QTableWidget>
#include <QWidget>

class Game;

/*!
 * \brief Window that show the history of inquiries
 *
 * By means of a table, the user can checl all the inquiries that were made during the game. For
 * each inquiry, inquirier, called cards and giver are shown.
 */
class InquiryHistoryWindow : public QDialog
{
public:
    /*!
     * \brief Create the window
     * \param game pointer to the Game instance
     * \param parent the parent of the window
     */
    InquiryHistoryWindow(Game* game, QWidget* parent = 0);

    /*!
     * \brief Update the history table
     *
     * The table that shows all the historical inquiries is updated when a new inquiry has to be
     * added.
     */
    void myupdate();

private:
    Game* game;
    QTableWidget* inquiryHistoryTable;

    void closeEvent(QCloseEvent* e);
};

#endif // INQUIRYHISTORYWINDOW_H
