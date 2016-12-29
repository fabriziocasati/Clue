#ifndef NUMBEROFPLAYERS_H
#define NUMBEROFPLAYERS_H


#include <QWidget>

class QGroupBox;
class QRadioButton;

class NumberOfPlayers : public QWidget
{
Q_OBJECT

public:
    explicit NumberOfPlayers(QWidget *parent = 0);

public slots:
    void openNewWindow();

private:
        QGroupBox *createNumberOfPlayersGroup();
        QRadioButton *radio3;



};

#endif // NUMBEROFPLAYERS_H
