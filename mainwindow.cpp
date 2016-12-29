#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {

    // Create and position the button
    m_button = new QPushButton("Create New Game", this);
    m_button->setGeometry(10, 10, 150, 30);

    connect(m_button, SIGNAL (clicked()), this, SLOT (openNewWindow()));

    window2 = new Window2();
    window2->show();




}

void MainWindow::openNewWindow() {
    window = new Window(); // Be sure to destroy you window somewhere
    window->show();

    window2 = new Window2();
    window2->show();

    this->hide();
    //this->setDisabled(true);
    // ...
}

