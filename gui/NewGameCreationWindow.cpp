#include "NewGameCreationWindow.h"

NewGameCreationWindow::NewGameCreationWindow(QWidget* parent) : QDialog(parent)
{
    setModal(true);
}

QPushButton* NewGameCreationWindow::createConfirmButton() {
    QPushButton* confirmButton = new QPushButton("Ok", this);
    connect(confirmButton, SIGNAL (clicked()), this, SLOT (confirmButtonClicked()));
    return confirmButton;
}

void NewGameCreationWindow::closeEvent(QCloseEvent* closeEvent)
{
    closeEvent->ignore();
}
