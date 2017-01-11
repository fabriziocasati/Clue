#include "InquiryHistoryWindow.h"
#include <boost/lexical_cast.hpp>
#include <QHeaderView>

InquiryHistoryWindow::InquiryHistoryWindow(Game *g, QWidget *parent)
    : QWidget(parent)
{

    this->g = g;

    inquiryHistoryTable = new QTableWidget(this);

    inquiryHistoryTable->setRowCount(g->inquiryList->size());
    inquiryHistoryTable->setColumnCount(6);
    //inquiryHistoryTable->horizontalHeaderItem(0)->setText("Whatever");
    QStringList m_TableHeader;
    m_TableHeader<<"Turn"<<"Inquirer"<<"Room"<<"Suspect"<<"Weapon"<<"Giver";
    inquiryHistoryTable->setHorizontalHeaderLabels(m_TableHeader);
    //inquiryHistoryTable->verticalHeader()->setVisible(false);
    //inquiryHistoryTable->verticalScrollBar()->setEnabled(true);
    inquiryHistoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    inquiryHistoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    inquiryHistoryTable->setSelectionMode(QAbstractItemView::SingleSelection);
    //inquiryHistoryTable->setShowGrid(false);
    //inquiryHistoryTable->setStyleSheet("QTableView {selection-background-color: red; color: yellow; background: blue; border: 1px solid white}");
    inquiryHistoryTable->resize(700,400);

    resize(750,400);


    if(!(g->inquiryList->empty())) {

        std::string numberString = boost::lexical_cast<std::string>(g->inquiryList->front()->turn) ;
        QString numberQString = QString::fromStdString(numberString);

        inquiryHistoryTable->setItem(0, 0, new QTableWidgetItem("Hello"));
        //inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem("Hello"));
        inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem(numberQString));


        std::list<Inquiry*>::iterator it=g->inquiryList->begin();
        int index=0;
        for (; it != g->inquiryList->end(); index++, ++it) {
            std::string numberString = boost::lexical_cast<std::string>((*it)->turn) ;
            QString numberQString = QString::fromStdString(numberString);

            inquiryHistoryTable->setItem(index, 0, new QTableWidgetItem(numberQString));

            numberString = boost::lexical_cast<std::string>((*it)->inquirer) ;
            numberQString = QString::fromStdString(numberString);
            inquiryHistoryTable->setItem(index, 1, new QTableWidgetItem(numberQString));
        }
    }


    // constructors used in the same order as described above:
      std::list<int> first;                                // empty list of ints
      std::list<int> second (4,100);                       // four ints with value 100
      std::list<int> third (second.begin(),second.end());  // iterating through second
      std::list<int> fourth (third);                       // a copy of third

      // the iterator constructor can also be used to construct from arrays:
      int myints[] = {16,2,77,29};
      std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

      std::cout << "The contents of fifth are: ";
      for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << *it << ' ';

      std::cout << '\n';
}

