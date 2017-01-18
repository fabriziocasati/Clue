#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMdiArea>
#include "Main.h"


class QPushButton;
class QRadioButton;
class QGroupBox;
class QGridLayout;
class Main;
class QMdiArea;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Main *main, QWidget *parent = 0);
    void resizeEvent (QResizeEvent* event);
    QPixmap* m_pPixmap;
    QPalette* m_pPalette;

    void setSubwindow(QWidget *q);
    void createNewGame();

private:
    Main *main;
    QMenu *fileMenu;
    QPushButton *m_button;
    QRadioButton *r_button;
    QGroupBox *createFirstExclusiveGroup();
    QMdiArea *area;

    void createMenus();


private slots:
    void showCardTableWindow();

};

#endif // MAINWINDOW_H
