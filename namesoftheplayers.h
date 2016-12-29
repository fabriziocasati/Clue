#ifndef NAMESOFTHEPLAYERS_H
#define NAMESOFTHEPLAYERS_H

#include <QWidget>

class QGroupBox;

class NamesOfThePlayers  : public QWidget
{
     Q_OBJECT

public:
    NamesOfThePlayers(int numberOfPlayers, QWidget *parent = 0);
public slots:
    void openNamesOfThePlayersWindow();

private:
        QGroupBox *createNumberOfPlayersGroup(int numberOfPlayers);

};

#endif // NAMESOFTHEPLAYERS_H
