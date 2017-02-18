#include "CardTableWindow.h"
#include <QDebug>
#include <QHeaderView>
#include <QtGui>
#include <boost/lexical_cast.hpp>

#define ROW_SIZE 25
#define COLUMN_SIZE 110

CardTableWindow::CardTableWindow(Game* game, QWidget* parent)
    : QDialog(parent)
{
    /* Store constructor arguments */
    this->game = game;

    /* Get lists */
    playerList      = game->getPlayerList();
    roomCardList    = game->getRoomCardList();
    suspectCardList = game->getSuspectCardList();
    weaponCardList  = game->getWeaponCardList();

    std::vector<QString>::iterator it = roomCardList.begin();
    for(int i = 0; it != roomCardList.end(); ++it, i++)
        roomCardHash[*it] = i;

    it = suspectCardList.begin();
    for(int i = 0; it != suspectCardList.end(); ++it, i++)
        suspectCardHash[*it] = i;

    it = weaponCardList.begin();
    for(int i = 0; it != weaponCardList.end(); ++it, i++)
        weaponCardHash[*it] = i;

    it = playerList.begin();
    for(int i = 0; it != playerList.end(); ++it, i++)
        playerHash[*it] = i;

    /* Create subtables */
    roomCardTable = createCardSubTable(roomCardList);
    suspectCardTable = createCardSubTable(suspectCardList);
    weaponCardTable = createCardSubTable(weaponCardList);

    /* Create window layout and fill it with all the subtables */
    QVBoxLayout* l = new QVBoxLayout;
    l->addWidget(roomCardTable,    0, Qt::AlignCenter);
    l->addWidget(suspectCardTable, 1, Qt::AlignCenter);
    l->addWidget(weaponCardTable,  2, Qt::AlignCenter);

    /* Window settings */
    setWindowTitle(tr("Card Table Window"));
    setLayout(l);
}

QTableWidget* CardTableWindow::createCardSubTable(std::vector<QString> cardList)
{
    /* Create a card subtable */
    cardSubTable = new QTableWidget(this);

    /* Set row and column counts */
    cardSubTable->setRowCount(cardList.capacity());
    cardSubTable->setColumnCount(playerList.capacity());

    /* Create horizontal header and fill it with the players' names */
    QStringList m_TableHeader;
    for (std::vector<QString>::iterator it = cardList.begin(); it != cardList.end(); ++it)
        m_TableHeader.push_back(*it);

    /* Create vertical header and fill it with the card names */
    QStringList m_h;
    for (std::vector<QString>::iterator it = playerList.begin(); it != playerList.end(); ++it)
        m_h.push_back(*it);

    cardSubTable->setHorizontalHeaderLabels(m_h);
    cardSubTable->setVerticalHeaderLabels(m_TableHeader);

    /* Set row size */
    cardSubTable->horizontalHeader()->setMinimumHeight(ROW_SIZE);
    cardSubTable->horizontalHeader()->setMaximumHeight(ROW_SIZE);
    cardSubTable->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    cardSubTable->setHorizontalHeaderLabels(m_h);
    for(int i = 0; i < cardSubTable->rowCount(); i++)
        cardSubTable->setRowHeight(i, ROW_SIZE);

    /* Set column size */
    for(int i = 0; i < cardSubTable->columnCount(); i++)
        cardSubTable->setColumnWidth(i, COLUMN_SIZE);
    cardSubTable->verticalHeader()->setMinimumWidth(COLUMN_SIZE);
    cardSubTable->verticalHeader()->setMaximumWidth(COLUMN_SIZE);
    cardSubTable->verticalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    cardSubTable->setVerticalHeaderLabels(m_TableHeader);

    /* Set table size */
    cardSubTable->setFixedSize(COLUMN_SIZE * (cardSubTable->columnCount()) +
                               (cardSubTable->verticalHeader()->width()) + 2,
                               ROW_SIZE * (cardSubTable->rowCount()) +
                               (cardSubTable->horizontalHeader()->height()) + 2);

    /* Other table settings */
    cardSubTable->setSelectionBehavior(QAbstractItemView::SelectItems);
    cardSubTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    cardSubTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    cardSubTable->setSizeAdjustPolicy(QTableWidget::AdjustToContents);

    return cardSubTable;
}

/*
void CardTableWindow::myupdate()
{

 *     std::string numberString = boost::lexical_cast<std::string>(game->inquiryList->front()->i) ;
 *     QString numberQString = QString::fromStdString(numberString);
 *
 *     inquiryHistoryTable->setItem(0, 0, new QTableWidgetItem("Hello"));
 *     //inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem("Hello"));
 *     inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem(numberQString));
 *
}
*/

void CardTableWindow::updateCardTable(QString card, QString player, QString value)
{

    QTableWidgetItem *q = new QTableWidgetItem(value);
    if(value.compare("Yes") == 0)
        q->setTextColor(QColor(Qt::green));
    else
        q->setTextColor(QColor(Qt::red));
    q->setTextAlignment(Qt::AlignCenter);

    if(roomCardHash.contains(card))
        roomCardTable->setItem(roomCardHash[card], playerHash[player], q);
    else if(suspectCardHash.contains(card))
        suspectCardTable->setItem(suspectCardHash[card], playerHash[player], q);
    else
        weaponCardTable->setItem(weaponCardHash[card], playerHash[player], q);
}

void CardTableWindow::closeEvent(QCloseEvent* e)
{
    e->ignore();
    hide();
}

/*
void CardTableWindow::myupdate2()
{
    QTableWidgetItem* q = new QTableWidgetItem("Yes");
    q->setBackground(QBrush(QColor(Qt::blue)));
    q->setTextColor(QColor(Qt::red));
    q->setTextAlignment(Qt::AlignCenter);
    cardSubTable->setItem(0, 0, q);
}
*/
