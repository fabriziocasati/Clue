#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "window2.h"
#include "window.h"


class QPushButton;
class QRadioButton;
class QGroupBox;
class QGridLayout;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void resizeEvent (QResizeEvent* event);
    QPixmap* m_pPixmap;
      QPalette* m_pPalette;

public slots:
   void openNewWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *m_button;
    QRadioButton *r_button;
    Window *window;
    Window2 *window2;
    QGroupBox *createFirstExclusiveGroup();
};

#endif // MAINWINDOW_H
