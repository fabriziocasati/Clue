#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;
class Window : public QWidget
{
 public:
  explicit Window(QWidget *parent = 0);
 private:
    QPushButton *m_button;
    QPushButton *m_button2;
};

#endif // WINDOW_H
