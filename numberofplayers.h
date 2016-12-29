#ifndef NUMBEROFPLAYERS_H
#define NUMBEROFPLAYERS_H

#define MAX_NUMBER_OF_PLAYERS 6
#define MIN_NUMBER_OF_PLAYERS 3

#include <QMainWindow>
#include <QWidget>

class QGroupBox;
class QRadioButton;

namespace Ui {
class NumberOfPlayers;
}

class NumberOfPlayers : public QWidget
{
    Q_OBJECT

public:
    explicit NumberOfPlayers(QWidget *parent = 0);

public slots:
    void openNamesOfThePlayersWindow();

private:
        QGroupBox *createNumberOfPlayersGroup();
        QRadioButton *radio3;
        QRadioButton *numberOfPlayersRadioButton[MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1];



};

#endif // NUMBEROFPLAYERS_H
