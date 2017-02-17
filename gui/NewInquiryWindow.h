#ifndef NEWINQUIRYWINDOW_H
#define NEWINQUIRYWINDOW_H

#include "gui/InquiryHistoryWindow.h"
#include <QCheckBox>
#include <QDialog>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QObject>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>
#include <boost/lexical_cast.hpp>
#include <game/Game.h>
#include <gui/CardTableWindow.h>

class Game;
class CardTableWindow;
class InquiryHistoryWindow;

/*!
 * \brief Window to insert a new inquiry
 *
 * When one player has made a new inquiry, the user can use this window to insert it: the user can
 * specify the inquirer, the called cards and the giver.
 */
class NewInquiryWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Create the windo
     * \param game pointer to the Game instance
     * \param inquiryHistoryWindow pointer to the InquiryHistoryWindow instance
     * \param parent the parent of the window
     */
    NewInquiryWindow(Game* game, InquiryHistoryWindow* inquiryHistoryWindow,
                     QWidget* parent = 0);

private:
    Game* game;
    CardTableWindow* gw;
    QRadioButton* callerRadioButton[6];
    QRadioButton* roomCardRadioButton[10];
    QRadioButton* suspectCardRadioButton[6];
    QRadioButton* weaponCardRadioButton[6];
    QRadioButton* giverRadioButton[7];
    InquiryHistoryWindow* inquiryHistoryWindow;

    void closeEvent(QCloseEvent* e);
    QGroupBox* foo(QString string, std::vector<QString> list, QRadioButton* radioButtonArray[]);

private slots:
    void openNewWindow();
};

#endif // NEWINQUIRYWINDOW_H
