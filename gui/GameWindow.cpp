#include "GameWindow.h"
#include <QHeaderView>
#include <boost/lexical_cast.hpp>


GameWindow::GameWindow(Game *game, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Group Boxes"));

    this->game = game;

    QHBoxLayout *l = new QHBoxLayout;

    m_button2 = new QPushButton("Show Query History", this);
    m_button2->setGeometry(600, 50, 150, 30);
    connect(m_button2, SIGNAL (clicked()), this, SLOT (test()));

    QPushButton *m_button3 = new QPushButton("Insert New Query", this);
    m_button3->setGeometry(600, 90, 150, 30);
    connect(m_button3, SIGNAL (clicked()), this, SLOT (openQueryListWindow()));

    label = new QLabel("Test");
    label->setGeometry(10, 10, 150, 30);

    cardTable = new QTableWidget(this);

    cardTable->setRowCount(5);
    cardTable->setColumnCount(5);
    QStringList m_TableHeader;
    m_TableHeader<<"Card"<<"Envelop"<<"Player 1"<<"Player 2"<<"Player 3";
    cardTable->setHorizontalHeaderLabels(m_TableHeader);
    cardTable->setVerticalHeaderLabels(m_TableHeader);
    //cardTable->verticalHeader()->setVisible(false);
    //cardTable->verticalScrollBar()->setEnabled(true);
    cardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    cardTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    cardTable->setSelectionMode(QAbstractItemView::SingleSelection);
    //cardTable->setShowGrid(false);
    //cardTable->setStyleSheet("QTableView {selection-background-color: red; color: yellow; background: blue; border: 1px solid white}");
    //cardTable->resize(1550,1250);
    cardTable->setFixedSize(800,600);

    l->addWidget(cardTable);
    l->addWidget(m_button3);
    l->addWidget(m_button2);
    setLayout(l);

    resize(800,400);

}

void GameWindow::openQueryListWindow() {
    NewInquiryWindow *w = new NewInquiryWindow(game, this);
    w->show();
}

void GameWindow::test() {
    InquiryHistoryWindow *h = new InquiryHistoryWindow(game);
    h->show();
}

void GameWindow::myupdate() {
/*
    std::string numberString = boost::lexical_cast<std::string>(game->inquiryList->front()->i) ;
    QString numberQString = QString::fromStdString(numberString);

    inquiryHistoryTable->setItem(0, 0, new QTableWidgetItem("Hello"));
    //inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem("Hello"));
    inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem(numberQString));
*/
}

