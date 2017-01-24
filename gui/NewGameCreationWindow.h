#ifndef NEWGAMECREATIONWINDOW_H
#define NEWGAMECREATIONWINDOW_H

#include <QDialog>

class NewGameCreationWindow : public QDialog
{
    Q_OBJECT

public:
    NewGameCreationWindow();

private slots:
    /*!
     * \brief Function called when the confirm button of the window is clicked by the user.
     *
     * When the user clicks the confirm button of the window, actions related to the window have
     * to be taken to process the data inserted by the user using the window.
     */
    virtual void confirmButtonClicked() = 0;
};

#endif // NEWGAMECREATIONWINDOW_H
