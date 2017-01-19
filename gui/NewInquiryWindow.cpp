#include "NewInquiryWindow.h"
#include "Inquiry.h"

#include <QDebug>

NewInquiryWindow::NewInquiryWindow(Game *g, QWidget *parent)
    : QWidget(parent)
{


    QRadioButton *roomCardCheckBox[10];
    QRadioButton *suspectCardCheckBox[6];
    QRadioButton *weaponCardCheckBox[6];
    QRadioButton *giverRadioButton[7];


    this->game = g;
    //this->gw = gw;

    QPushButton *m_button = new QPushButton("Create New Game", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNewWindow()));
    resize(500,300);

/*
    QGroupBox *groupBox = new QGroupBox("Your cards");
    QGroupBox *groupBox2 = new QGroupBox("Your cards");
    QGroupBox *groupBox3 = new QGroupBox("Your cards");

    /*
    groupBox2->setStyleSheet("QGroupBox {"
                             "border: 1px solid gray;}"
            "QGroupBox::title {"
                             "color: blue;}");
    groupBox3->setStyleSheet("QGroupBox {  border: 1px solid gray;}");
    */

    /*
    QCheckBox *checkBox1 = new QCheckBox("Checkbox 1");
    QCheckBox *checkBox2 = new QCheckBox("Checkbox 2");
    QCheckBox *checkBox3 = new QCheckBox("Checkbox 3");

    QHBoxLayout *vbox = new QHBoxLayout;
    QVBoxLayout *vbox2 = new QVBoxLayout;
    QVBoxLayout *vbox3 = new QVBoxLayout;

    vbox2->addWidget(checkBox1);
    groupBox2->setLayout(vbox2);

    vbox3->addWidget(checkBox2);
    vbox3->addWidget(checkBox3);
    groupBox3->setLayout(vbox3);

    vbox->addWidget(groupBox2);
    vbox->addWidget(groupBox3);
    vbox->addWidget(m_button);
    //vbox->addWidget(groupBox1);

    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(groupBox, 0, 0);
    setLayout(grid);


*/

    //std::string numberString = boost::lexical_cast<std::string>(numberOfPlayers);
    //QString numberQString = QString::fromStdString(numberString);

    QGroupBox *groupBox = new QGroupBox("Select which cards you were given");

    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->setSpacing(30);
    //vbox->setAlignment(Qt::AlignLeft);
    vbox->addWidget(m_button);
    //vbox->addStretch(1);


{
        QGroupBox *v = new QGroupBox("Caller");

        QVBoxLayout *vl = new QVBoxLayout;


        for(int i=0; i<6; i++) {
            std::string numberString = boost::lexical_cast<std::string>(i);
            QString numberQString = QString::fromStdString(numberString);
            callerRadioButton[i] = new QRadioButton(numberQString);
            vl->addWidget(callerRadioButton[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

}

    {
        QGroupBox *v = new QGroupBox("Room Card");

        QVBoxLayout *vl = new QVBoxLayout;

        /*
        for(int i=0; i<9; i++) {
            //std::string numberString = boost::lexical_cast<std::string>(i);
            //QString numberQString = QString::fromStdString(numberString);
            roomCardCheckBox[i] = new QRadioButton("1");
            vl->addWidget(roomCardCheckBox[i]);
        }
        */

        std::vector<QString> r = g->getRoomCardList();
        int i=0;
        for (std::vector<QString>::iterator it = r.begin(); it != r.end(); ++it, i++) {
            roomCardCheckBox[i] = new QRadioButton(*it);
            vl->addWidget(roomCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    {
        QGroupBox *v = new QGroupBox("Suspect Card");

        QVBoxLayout *vl = new QVBoxLayout;

        for(int i=0; i<6; i++) {
            //std::string numberString = boost::lexical_cast<std::string>(i);
            //QString numberQString = QString::fromStdString(numberString);
            suspectCardCheckBox[i] = new QRadioButton("2");
            vl->addWidget(suspectCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    {
        QGroupBox *v = new QGroupBox("Weapon Card");

        QVBoxLayout *vl = new QVBoxLayout;

        for(int i=0; i<6; i++) {
            //std::string numberString = boost::lexical_cast<std::string>(i);
            //QString numberQString = QString::fromStdString(numberString);
            weaponCardCheckBox[i] = new QRadioButton("3");
            vl->addWidget(weaponCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);

    }

    {
        QGroupBox *v = new QGroupBox("Giver");

        QVBoxLayout *vl = new QVBoxLayout;

        for(int i=0; i<7; i++) {
            //std::string numberString = boost::lexical_cast<std::string>(i);
            //QString numberQString = QString::fromStdString(numberString);
            giverRadioButton[i] = new QRadioButton("4");
            vl->addWidget(roomCardCheckBox[i]);
        }

        v->setLayout(vl);
        vbox->addWidget(v);
    }

    setLayout(vbox);

}

void NewInquiryWindow::openNewWindow() {

    Inquiry *q;
    for(int i=0; i<6; i++)
        if(callerRadioButton[i]->isChecked())
           q  = new Inquiry(i, "a", "b", "c", "d", "e");


    game->addInquiry(q);

    gw->myupdate();

    this->close();
}

