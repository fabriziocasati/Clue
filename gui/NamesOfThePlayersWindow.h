#ifndef NAMESOFTHEPLAYERS_H
#define NAMESOFTHEPLAYERS_H

#include <QWidget>
#include <QHash>
#include "gui/MainWindow.h"
#include "NewGameCreator.h"

class QGroupBox;
class QPushButton;
class QLineEdit;
class QLabel;
class NewGameCreator;

class NamesOfThePlayers  : public QWidget
{
     Q_OBJECT

public:
    NamesOfThePlayers(int numberOfPlayers, MainWindow *mainWindow, NewGameCreator *newGameCreator, QWidget *parent = 0);
    int getNumberOfPlayers();

public slots:
    void openNumberOfCardsForEachPlayerWindow();
    void enableOrDisableConfirmButton(const QString &text);

private:
        QGroupBox *createNumberOfPlayersGroup(int numberOfPlayers);
        QPushButton *m_button;
        int nonEmptyName[6];
        int nonEmptyNames = 0;
        QHash<QLineEdit**, int> hash;
        QLineEdit *playerNameLineEdit[6];
        QLabel *playerNameLabel[6];
        MainWindow *mainWindow;
        NewGameCreator *newGameCreator;

};

#endif // NAMESOFTHEPLAYERS_H
