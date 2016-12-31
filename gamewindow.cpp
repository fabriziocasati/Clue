#include "gamewindow.h"
#include <boost/lexical_cast.hpp>

GameWindow::GameWindow(Game *game, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Group Boxes"));

    this->game = game;


    m_button2 = new QPushButton("Show Query History", this);
    m_button2->setGeometry(10, 50, 150, 30);
    connect(m_button2, SIGNAL (clicked()), this, SLOT (openQueryListWindow()));


    QPushButton *m_button3 = new QPushButton("Insert New Query", this);
    m_button3->setGeometry(10, 90, 150, 30);
    connect(m_button3, SIGNAL (clicked()), this, SLOT (openQueryListWindow()));

    label = new QLabel("Test");
    label->setGeometry(10, 10, 150, 30);

}

void GameWindow::openQueryListWindow() {
    NewInquiryWindow *w = new NewInquiryWindow(game, this);
    w->show();
}

void GameWindow::myupdate() {

    std::string numberString = boost::lexical_cast<std::string>(game->inquiryList->front()->i) ;
    QString numberQString = QString::fromStdString(numberString);


    m_button2->setText(numberQString);
}

