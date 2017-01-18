#include "GameWindow.h"
#include <QHeaderView>
#include <boost/lexical_cast.hpp>
#include <QDebug>
#include <QtGui>


GameWindow::GameWindow(Game *game, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Group Boxes"));


    roomCard.push_back(QString("Kitchen"));
    roomCard.push_back(QString("Ballroom"));
    roomCard.push_back(QString("Conservatory"));
    roomCard.push_back(QString("Dining Room"));
    roomCard.push_back(QString("Billiard Room"));
    roomCard.push_back(QString("Library"));
    roomCard.push_back(QString("Lounge"));
    roomCard.push_back(QString("Hall"));
    roomCard.push_back(QString("Study"));

    std::vector<QString> names2 = roomCard;

    this->game = game;

    QVBoxLayout *l = new QVBoxLayout;

    m_button2 = new QPushButton("Show Query History", this);
    m_button2->setGeometry(600, 50, 150, 30);
    connect(m_button2, SIGNAL (clicked()), this, SLOT (test()));

    QPushButton *m_button3 = new QPushButton("Insert New Query", this);
    m_button3->setGeometry(600, 90, 150, 30);
    connect(m_button3, SIGNAL (clicked()), this, SLOT (openQueryListWindow()));

    label = new QLabel("Test");
    label->setGeometry(10, 10, 150, 30);

    cardTable = new QTableWidget(this);

    cardTable->setRowCount(9);
    cardTable->setColumnCount(5);
    QStringList m_TableHeader;
    //m_TableHeader<<"Card"<<"Envelop"<<"Player 1"<<"Player 2"<<"Player 3";
    //m_TableHeader.push_back("Ciao");
    //m_TableHeader<<"Player 4";
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
    QTableWidgetItem *q = new QTableWidgetItem("Yes");
    //i->setBackground(QBrush(QColor(Qt::blue)));
    //i->setTextColor(QColor(Qt::red));
    q->setBackground(QBrush(QColor(Qt::green)));
    //q->setTextColor(QColor(Qt::green));
    q->setTextAlignment(Qt::AlignCenter);
    cardTable->setItem(0, 0, q);
    //cardTable->setFixedSize(400,300);
    //setFixedSize(cardTable->horizontalHeader()->length() + 600, cardTable->verticalHeader()->length() + 100);

    int vwidth = cardTable->verticalHeader()->width();
    int hwidth = cardTable->horizontalHeader()->length();
    //int swidth = cardTable->style()->pixelMetric(QtGui::QStyle::PM_ScrollBarExtent);
    int swidth = 0;
    int fwidth = cardTable->frameWidth() * 2;

    cardTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    cardTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //cardTable->setFixedWidth(vwidth + hwidth + swidth + fwidth);
    cardTable->setSizeAdjustPolicy(QTableWidget::AdjustToContents);



    q = new QTableWidgetItem("Yes");
    q->setTextColor(QColor(Qt::green));
    q->setTextAlignment(Qt::AlignCenter);
    cardTable->setItem(0, 1, q);
    q = new QTableWidgetItem("No");
    q->setBackground(QBrush(QColor(Qt::red)));
    q->setTextAlignment(Qt::AlignCenter);
    cardTable->setItem(1, 0, q);

    QTableWidget *suspectCardTable = new QTableWidget(this);
    QStringList m_TableHeader2;
    suspectCardTable->setRowCount(30);
    suspectCardTable->setColumnCount(5);
    //m_TableHeader<<"Card"<<"Envelop"<<"Player 1"<<"Player 2"<<"Player 3";
    //m_TableHeader.push_back("Ciao");
    //m_TableHeader<<"Player 4";
    for (std::vector<QString>::iterator it = names2.begin() ; it != names2.end(); ++it) {
        m_TableHeader2.push_back(*it);
    }
    for(int i=0; i<10; i++)
        m_TableHeader2.push_back("Ciao");


    suspectCardTable->setHorizontalHeaderLabels(m_TableHeader2);
    suspectCardTable->setVerticalHeaderLabels(m_TableHeader2);

    int h=25;
    //suspectCardTable->verticalHeader()->setMaximumHeight(h);
    //suspectCardTable->verticalHeader()->setMinimumHeight(h);
    //suspectCardTable->horizontalHeader()->setMinimumHeight(h);
    for(int i=0; i<suspectCardTable->rowCount(); i++)
       suspectCardTable->setRowHeight(i, h);

    //suspectCardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //suspectCardTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    //suspectCardTable->setSelectionMode(QAbstractItemView::SingleSelection);


    suspectCardTable->setFixedSize(800,h*(suspectCardTable->rowCount())+(suspectCardTable->horizontalHeader()->height())+2);


    suspectCardTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //suspectCardTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //cardTable->setFixedWidth(vwidth + hwidth + swidth + fwidth);
    //suspectCardTable->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    qDebug() << suspectCardTable->verticalHeader()->height();

    //suspectCardTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //suspectCardTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    //suspectCardTable->setMinimumHeight((suspectCardTable->verticalHeader()->height()));

    /*
    suspectCardTable->resizeRowsToContents();
    suspectCardTable->resizeColumnsToContents();
    QAbstractItemModel* model = suspectCardTable->model();
    QHeaderView* horHeader = suspectCardTable->horizontalHeader();
    QHeaderView* verHeader = suspectCardTable->verticalHeader();
    int rows = model->rowCount();
    int cols = model->columnCount();
    int x = horHeader->sectionViewportPosition(cols-1) + horHeader->offset()
            + horHeader->sectionSize(cols-1) + 1;
    int y = verHeader->sectionViewportPosition(rows-1) + verHeader->offset()
            + verHeader->sectionSize(rows-1) + 1;
    QPoint p = suspectCardTable->viewport()->mapToParent(QPoint(x,y));
    QRect g = suspectCardTable->geometry();
    g.setSize(QSize(p.x(),p.y()));
    suspectCardTable->setGeometry(g);
    */
/*

    suspectCardTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    suspectCardTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QRect rect = suspectCardTable->geometry();
    int width = 2,length = 2;
    for(int col = 0;col<proxySortModel->columnCount();++col){
        if(!suspectCardTable->isColumnHidden(col))
            width += suspectCardTable->columnWidth(col);
    }
    for(int row =0;row<proxySortModel->rowCount();++row)
        length += suspectCardTable->rowHeight(row);
    rect.setWidth(width);
    rect.setHeight(length);
    suspectCardTable->setGeometry(rect);
*/


    l->addWidget(cardTable, 0, Qt::AlignCenter);
    l->addWidget(suspectCardTable, 1, Qt::AlignCenter);
    l->addWidget(m_button3, 2, Qt::AlignCenter);
    l->addWidget(m_button2, 3, Qt::AlignCenter);

    setLayout(l);

    //setFixedSize(800,1000);

    std::vector<QString>::iterator it;
    /*
    it = names2.begin();
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
    }
    */

    q = new QTableWidgetItem("?");
    q->setTextAlignment(Qt::AlignCenter);
    cardTable->setItem(5, 4, q);
    q = new QTableWidgetItem("?");
    q->setBackground(QBrush(QColor(Qt::yellow)));
    q->setTextAlignment(Qt::AlignCenter);
    cardTable->setItem(2, 0, q);


    /*
    std::vector<QString> userCards = game->getUserCards();
    it = userCards.begin();
    std::vector<QString>::iterator it2 = names2.begin();
    QString s = *it;
    int ok;
    for(int i=0; i < 20-7 && it2 != names2.end(); ++it2, i++) {
        ok = 0;
        for(it = userCards.begin(); !ok && it != userCards.end(); ++it)
            if((*it).compare(*it2) == 0)
                ok = 1;
        if(ok) {
            q = new QTableWidgetItem("Yes");
            q->setTextColor(QColor(Qt::green));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i+7, 3, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i+7, 0, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i+7, 1, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i+7, 2, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i+7, 4, q);
        } else {
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i+7, 3, q);
        }
        }

        */

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

void GameWindow::updateCardTable(QString card, QString player, QString value) {
    std::vector<QString> userCards = game->getUserCards();
    std::vector<QString>::iterator it = roomCard.begin();
    int ok = 0;
    int i=0;
    while(!ok && it != roomCard.end())
        if((*it).compare(card) == 0)
            ok=1;
        else {
            ++it, i++;
        }

    qDebug() << i;

    std::vector<QString>::iterator it2;
    QTableWidgetItem *q;
        for(it = roomCard.begin(); !ok && it != roomCard.end(); ++it)
            if((*it).compare(*it2) == 0)
                ok = 1;
        if(value.compare("Yes") == 0) {
            q = new QTableWidgetItem("Yes");
            q->setTextColor(QColor(Qt::green));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i, 3, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i, 0, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i, 1, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i, 2, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i, 4, q);
        } else {
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            cardTable->setItem(i, 3, q);
        }
}
