#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Create and position the button
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 80, 30);

    connect(m_button, SIGNAL (clicked()), this, SLOT (openNewWindow()));

}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::openNewWindow()
{
   window = new Window(); // Be sure to destroy you window somewhere
   window->show();
   this->hide();
   //this->setDisabled(true);
   // ...
}
