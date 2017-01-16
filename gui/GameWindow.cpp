#include "GameWindow.h"
#include <QHeaderView>
#include <boost/lexical_cast.hpp>


GameWindow::GameWindow(Game *game, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Group Boxes"));

    std::vector<QString> names2;
    names2.push_back(QString("Stanza"));
    names2.push_back(QString("Carta"));
    names2.push_back(QString("Esempio"));
    names2.push_back(QString("Qualcosa"));
    names2.push_back(QString("Arma"));
    names2.push_back(QString("Sospetto"));

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

    cardTable->setRowCount(15);
    cardTable->setColumnCount(5);
    QStringList m_TableHeader;
    m_TableHeader<<"Card"<<"Envelop"<<"Player 1"<<"Player 2"<<"Player 3";
    m_TableHeader.push_back("Ciao");
    m_TableHeader<<"Player 4";
    for (std::vector<QString>::iterator it = names2.begin() ; it != names2.end(); ++it) {
        m_TableHeader.push_back(*it);
    }


    cardTable->setHorizontalHeaderLabels(m_TableHeader);
    //cardTable->verticalHeader()->setSizeAdjustPolicy(QHeaderView::Fixed);
    //cardTable->verticalHeader()->resizeSection( 0, 200 );
    //cardTable->horizontalHeader()->setDefaultSectionSize(50);
    cardTable->setVerticalHeaderLabels(m_TableHeader);
    //cardTable->verticalHeader()->setVisible(false);
    //cardTable->verticalScrollBar()->setEnabled(true);
    cardTable->verticalHeader()->setMinimumWidth(50);
    cardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    cardTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    cardTable->setSelectionMode(QAbstractItemView::SingleSelection);
    //cardTable->setShowGrid(false);
    //cardTable->setStyleSheet("QTableView {selection-background-color: red; color: yellow; background: blue; border: 1px solid white}");
    QTableWidgetItem *q = new QTableWidgetItem("Hello");
    //i->setBackground(QBrush(QColor(Qt::blue)));
    //i->setTextColor(QColor(Qt::red));
    q->setBackground(QBrush(QColor(Qt::green)));
    //q->setTextColor(QColor(Qt::green));
    q->setTextAlignment(Qt::AlignCenter);
    cardTable->setItem(0, 0, q);
    cardTable->setFixedSize(800,600);
    q = new QTableWidgetItem("Hello");
    q->setTextColor(QColor(Qt::green));
    q->setTextAlignment(Qt::AlignCenter);
    cardTable->setItem(0, 1, q);
    q = new QTableWidgetItem("Hello");
    q->setBackground(QBrush(QColor(Qt::red)));
    q->setTextAlignment(Qt::AlignCenter);
    cardTable->setItem(1, 0, q);


    l->addWidget(cardTable);
    l->addWidget(m_button3);
    l->addWidget(m_button2);
    setLayout(l);

    resize(800,400);

    std::vector<QString>::iterator it = names2.begin();
    for(int i=0; i<15; i++) {
        if(QString("Arma").compare(*it) == 0) {
            q = new QTableWidgetItem("Hello");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i, 2, q);
        } else {
            q = new QTableWidgetItem("Hello");
            q->setTextColor(QColor(Qt::green));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i, 2, q);
            ++it;
        }
        //
    }
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

