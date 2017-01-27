#include "MainWindow.h"
#include "gui/NumberOfPlayersWindow.h"
#include "gui/NewInquiryWindow.h"
#include "gui/NamesOfThePlayersWindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QAction>
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include "game/Game.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    area = new QMdiArea;
    setCentralWidget(area);
    createMenus();

    setWindowTitle(tr("Clue Solver"));


    /*
    m_pPalette	= new QPalette();
    m_pPixmap		= new QPixmap("img2.jpg");

    m_pPalette->setBrush(QPalette::Background,QBrush(*m_pPixmap));
    setPalette(*m_pPalette);

    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout();
    centralWidget->setLayout(layout);


    /*
    QPixmap bkgnd("/home/fabrizio/qt_workspace/Clue_Solver/img.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

    QWidget *pic = new QWidget(this);
    pic->setStyleSheet("background-image: url(/home/fabrizio/qt_workspace/Clue_Solver/img.jpg)");
    pic->setGeometry(QRect(0,0,this->maximumWidth(),this->maximumHeight()));
    */

    std::vector<QString> names;
    names.push_back(QString("Fabrizio"));
    names.push_back(QString("Cristina"));
    names.push_back(QString("Grigina"));
    names.push_back(QString("Nerone"));

    std::vector<int> num;
    num.push_back(5);
    num.push_back(5);
    num.push_back(5);
    num.push_back(5);

    std::vector<QString> names2;
    names2.push_back(QString("Kitchen"));
    names2.push_back(QString("Lounge"));
    names2.push_back(QString("Library"));

    game = new Game(this, 4, names, num, names2);
    g = new GameWindow(game, this);
    i = new InquiryHistoryWindow(game, this);
    n = new NewInquiryWindow(game, i, this);
    /*
    setSubwindow(g);
    setSubwindow(n);
    setSubwindow(i);
    */

}

void MainWindow::resizeEvent (QResizeEvent* event)
  {
    /*
    m_pPalette->setBrush(QPalette::Background,QBrush(m_pPixmap->scaled(width(),height())));
      setPalette(*m_pPalette);
      */
  };

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Game"));
    QAction *newGameAction = new QAction(tr("&New Game"), this);
    fileMenu->addAction(newGameAction);
    connect(newGameAction, &QAction::triggered, this, &MainWindow::createNewGame);

    windowMenu = menuBar()->addMenu(tr("&Window"));
    QAction *showCardTableWindowAction = new QAction(tr("Show &Card Table Window"), this);
    windowMenu->addAction(showCardTableWindowAction);
    //showCardTableWindowAction->setCheckable(true);
    connect(showCardTableWindowAction, &QAction::triggered, this, &MainWindow::showCardTableWindow);

    QAction *showNewInquiryInsertionWindowAction = new QAction(tr("Show &New Inquiry Insertion Window"), this);
    windowMenu->addAction(showNewInquiryInsertionWindowAction);
    //showNewInquiryInsertionWindowAction->setCheckable(true);
    connect(showNewInquiryInsertionWindowAction, &QAction::triggered, this, &MainWindow::showNewInquiryInsertionWindow);

    QAction *showInquiryHistoryWindowAction = new QAction(tr("Show &Inquiry History Window"), this);
    windowMenu->addAction(showInquiryHistoryWindowAction);
    //showInquiryHistoryWindowAction->setCheckable(true);
    connect(showInquiryHistoryWindowAction, &QAction::triggered, this, &MainWindow::showInquiryHistoryWindow);

    /*
    QAction *a4 = new QAction(tr("Show &Deduction History Window"), this);
    windowMenu->addAction(a4);
    a4->setCheckable(true);
    */

    windowMenu->setEnabled(false);

}

void MainWindow::createNewGame() {
    NewGameCreator *newGameCreator = new NewGameCreator(this);
}

void MainWindow::showCardTableWindow() {
    setSubwindow(g);
}

void MainWindow::showNewInquiryInsertionWindow() {
    setSubwindow(n);
}

void MainWindow::showInquiryHistoryWindow() {
    setSubwindow(i);
}

void MainWindow::setSubwindow(QWidget *q) {
    /*
    QMdiArea *area = new QMdiArea;
    area->addSubWindow(q);
    this->setCentralWidget(area);
    */
    //area->addSubWindow(q);
    //area->activateNextSubWindow();
    //area->activatePreviousSubWindow();
    //area->show();
    q->show();
    q->show();
    q->move(q->pos());  //TODO barbatrucco
}

void MainWindow::setGame(Game *game) {
    this->game = game;
    windowMenu->setEnabled(true);
}

void MainWindow::myupdate() {
    g->myupdate2();
}
