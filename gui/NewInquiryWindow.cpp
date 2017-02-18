#include "NewInquiryWindow.h"
#include "game/Inquiry.h"
#include <QDebug>
#include <QtGui>

NewInquiryWindow::NewInquiryWindow(Game* game,
                                   InquiryHistoryWindow* inquiryHistoryWindow,
                                   QWidget* parent)
    : QDialog(parent)
{
    /* Store construct arguments */
    this->game = game;
    this->inquiryHistoryWindow = inquiryHistoryWindow;

    QVBoxLayout* vboxmain = new QVBoxLayout;

    QPushButton* m_button = new QPushButton("Ok", this);
    connect(m_button, SIGNAL (clicked()), this, SLOT (openNewWindow()));
    resize(500,300);

    QGroupBox* groupBox = new QGroupBox("Select which cards you were given");

    QHBoxLayout* vbox = new QHBoxLayout;
    vbox->setSpacing(30);

    vbox->addWidget((foo("Caller",
                         game->getPlayerList(),      callerRadioButton)),      0, Qt::AlignTop);
    vbox->addWidget((foo("Room Card",
                         game->getRoomCardList(),    roomCardRadioButton)),    1, Qt::AlignTop);
    vbox->addWidget((foo("Suspect Card",
                         game->getSuspectCardList(), suspectCardRadioButton)), 2, Qt::AlignTop);
    vbox->addWidget((foo("Weapon Card",
                         game->getWeaponCardList(),  weaponCardRadioButton)),  3, Qt::AlignTop);
    vbox->addWidget((foo("Giver",
                         game->getPlayerList(),      giverRadioButton)),       4, Qt::AlignTop);

    /*
     *
     *    {
     *     QGroupBox* v = new QGroupBox("Giver");
     *
     *     QVBoxLayout* vl = new QVBoxLayout;
     *
     *     std::vector<QString> r = game->getPlayerList();
     *     r.push_back(QString("(nobody)"));
     *     int i = 0;
     *     for (std::vector<QString>::iterator it = r.begin(); it != r.end(); ++it, i++)
     *     {
     *         giverRadioButton[i] = new QRadioButton(*it);
     *         vl->addWidget(giverRadioButton[i], i, Qt::AlignTop);
     *     }
     *
     *     v->setLayout(vl);
     *     vbox->addWidget(v, 4, Qt::AlignTop);
     *    }
     */

    QGroupBox* g2 = new QGroupBox(
        "Select the cards that are searched, who searches them and who passes a card");
    g2->setLayout(vbox);

    vboxmain->addWidget(g2, 0, Qt::AlignCenter);
    vboxmain->addWidget(m_button, 1, Qt::AlignCenter);
    setLayout(vboxmain);
}

void NewInquiryWindow::openNewWindow()
{
    std::string caller  = "null";
    std::string room    = "null";
    std::string suspect = "null";
    std::string weapon  = "null";
    std::string giver   = "(nobody)";
    Inquiry* q;
    for(int i = 0; i < game->getPlayerList().capacity(); i++)
        if(callerRadioButton[i]->isChecked())
        {
            caller = callerRadioButton[i]->text().toStdString();
            callerRadioButton[i]->setAutoExclusive(false);
            callerRadioButton[i]->setChecked(false);
            callerRadioButton[i]->setAutoExclusive(true);
        }

    for(int i = 0; i < game->getRoomCardList().capacity(); i++)
        if(roomCardRadioButton[i]->isChecked())
        {
            room = roomCardRadioButton[i]->text().toStdString();
            roomCardRadioButton[i]->setAutoExclusive(false);
            roomCardRadioButton[i]->setChecked(false);
            roomCardRadioButton[i]->setAutoExclusive(true);
        }

    for(int i = 0; i < game->getSuspectCardList().capacity(); i++)
        if(suspectCardRadioButton[i]->isChecked())
        {
            suspect = suspectCardRadioButton[i]->text().toStdString();
            suspectCardRadioButton[i]->setAutoExclusive(false);
            suspectCardRadioButton[i]->setChecked(false);
            suspectCardRadioButton[i]->setAutoExclusive(true);
        }

    for(int i = 0; i < game->getWeaponCardList().capacity(); i++)
        if(weaponCardRadioButton[i]->isChecked())
        {
            weapon = weaponCardRadioButton[i]->text().toStdString();
            weaponCardRadioButton[i]->setAutoExclusive(false);
            weaponCardRadioButton[i]->setChecked(false);
            weaponCardRadioButton[i]->setAutoExclusive(true);
        }

    for(int i = 0; i < game->getPlayerList().capacity(); i++) // TODO missing (nobody)!!!
        if(giverRadioButton[i]->isChecked())
        {
            giver = giverRadioButton[i]->text().toStdString();
            giverRadioButton[i]->setAutoExclusive(false);
            giverRadioButton[i]->setChecked(false);
            giverRadioButton[i]->setAutoExclusive(true);
        }

    q  = new Inquiry(game->getTurnNumber(), caller, room, suspect, weapon, giver);

    game->addInquiry(q, inquiryHistoryWindow);

    QCoreApplication::processEvents();
    //parentWidget()->update();
    inquiryHistoryWindow->myupdate();
}

void NewInquiryWindow::closeEvent(QCloseEvent* e)
{
    e->ignore();
    hide();
}

QGroupBox* NewInquiryWindow::foo(QString string,
                                 std::vector<QString> list,
                                 QRadioButton* radioButtonArray[])
{
    QGroupBox* v = new QGroupBox(string);
    QVBoxLayout* vl = new QVBoxLayout;

    int i = 0;
    for (std::vector<QString>::iterator it = list.begin(); it != list.end(); ++it, i++)
    {
        radioButtonArray[i] = new QRadioButton(*it);
        vl->addWidget(radioButtonArray[i], i, Qt::AlignTop);
    }

    v->setLayout(vl);
    return v;
}
