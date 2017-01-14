#ifndef NUMBEROFPLAYERSWINDOW_H
#define NUMBEROFPLAYERSWINDOW_H

#define MAX_NUMBER_OF_PLAYERS 6
#define MIN_NUMBER_OF_PLAYERS 3

#include <QMainWindow>
#include <QWidget>
#include "NewGameCreator.h"

class QGroupBox;
class QRadioButton;
class QPushButton;
class NewGameCreator;

class NumberOfPlayersWindow : public QWidget {
    Q_OBJECT

    public:
        explicit NumberOfPlayersWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

    public slots:
        void openNamesOfThePlayersWindow();
        void activateConfirmButton();

    private:
        QPushButton *m_button;
        QRadioButton *numberOfPlayersRadioButton[MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1];
        NewGameCreator *newGameCreator;
};

#endif // NUMBEROFPLAYERSWINDOW_H
