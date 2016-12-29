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

    QWidget *window = new QWidget;
        QPushButton *button1 = new QPushButton("One");
        QPushButton *button2 = new QPushButton("Two");
        QPushButton *button3 = new QPushButton("Three");
        QPushButton *button4 = new QPushButton("Four");
        QPushButton *button5 = new QPushButton("Five");

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4);
        layout->addWidget(button5);

        window->setLayout(layout);
        window->show();


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
