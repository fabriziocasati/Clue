#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "window.h"

class QPushButton;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
   void openNewWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *m_button;
    Window *window;
};

#endif // MAINWINDOW_H
