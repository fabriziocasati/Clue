#include "mysubwindow.h"

MySubWindow::MySubWindow( QWidget *parent)
    : QWidget(parent)
{
    QPushButton *b = new QPushButton("Ciao", this);
}

