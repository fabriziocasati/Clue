#include "window.h"
#include <QPushButton>
#include <QHBoxLayout>

Window::Window(QWidget *parent) :
    QWidget(parent) {
// Set size of the window
    setFixedSize(500, 250);
    //this->setSizePolicy(f);

// Create and position the button
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 80, 30);

// Create and position the button
    m_button2 = new QPushButton("Ciao", this);
    m_button2->setGeometry(30, 30, 80, 30);


        QPushButton *button1 = new QPushButton("1");
        QPushButton *button2 = new QPushButton("2");
        QPushButton *button3 = new QPushButton("Three");
        QPushButton *button4 = new QPushButton("Four");
        QPushButton *button5 = new QPushButton("Five");

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4);
        layout->addWidget(button5);

        this->setLayout(layout);



}

