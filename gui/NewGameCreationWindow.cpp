#include "NewGameCreationWindow.h"

NewGameCreationWindow::NewGameCreationWindow(QWidget* parent) : QDialog(parent)
{
    setModal(true);
}

void NewGameCreationWindow::closeEvent(QCloseEvent* closeEvent)
{
    closeEvent->ignore();
}
