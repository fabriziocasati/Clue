#include "gamewindow.h"
#include <boost/lexical_cast.hpp>

GameWindow::GameWindow(Game *game, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Group Boxes"));

    this->game = game;


    m_button2 = new QPushButton("Show Query History", this);
    m_button2->setGeometry(400, 50, 150, 30);
    connect(m_button2, SIGNAL (clicked()), this, SLOT (openQueryListWindow()));


    QPushButton *m_button3 = new QPushButton("Insert New Query", this);
    m_button3->setGeometry(400, 90, 150, 30);
    connect(m_button3, SIGNAL (clicked()), this, SLOT (openQueryListWindow()));

    label = new QLabel("Test");
    label->setGeometry(10, 10, 150, 30);

    inquiryHistoryTable = new QTableWidget(this);

    inquiryHistoryTable->setRowCount(100);
    inquiryHistoryTable->setColumnCount(3);
    //inquiryHistoryTable<<"#"<<"Name"<<"Text";
    //inquiryHistoryTable->setHorizontalHeaderLabels(m_TableHeader);
    //inquiryHistoryTable->verticalHeader()->setVisible(false);
    //inquiryHistoryTable->verticalScrollBar()->setEnabled(true);
    inquiryHistoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    inquiryHistoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    inquiryHistoryTable->setSelectionMode(QAbstractItemView::SingleSelection);
    //inquiryHistoryTable->setShowGrid(false);
    //inquiryHistoryTable->setStyleSheet("QTableView {selection-background-color: red; color: yellow; background: blue; border: 1px solid white}");
    inquiryHistoryTable->resize(400,200);

    resize(600,300);

}

void GameWindow::openQueryListWindow() {
    NewInquiryWindow *w = new NewInquiryWindow(game, this);
    w->show();
}

void GameWindow::myupdate() {

    std::string numberString = boost::lexical_cast<std::string>(game->inquiryList->front()->i) ;
    QString numberQString = QString::fromStdString(numberString);

    inquiryHistoryTable->setItem(0, 0, new QTableWidgetItem("Hello"));
    //inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem("Hello"));
    inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem(numberQString));

}

