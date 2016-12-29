#ifndef WINDOW2_H
#define WINDOW2_H

#include <QWidget>

class QGroupBox;

class Window2 : public QWidget
{
    Q_OBJECT

public:
    Window2(QWidget *parent = 0);

private:
    QGroupBox *createFirstExclusiveGroup();
    QGroupBox *createSecondExclusiveGroup();
    QGroupBox *createNonExclusiveGroup();
    QGroupBox *createPushButtonGroup();
    QGroupBox *createNumberOfPlayersGroup();
    QGroupBox *createNamesOfThePlayersGroup();
    QGroupBox *createNumberOfCardsOfThePlayersGroup();
    QGroupBox *createCardsOfTheUserGroup();
};

#endif
