#ifndef NAMESOFTHEPLAYERSWINDOW_H
#define NAMESOFTHEPLAYERSWINDOW_H

#include "NewGameCreationWindow.h"

class QGroupBox;
class QPushButton;
class QLineEdit;
class QLabel;
class NewGameCreator;

class NamesOfThePlayersWindow  : public NewGameCreationWindow
{
     Q_OBJECT

    public:
        NamesOfThePlayersWindow(NewGameCreator *newGameCreator, QWidget *parent = 0);

    public slots:
        void enableOrDisableConfirmButton(const QString &text);

    private:
        QGroupBox *createNumberOfPlayersGroup();
        QPushButton *m_button;
        int nonEmptyName[6];
        int nonEmptyNames = 0;
        QHash<QLineEdit**, int> hash;
        QLineEdit *playerNameLineEdit[6];
        QLabel *playerNameLabel[6];
        NewGameCreator *newGameCreator;
        int numberOfPlayers;

private slots:
    /*!
     * \brief Function called when the confirm button of the window is clicked
     *
     * When the confirm button of the window is clicked, this function detects which radio
     * buttons were checked by the user in order to compute the number of cards held by each
     * player; these data are then passed to the Game instance, and then signals to MainWindow
     * that the next window for data insertion must be shown.
     */
    void confirmButtonClicked();

};

#endif // NAMESOFTHEPLAYERSWINDOW_H
