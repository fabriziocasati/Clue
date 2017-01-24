#include "NewGameCreationWindow.h"

#include <QtWidgets> // required by QCloseEvent

NewGameCreationWindow::NewGameCreationWindow(QWidget* parent) : QDialog(parent)
{
    setModal(true);
}

void NewGameCreationWindow::closeEvent(QCloseEvent* closeEvent)
{
    closeEvent->ignore();
}
