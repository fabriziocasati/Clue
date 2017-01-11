#include "mainwindow.h"
#include "numberofplayers.h"
#include "gui/newinquirywindow.h"
#include "ui_mainwindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include "mysubwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {


    //QWidget *widget = new QWidget;
    widget = new QMdiArea;
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

    newAct = new QAction(tr("&New"), this);
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Menus"));
    //setMinimumSize(160, 160);
    //resize(480, 320);

    /*
    NumberOfPlayers *w = new NumberOfPlayers();
    widget->addSubWindow(w);
    setCentralWidget(widget);
    */

    /*
    m_pPalette	= new QPalette();
          m_pPixmap		= new QPixmap("/home/fabrizio/qt_workspace/Clue_Solver/img2.jpg");

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

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    /*
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
    */
}
#endif // QT_NO_CONTEXTMENU

void MainWindow::openNewWindow() {
    //window = new Window(); // Be sure to destroy you window somewhere
    //window->show();

    //window2 = new Window2();
    //window2->show();

    //NumberOfPlayers *numberOfPlayersWindow = new NumberOfPlayers();
    //numberOfPlayersWindow->show();


    //this->hide();
    //this->setDisabled(true);
    // ...



    QMdiArea *area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    NumberOfPlayers *subWindow = new NumberOfPlayers();
    //subWindow->setFixedSize(600,300);
    subWindow->move(300,300);
    subWindow->move(QPoint(300,300));
    area->addSubWindow(subWindow);
    setCentralWidget(area);
    //subWindow->move(parentWidget()->window()->frameGeometry().topLeft() + parentWidget()->window()->rect().center() - rect().center());


    //area.show();

    //Game *g = new Game();
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
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    connect(newAct, &QAction::triggered, this, &MainWindow::openNewWindow);

}
