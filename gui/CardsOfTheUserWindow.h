#ifndef CARDSOFTHEUSERWINDOW_H
#define CARDSOFTHEUSERWINDOW_H

#include "game/NewGameCreator.h"
#include <QDialog>
#include <QGroupBox>
#include <QObject>
#include <QPushButton>
#include <QWidget>

/*!
 * \brief Window that the user can use to specify the cards that he owns.
 *
 * The user can use this window to specify the cards that he received during the preparation phase
 * of the game. The user can select the cards from the Room, Suspect and Weapon groups.
 */
class CardsOfTheUserWindow : public NewGameCreationWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Create the window
     * \param newGameCreator pointer to the newGameCreator instance
     * \param parent the parent of the window
     */
    CardsOfTheUserWindow(NewGameCreator* newGameCreator, QWidget* parent = 0);

private:
    NewGameCreator* newGameCreator;
    QPushButton* confirmButton;

    QGroupBox* createGroupBoxes();

    int nonEmptyName[6];
    int nonEmptyNames = 0;
    QHash<QLineEdit**, int> hash;
    QLineEdit* playerNameLineEdit[6];
    QLabel* playerNameLabel[6];

    QCheckBox* roomCardCheckBox[9];
    QCheckBox* suspectCardCheckBox[9];
    QCheckBox* weaponCardCheckBox[9];

    int userCardCount;
    int checkedCheckBoxCount;

    QGroupBox* foo(QString string, std::vector<QString> cardList, QCheckBox* cardArray[]);

private slots:
    void confirmButtonClicked();
    void checkEnablingConditions();
};

#endif // CARDSOFTHEUSERWINDOW_H
