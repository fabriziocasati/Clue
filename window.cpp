#include "window.h"
#include <QPushButton>

Window::Window(QWidget *parent) :
    QWidget(parent) {
// Set size of the window
    setFixedSize(100, 50);

// Create and position the button
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 80, 30);

// Create and position the button
    m_button2 = new QPushButton("Ciao", this);
    m_button2->setGeometry(30, 30, 80, 30);


}

