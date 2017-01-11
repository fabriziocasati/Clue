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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{



    //QWidget *widget = new QWidget;
    //QMdiArea *area = new QMdiArea;
    //widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    /*
    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);
    */



    createMenus();


    setWindowTitle(tr("Clue Solver"));
    //setMinimumSize(160, 160);
    //resize(480, 320);

    /*
    NumberOfPlayers *w = new NumberOfPlayers();
    widget->addSubWindow(w);
    setCentralWidget(widget);
    */

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

    /*
    // Create and position the button
    m_button = new QPushButton("Create New Game", this);
    m_button->setGeometry(10, 10, 150, 30);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNewWindow()));
*/

    /*
    NumberOfPlayers *numberOfPlayersWindow = new NumberOfPlayers();

    QMdiArea area;
    area.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    area.addSubWindow(numberOfPlayersWindow);

    this->setCentralWidget(&area);
    */


    //window2 = new Window2();
    //window2->show();


/*
    QMainWindow window;
    //window.setFixedSize(800,600);

    window.setWindowTitle(QString::fromUtf8("My QMdiWindow"));
    QMdiArea area;
    area.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
*/
    /*
    //Create QMdiSubWindow
    QMdiSubWindow subWindow;
    subWindow.setFixedSize(200,100);

    //Add subWindow to Main QMdiWindow here
    //area.addSubWindow(&subWindow);
    area.addSubWindow(&subWindow, Qt::FramelessWindowHint );
    */
/*
    MySubWindow *subWindow = new MySubWindow();

    subWindow->setFixedSize(200,100);

    //Add subWindow to Main QMdiWindow here
    area.addSubWindow(subWindow);
    //area.addSubWindow(subWindow, Qt::FramelessWindowHint );

/*
    window.setCentralWidget(&area);
    //window.show();
    window.showMaximized();
*/


    //resize(500,300);


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
    //window = new Window(); // Be sure to destroy you window somewhere
    //this->hide();
    //this->setDisabled(true);

    QMdiArea *area = new QMdiArea;
    area->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    NumberOfPlayers *subWindow = new NumberOfPlayers(this);
    //subWindow->setFixedSize(600,300);
    //subWindow->move(300,300);
    //subWindow->move(QPoint(300,300));
    area->addSubWindow(subWindow);
    setCentralWidget(area);
    //subWindow->move(parentWidget()->window()->frameGeometry().topLeft() + parentWidget()->window()->rect().center() - rect().center());

}

void MainWindow::setSubwindow(QWidget *q) {
    QMdiArea *area = new QMdiArea;
    area->addSubWindow(q);
    this->setCentralWidget(area);
}
