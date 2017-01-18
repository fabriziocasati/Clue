#include "NewInquiryWindow.h"
#include "Inquiry.h"

NewInquiryWindow::NewInquiryWindow(Game *g, QWidget *parent)
    : QWidget(parent)
{

    this->game = g;
    //this->gw = gw;

    QPushButton *m_button = new QPushButton("Create New Game", this);
    resize(500,300);


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

    connect(m_button, SIGNAL (clicked()), this, SLOT (openNewWindow()));

}

void NewInquiryWindow::openNewWindow() {
    Inquiry *q = new Inquiry(1, "a", "b", "c", "d", "e");
    game->addInquiry(q);

    gw->myupdate();

    this->close();
}

