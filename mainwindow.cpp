#include "mainwindow.h"
#include "numberofplayers.h"
#include "newinquirywindow.h"
#include "ui_mainwindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include "mysubwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {

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

    NumberOfPlayers *numberOfPlayersWindow = new NumberOfPlayers();
    /*
    QMdiArea area;
    area.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    area.addSubWindow(numberOfPlayersWindow);

    this->setCentralWidget(&area);
    */


    window2 = new Window2();
    //window2->show();



    QMainWindow window;
    //window.setFixedSize(800,600);

    window.setWindowTitle(QString::fromUtf8("My QMdiWindow"));
    QMdiArea area;
    area.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    /*
    //Create QMdiSubWindow
    QMdiSubWindow subWindow;
    subWindow.setFixedSize(200,100);

    //Add subWindow to Main QMdiWindow here
    //area.addSubWindow(&subWindow);
    area.addSubWindow(&subWindow, Qt::FramelessWindowHint );
    */

    MySubWindow *subWindow = new MySubWindow();

    subWindow->setFixedSize(200,100);

    //Add subWindow to Main QMdiWindow here
    area.addSubWindow(subWindow);
    //area.addSubWindow(subWindow, Qt::FramelessWindowHint );


    window.setCentralWidget(&area);
    //window.show();
    window.showMaximized();



    resize(500,300);


}

void MainWindow::openNewWindow() {
    window = new Window(); // Be sure to destroy you window somewhere
    //window->show();

    window2 = new Window2();
    //window2->show();

    NumberOfPlayers *numberOfPlayersWindow = new NumberOfPlayers();
    //numberOfPlayersWindow->show();


    //this->hide();
    //this->setDisabled(true);
    // ...

    QMdiArea area;
    area.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    area.addSubWindow(numberOfPlayersWindow);

    this->setCentralWidget(&area);
    this->update();

    area.show();

    Game *g = new Game();
}

void MainWindow::resizeEvent (QResizeEvent* event)
  {
    /*
    m_pPalette->setBrush(QPalette::Background,QBrush(m_pPixmap->scaled(width(),height())));
      setPalette(*m_pPalette);
      */
  };

