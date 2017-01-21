#include "NewInquiryWindow.h"
#include "game/Inquiry.h"
#include <QtGui>
#include <QDebug>

NewInquiryWindow::NewInquiryWindow(Game *g, InquiryHistoryWindow *i, QWidget *parent)
    : QDialog(parent)
{

    this->game = g;
    this->i = i;
    //this->gw = gw;

    QVBoxLayout *vboxmain = new QVBoxLayout;

    QPushButton *m_button = new QPushButton("Ok", this);
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
    //vbox->addStretch(1);


{
        QGroupBox *v = new QGroupBox("Caller");

        QVBoxLayout *vl = new QVBoxLayout;


        /*
        for(int i=0; i<6; i++) {
            std::string numberString = boost::lexical_cast<std::string>(i);
            QString numberQString = QString::fromStdString(numberString);
            callerRadioButton[i] = new QRadioButton(numberQString);
            vl->addWidget(callerRadioButton[i]);
        }
        */


        std::vector<QString> r = g->getPlayerList();
        int i=0;
        for (std::vector<QString>::iterator it = r.begin(); it != r.end(); ++it, i++) {
            callerRadioButton[i] = new QRadioButton(*it);
            vl->addWidget(callerRadioButton[i], i, Qt::AlignTop);
        }


        v->setLayout(vl);
        vbox->addWidget(v, 0, Qt::AlignTop);

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
        vbox->addWidget(v, 1, Qt::AlignTop);

    }

    {
        QGroupBox *v = new QGroupBox("Suspect Card");

        QVBoxLayout *vl = new QVBoxLayout;

        std::vector<QString> r = g->getSuspectCardList();
        int i=0;
        for (std::vector<QString>::iterator it = r.begin(); it != r.end(); ++it, i++) {
            suspectCardCheckBox[i] = new QRadioButton(*it);
            vl->addWidget(suspectCardCheckBox[i], i, Qt::AlignTop);
        }

        /*
        for(int i=0; i<6; i++) {
            //std::string numberString = boost::lexical_cast<std::string>(i);
            //QString numberQString = QString::fromStdString(numberString);
            suspectCardCheckBox[i] = new QRadioButton("2");
            vl->addWidget(suspectCardCheckBox[i]);
        }
        */

        v->setLayout(vl);
        vbox->addWidget(v, 2, Qt::AlignTop);

    }

    {
        QGroupBox *v = new QGroupBox("Weapon Card");

        QVBoxLayout *vl = new QVBoxLayout;

        std::vector<QString> r = g->getWeaponCardList();
        int i=0;
        for (std::vector<QString>::iterator it = r.begin(); it != r.end(); ++it, i++) {
            weaponCardCheckBox[i] = new QRadioButton(*it);
            vl->addWidget(weaponCardCheckBox[i], i, Qt::AlignTop);
        }

/*
        for(int i=0; i<6; i++) {
            //std::string numberString = boost::lexical_cast<std::string>(i);
            //QString numberQString = QString::fromStdString(numberString);
            weaponCardCheckBox[i] = new QRadioButton("3");
            vl->addWidget(weaponCardCheckBox[i]);
        }
*/

        v->setLayout(vl);
        vbox->addWidget(v, 3, Qt::AlignTop);

    }

    {
        QGroupBox *v = new QGroupBox("Giver");

        QVBoxLayout *vl = new QVBoxLayout;

        /*
        for(int i=0; i<7; i++) {
            //std::string numberString = boost::lexical_cast<std::string>(i);
            //QString numberQString = QString::fromStdString(numberString);
            giverRadioButton[i] = new QRadioButton("4");
            vl->addWidget(giverRadioButton[i]);
        }
        */

        std::vector<QString> r = g->getPlayerList();
        r.push_back(QString("(nobody)"));
        int i=0;
        for (std::vector<QString>::iterator it = r.begin(); it != r.end(); ++it, i++) {
            giverRadioButton[i] = new QRadioButton(*it);
            vl->addWidget(giverRadioButton[i], i, Qt::AlignTop);
        }

        v->setLayout(vl);
        vbox->addWidget(v, 4, Qt::AlignTop);
    }

    QGroupBox *g2 = new QGroupBox("Select the cards that are searched, who searches them and who passes a card");
    g2->setLayout(vbox);

    vboxmain->addWidget(g2, 0, Qt::AlignCenter);
    vboxmain->addWidget(m_button, 1, Qt::AlignCenter);
    setLayout(vboxmain);

}

void NewInquiryWindow::openNewWindow() {

    std::string caller = "null";
    std::string room = "null";
    std::string suspect = "null";
    std::string weapon = "null";
    std::string giver = "(nobody)";
    Inquiry *q;
    for(int i=0; i<game->getPlayerList().capacity(); i++)
        if(callerRadioButton[i]->isChecked())
            caller = callerRadioButton[i]->text().toStdString();

    for(int i=0; i<game->getRoomCardList() .capacity(); i++)
        if(roomCardCheckBox[i]->isChecked())
            room = roomCardCheckBox[i]->text().toStdString();

    for(int i=0; i<game->getSuspectCardList().capacity(); i++)
        if(suspectCardCheckBox[i]->isChecked())
            suspect = suspectCardCheckBox[i]->text().toStdString();

    for(int i=0; i<game->getWeaponCardList().capacity(); i++)
        if(weaponCardCheckBox[i]->isChecked())
            weapon = weaponCardCheckBox[i]->text().toStdString();

    for(int i=0; i<game->getPlayerList().capacity(); i++) // TODO missing (nobody)!!!
        if(giverRadioButton[i]->isChecked())
            giver = giverRadioButton[i]->text().toStdString();


    q  = new Inquiry(game->getTurnNumber(), caller, room, suspect, weapon, giver);


    game->addInquiry(q, i);

    gw->myupdate();

    QCoreApplication::processEvents();
    parentWidget()->update();
    i->myupdate();
    //i->close();
    //i->show();
    //i->repaint();

    this->close();
}

void NewInquiryWindow::closeEvent(QCloseEvent *e)
{
//e->ignore();
}

