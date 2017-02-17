#include "InquiryHistoryWindow.h"
#include <QHeaderView>
#include <QtGui>
#include <boost/lexical_cast.hpp>

#define COLUMN_SIZE 30
#define ROW_SIZE    120

InquiryHistoryWindow::InquiryHistoryWindow(Game* game, QWidget* parent)
    : QDialog(parent)
{
    /* Store construct arguments */
    this->game = game;

    /* Create table */
    inquiryHistoryTable = new QTableWidget(this);

    QGridLayout* l = new QGridLayout;

    inquiryHistoryTable->setRowCount(0);
    inquiryHistoryTable->setColumnCount(5);

    QStringList m_TableHeader;
    m_TableHeader << "Inquirer" << "Room" << "Suspect" << "Weapon" << "Giver";
    inquiryHistoryTable->setHorizontalHeaderLabels(m_TableHeader);

    inquiryHistoryTable->horizontalHeader()->setMinimumHeight(COLUMN_SIZE);
    inquiryHistoryTable->horizontalHeader()->setMaximumHeight(COLUMN_SIZE);

    inquiryHistoryTable->verticalHeader()->setMinimumWidth(COLUMN_SIZE);
    for(int i = 0; i < inquiryHistoryTable->columnCount(); i++)
        inquiryHistoryTable->setColumnWidth(i, ROW_SIZE);

    inquiryHistoryTable->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    inquiryHistoryTable->verticalHeader()->setSectionResizeMode (QHeaderView::Fixed);

    inquiryHistoryTable->setFixedSize(ROW_SIZE * (inquiryHistoryTable->columnCount()) +
                                      (inquiryHistoryTable->verticalHeader()->width()) + 2,
                                      500);

    l->addWidget(inquiryHistoryTable);

    inquiryHistoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    inquiryHistoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    inquiryHistoryTable->setSelectionMode(QAbstractItemView::SingleSelection);

    setLayout(l);
}

void InquiryHistoryWindow::myupdate()
{
    if(!(game->inquiryList->empty()))
    {
        inquiryHistoryTable->setRowCount(inquiryHistoryTable->rowCount() + 1);
        std::list<Inquiry*>::iterator it = game->inquiryList->begin();
        int index = 0;
        for (; it != game->inquiryList->end(); index++, ++it)
        {
            inquiryHistoryTable->setItem(index, 0,
                                         new QTableWidgetItem(QString::fromStdString((*
                                                                                      it)
                                                                                     ->
                        inquirer)));
            inquiryHistoryTable->setItem(index, 1,
                                         new QTableWidgetItem(QString::fromStdString((*
                                                                                      it)
                                                                                     ->
                        room)));
            inquiryHistoryTable->setItem(index, 2,
                                         new QTableWidgetItem(QString::fromStdString((*
                                                                                      it)
                                                                                     ->
                        suspect)));
            inquiryHistoryTable->setItem(index, 3,
                                         new QTableWidgetItem(QString::fromStdString((*
                                                                                      it)
                                                                                     ->
                        weapon)));
            inquiryHistoryTable->setItem(index, 4,
                                         new QTableWidgetItem(QString::fromStdString((*
                                                                                      it)
                                                                                     ->
                        giver)));
        }
    }
}

void InquiryHistoryWindow::closeEvent(QCloseEvent* e)
{
    e->ignore();
    hide();
}
