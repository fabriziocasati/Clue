#include "mainwindow.h"
#include "numberofplayers.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {

    // Create and position the button
    m_button = new QPushButton("Create New Game", this);
    m_button->setGeometry(10, 10, 150, 30);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNewWindow()));

    QPushButton *m_button2 = new QPushButton("Show Query History", this);
    m_button2->setGeometry(10, 50, 150, 30);
    connect(m_button2, SIGNAL (clicked()), this, SLOT (openQueryListWindow()));

    QPushButton *m_button3 = new QPushButton("Insert New Query", this);
    m_button3->setGeometry(10, 90, 150, 30);
    connect(m_button3, SIGNAL (clicked()), this, SLOT (openQueryListWindow()));


    window2 = new Window2();
    //window2->show();

    resize(500,300);




}

void MainWindow::openNewWindow() {
    window = new Window(); // Be sure to destroy you window somewhere
    //window->show();

    window2 = new Window2();
    //window2->show();

    NumberOfPlayers *numberOfPlayersWindow = new NumberOfPlayers();
    numberOfPlayersWindow->show();

    this->hide();
    //this->setDisabled(true);
    // ...
}


void MainWindow::openQueryListWindow() {

}

