#include "GameWindow.h"
#include <QHeaderView>
#include <boost/lexical_cast.hpp>
#include <QDebug>
#include <QtGui>


GameWindow::GameWindow(Game *game, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Group Boxes"));

    this->game = game;
    roomCardList = game->getRoomCardList();
    suspectCardList = game->getSuspectCardList();
    weaponCardList = game->getWeaponCardList();
    playerList = game->getPlayerList();


    QVBoxLayout *l = new QVBoxLayout;

    roomCardTable = new QTableWidget(this);

    roomCardTable->setRowCount(roomCardList.capacity());
    roomCardTable->setColumnCount(playerList.capacity());
    QStringList m_TableHeader;
    for (std::vector<QString>::iterator it = roomCardList.begin() ; it != roomCardList.end(); ++it) {
        m_TableHeader.push_back(*it);
    }
    QStringList m_h;
    for (std::vector<QString>::iterator it = playerList.begin() ; it != playerList.end(); ++it) {
        m_h.push_back(*it);
    }

    roomCardTable->setHorizontalHeaderLabels(m_h);
    roomCardTable->setVerticalHeaderLabels(m_TableHeader);

    int h=25;
    roomCardTable->horizontalHeader()->setMinimumHeight(h);
    roomCardTable->horizontalHeader()->setMaximumHeight(h);
    for(int i=0; i<roomCardTable->rowCount(); i++)
       roomCardTable->setRowHeight(i, h);

    int k=110;
    roomCardTable->verticalHeader()->setMinimumWidth(k);
    roomCardTable->verticalHeader()->setMaximumWidth(k);
    for(int i=0; i<roomCardTable->columnCount(); i++)
       roomCardTable->setColumnWidth(i, k);

    roomCardTable->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    roomCardTable->verticalHeader()->setSectionResizeMode (QHeaderView::Fixed);

    //suspectCardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //suspectCardTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    //suspectCardTable->setSelectionMode(QAbstractItemView::SingleSelection);

    roomCardTable->setHorizontalHeaderLabels(m_h);
    roomCardTable->setVerticalHeaderLabels(m_TableHeader);


    roomCardTable->setFixedSize(k*(roomCardTable->columnCount())+(roomCardTable->verticalHeader()->width())+2,
                h*(roomCardTable->rowCount())+(roomCardTable->horizontalHeader()->height())+2);


    roomCardTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //cardTable->verticalHeader()->setSizeAdjustPolicy(QHeaderView::Fixed);
    //cardTable->verticalHeader()->resizeSection( 0, 200 );
    //cardTable->horizontalHeader()->setDefaultSectionSize(50);

    //cardTable->verticalHeader()->setVisible(false);
    //cardTable->verticalScrollBar()->setEnabled(true);
    //roomCardTable->verticalHeader()->setMinimumWidth(50);
    //roomCardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    roomCardTable->setSelectionBehavior(QAbstractItemView::SelectItems);
    //roomCardTable->setSelectionMode(QAbstractItemView::NoSelection);
    //cardTable->setShowGrid(false);
    //cardTable->setStyleSheet("QTableView {selection-background-color: red; color: yellow; background: blue; border: 1px solid white}");
    QTableWidgetItem *q = new QTableWidgetItem("Yes");
    //i->setBackground(QBrush(QColor(Qt::blue)));
    //i->setTextColor(QColor(Qt::red));
    q->setBackground(QBrush(QColor(Qt::green)));
    //q->setTextColor(QColor(Qt::green));
    q->setTextAlignment(Qt::AlignCenter);
    //roomCardTable->setItem(0, 0, q);
    //cardTable->setFixedSize(400,300);
    //setFixedSize(cardTable->horizontalHeader()->length() + 600, cardTable->verticalHeader()->length() + 100);

    //int vwidth = roomCardTable->verticalHeader()->width();
    //int hwidth = roomCardTable->horizontalHeader()->length();
    //int swidth = cardTable->style()->pixelMetric(QtGui::QStyle::PM_ScrollBarExtent);
    //int swidth = 0;
    //int fwidth = roomCardTable->frameWidth() * 2;

    roomCardTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    roomCardTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //cardTable->setFixedWidth(vwidth + hwidth + swidth + fwidth);
    roomCardTable->setSizeAdjustPolicy(QTableWidget::AdjustToContents);



    q = new QTableWidgetItem("Yes");
    q->setTextColor(QColor(Qt::green));
    q->setTextAlignment(Qt::AlignCenter);
    //roomCardTable->setItem(0, 1, q);
    q = new QTableWidgetItem("No");
    q->setBackground(QBrush(QColor(Qt::red)));
    q->setTextAlignment(Qt::AlignCenter);
    //roomCardTable->setItem(1, 0, q);











    QTableWidget *suspectCardTable = new QTableWidget(this);
    suspectCardTable->setRowCount(suspectCardList.capacity());
    suspectCardTable->setColumnCount(playerList.capacity());
    QStringList m_TableHeader2;
    for (std::vector<QString>::iterator it = suspectCardList.begin() ; it != suspectCardList.end(); ++it) {
        m_TableHeader2.push_back(*it);
    }

    suspectCardTable->setHorizontalHeaderLabels(m_h);
    suspectCardTable->setVerticalHeaderLabels(m_TableHeader2);

    //suspectCardTable->verticalHeader()->setMaximumHeight(h);

    suspectCardTable->horizontalHeader()->setMinimumHeight(h);
    suspectCardTable->horizontalHeader()->setMaximumHeight(h);
    for(int i=0; i<suspectCardTable->rowCount(); i++)
       suspectCardTable->setRowHeight(i, h);

    suspectCardTable->verticalHeader()->setMinimumWidth(k);
    for(int i=0; i<suspectCardTable->columnCount(); i++)
       suspectCardTable->setColumnWidth(i, k);

    suspectCardTable->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    suspectCardTable->verticalHeader()->setSectionResizeMode (QHeaderView::Fixed);

    //suspectCardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //suspectCardTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    //suspectCardTable->setSelectionMode(QAbstractItemView::SingleSelection);


    suspectCardTable->setFixedSize(k*(suspectCardTable->columnCount())+(suspectCardTable->verticalHeader()->width())+2,
                h*(suspectCardTable->rowCount())+(suspectCardTable->horizontalHeader()->height())+2);


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

    suspectCardTable->setStyleSheet("{ border-left: 10px solid black; }");








    QTableWidget *weaponCardTable = new QTableWidget(this);
    QStringList m_TableHeader3;
    weaponCardTable->setRowCount(suspectCardList.capacity());
    weaponCardTable->setColumnCount(playerList.capacity());

    for (std::vector<QString>::iterator it = weaponCardList.begin() ; it != weaponCardList.end(); ++it) {
        m_TableHeader3.push_back(*it);
    }

    weaponCardTable->setHorizontalHeaderLabels(m_h);
    weaponCardTable->setVerticalHeaderLabels(m_TableHeader3);

    //suspectCardTable->verticalHeader()->setMaximumHeight(h);

    weaponCardTable->horizontalHeader()->setMinimumHeight(h);
    weaponCardTable->horizontalHeader()->setMaximumHeight(h);
    for(int i=0; i<weaponCardTable->rowCount(); i++)
       weaponCardTable->setRowHeight(i, h);

    weaponCardTable->verticalHeader()->setMinimumWidth(k);
    for(int i=0; i<weaponCardTable->columnCount(); i++)
       weaponCardTable->setColumnWidth(i, k);

    weaponCardTable->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    weaponCardTable->verticalHeader()->setSectionResizeMode (QHeaderView::Fixed);

    //suspectCardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //suspectCardTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    //suspectCardTable->setSelectionMode(QAbstractItemView::SingleSelection);


    weaponCardTable->setFixedSize(k*(weaponCardTable->columnCount())+(weaponCardTable->verticalHeader()->width())+2,
                h*(weaponCardTable->rowCount())+(weaponCardTable->horizontalHeader()->height())+2);


    weaponCardTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);














    l->addWidget(roomCardTable, 0, Qt::AlignCenter);
    l->addWidget(suspectCardTable, 1, Qt::AlignCenter);
    l->addWidget(weaponCardTable, 1, Qt::AlignCenter);

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
    //roomCardTable->setItem(5, 4, q);
    q = new QTableWidgetItem("?");
    q->setBackground(QBrush(QColor(Qt::yellow)));
    q->setTextAlignment(Qt::AlignCenter);
    //roomCardTable->setItem(2, 0, q);


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
        //roomCardTable->setSelectionModel(QItemSelectionModel::Deselect);

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
    /*
    std::vector<QString> userCards = game->getUserCards();
    std::vector<QString>::iterator it = roomCardList.begin();
    int ok = 0;
    int i=0;
    while(!ok && it != roomCardList.end())
        if((*it).compare(card) == 0)
            ok=1;
        else {
            ++it, i++;
        }

    qDebug() << i;

    std::vector<QString>::iterator it2;
    QTableWidgetItem *q;
        for(it = roomCardList.begin(); !ok && it != roomCardList.end(); ++it)
            if((*it).compare(*it2) == 0)
                ok = 1;
        if(value.compare("Yes") == 0) {
            q = new QTableWidgetItem("Yes");
            q->setTextColor(QColor(Qt::green));
            q->setTextAlignment(Qt::AlignCenter);
            roomCardTable->setItem(i, 3, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            roomCardTable->setItem(i, 0, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            roomCardTable->setItem(i, 1, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            roomCardTable->setItem(i, 2, q);
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            roomCardTable->setItem(i, 4, q);
        } else {
            q = new QTableWidgetItem("No");
            q->setTextColor(QColor(Qt::red));
            q->setTextAlignment(Qt::AlignCenter);
            roomCardTable->setItem(i, 3, q);
        }
        */
}
