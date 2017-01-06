#ifndef MYSUBWINDOW_H
#define MYSUBWINDOW_H

#include <QObject>
#include <QWidget>
#include <QMdiSubWindow>
#include <QPushButton>

class MySubWindow : public QWidget
{
public:
    MySubWindow(QWidget *parent = 0);
};

#endif // MYSUBWINDOW_H
