#ifndef NAMESOFTHEPLAYERS_H
#define NAMESOFTHEPLAYERS_H

#include <QWidget>
#include <QHash>

class QGroupBox;
class QPushButton;
class QLineEdit;

class NamesOfThePlayers  : public QWidget
{
     Q_OBJECT

public:
    NamesOfThePlayers(int numberOfPlayers, QWidget *parent = 0);
public slots:
    void openNumberOfCardsForEachPlayerWindow();
    void enableOrDisableConfirmButton(const QString &text);

private:
        QGroupBox *createNumberOfPlayersGroup(int numberOfPlayers);
        QPushButton *m_button;
        int nonEmptyName[6];
        int nonEmptyNames = 0;
        QHash<QLineEdit**, int> hash;

};

#endif // NAMESOFTHEPLAYERS_H
