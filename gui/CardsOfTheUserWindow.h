#ifndef CARDSOFTHEUSERWINDOW_H
#define CARDSOFTHEUSERWINDOW_H

#include <QObject>
#include <QWidget>
#include "game/NewGameCreator.h"
#include <QPushButton>
#include <QGroupBox>
#include <QDialog>


class CardsOfTheUserWindow : public NewGameCreationWindow
{
    Q_OBJECT

    public:
        CardsOfTheUserWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

    private:
        NewGameCreator *newGameCreator;
        QPushButton *confirmButton;

        QGroupBox* createGroupBoxes();

        int nonEmptyName[6];
        int nonEmptyNames = 0;
        QHash<QLineEdit**, int> hash;
        QLineEdit *playerNameLineEdit[6];
        QLabel *playerNameLabel[6];

        QCheckBox *roomCardCheckBox[9];
        QCheckBox *suspectCardCheckBox[9];
        QCheckBox *weaponCardCheckBox[9];

        int userCardCount;
        int checkedCheckBoxCount;

        QGroupBox* foo(QString string, std::vector<QString> cardList, QCheckBox *cardArray[]);

    private slots:
        void confirmButtonClicked();
        void checkEnablingConditions();
};

#endif // CARDSOFTHEUSERWINDOW_H
