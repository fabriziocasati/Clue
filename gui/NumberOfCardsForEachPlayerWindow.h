#ifndef NUMBEROFCARDSFOREACHPLAYERWINDOW_H
#define NUMBEROFCARDSFOREACHPLAYERWINDOW_H

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QHash>
#include "gui/MainWindow.h"
#include "NewGameCreator.h"

class NewGameCreator;

class NumberOfCardsForEachPlayerWindow : public QWidget
{
    Q_OBJECT

    public:
        NumberOfCardsForEachPlayerWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

    private:
        NewGameCreator *newGameCreator;
        QGroupBox *createNumberOfPlayersGroup();
        QPushButton *m_button;
        int nonEmptyName[6];
        int nonEmptyNames = 0;
        QHash<QLineEdit**, int> hash;
        QLineEdit *playerNameLineEdit[6];
        QLabel *playerNameLabel[6];
        MainWindow *mainWindow;
        std::string *playerName;
        int numberOfPlayers;
        QRadioButton *radioButton[6][4];

    private slots:
        void openNextWindow();
};

#endif // NUMBEROFCARDSFOREACHPLAYERWINDOW_H
