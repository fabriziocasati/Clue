#ifndef NAMESOFTHEPLAYERS_H
#define NAMESOFTHEPLAYERS_H

#include <QWidget>
#include <QHash>
#include "gui/MainWindow.h"

class QGroupBox;
class QPushButton;
class QLineEdit;
class QLabel;

class NamesOfThePlayers  : public QWidget
{
     Q_OBJECT

public:
    NamesOfThePlayers(int numberOfPlayers, MainWindow *mainWindow, QWidget *parent = 0);
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

};

#endif // NAMESOFTHEPLAYERS_H
