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
#include "Game.h"
#include <QString>

MainWindow::MainWindow(Main *main, QWidget *parent) :
    QMainWindow(parent)
{

    this->main = main;
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
    names2.push_back(QString("Stanza"));
    names2.push_back(QString("Arma"));
    names2.push_back(QString("Sospetto"));

    new Game(this, 4, names, num, names2);

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

}

void MainWindow::createNewGame() {
    main->createNewGame();
}

void MainWindow::setSubwindow(QWidget *q) {
    /*
    QMdiArea *area = new QMdiArea;
    area->addSubWindow(q);
    this->setCentralWidget(area);
    */
    area->addSubWindow(q);
    //area->activateNextSubWindow();
    //area->activatePreviousSubWindow();
    //area->show();
    q->show();
}
