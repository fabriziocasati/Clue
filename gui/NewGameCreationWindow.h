#ifndef NEWGAMECREATIONWINDOW_H
#define NEWGAMECREATIONWINDOW_H

#include <QDialog>
#include <QtWidgets> // required by QCloseEvent

/*!
 * \brief Parent class of windows used to create a new game
 *
 * This class is the parent of all the windows that are used to create a new game. It is a QDialog
 * to center it and it is modal to avoid that the user, when one of the children windows of this
 * class is opened, does something else than inserting the data required by the children window.
 */
class NewGameCreationWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Create the window
     * \param parent the parent of the window
     *
     * Create the window and set it to be modal.
     */
    NewGameCreationWindow(QWidget* parent = 0);

protected:
    /*! The confirm button of the window */
    QPushButton* confirmButton;

    /*!
     * \brief Create and return the confirm button of the window
     * \return the confirm button of the window
     *
     * A confirm button for the window is created and returned. This button is connected to the
     * confirmButtonClicked() slot, which is called when the button is clicked by the user.
     *
     * By default, the button is disabled.
     */
    QPushButton* createConfirmButton();

    /*!
     * \brief Reimplementation of QDialog::closeEvent()
     * \param e The QCloseEvent instance
     *
     * To avoid that the window is closed by the user not in the proper way (i.e., by pressing
     * the confirm button), this function is reimplemented. In particular, when a close event is
     * created, it is ignored by the window and so the window doesn't close.
     */
    void closeEvent(QCloseEvent* closeEvent);

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
