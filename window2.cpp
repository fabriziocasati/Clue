#include <QtWidgets>

#include "window2.h"

Window2::Window2(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createFirstExclusiveGroup(), 0, 0);
    grid->addWidget(createSecondExclusiveGroup(), 1, 0);
    grid->addWidget(createNonExclusiveGroup(), 0, 1);
    grid->addWidget(createPushButtonGroup(), 1, 1);
    grid->addWidget(createNumberOfPlayersGroup(), 2, 0);
    grid->addWidget(createNamesOfThePlayersGroup(), 2, 1);
    grid->addWidget(createNumberOfCardsOfThePlayersGroup(), 2, 2);
    grid->addWidget(createCardsOfTheUserGroup(), 2, 3);
    setLayout(grid);

    setWindowTitle(tr("Group Boxes"));
    resize(480, 320);



    QGroupBox *groupBox = new QGroupBox("Number of players");

    QRadioButton *radio1 = new QRadioButton(groupBox->title());
    QRadioButton *radio2 = new QRadioButton("4");


    //radio1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);


    QGroupBox *groupBox2 = new QGroupBox("Number of players");

    radio3 = new QRadioButton("5");
    QRadioButton *radio4 = new QRadioButton("6");


    QVBoxLayout *vbox2 = new QVBoxLayout;
    vbox2->addWidget(radio3);
    vbox2->addWidget(radio4);
    vbox2->addStretch(1);
    groupBox2->setLayout(vbox2);

    grid->addWidget(groupBox, 3, 0);
    grid->addWidget(groupBox2, 3, 1);

    //radio4->setDisabled(true);

    connect(radio1, SIGNAL (clicked()), this, SLOT (OnRadioButton1()));




}

void Window2::OnRadioButton1()
{
    radio3->setEnabled(not(radio3->isEnabled()));
    radio3->setChecked(false);
}

QGroupBox *Window2::createNumberOfPlayersGroup()
{
    QGroupBox *groupBox = new QGroupBox("Number of players");

    //QRadioButton *radio1 = new QRadioButton(groupBox->title());
    QRadioButton *radio1 = new QRadioButton("3");
    QRadioButton *radio2 = new QRadioButton("4");
    QRadioButton *radio3 = new QRadioButton("5");
    QRadioButton *radio4 = new QRadioButton("6");

    QPushButton *m_button = new QPushButton("Create New Game", this);

    radio1->setChecked(true);

    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    vbox->addWidget(m_button);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window2::createNamesOfThePlayersGroup()
{
    QGroupBox *groupBox = new QGroupBox("Names of the players");

    QLabel *label = new QLabel("Ciao");
    QLineEdit *text = new QLineEdit();

    QRadioButton *radio1 = new QRadioButton("3");
    QRadioButton *radio2 = new QRadioButton("4");
    QRadioButton *radio3 = new QRadioButton("5");
    QRadioButton *radio4 = new QRadioButton("6");

    radio1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(label);
    vbox->addWidget(text);
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}


QGroupBox *Window2::createNumberOfCardsOfThePlayersGroup()
{
    QGroupBox *groupBox = new QGroupBox("Number of cards for each player");

    /*
    groupBox->setStyleSheet("QGroupBox {"
                             "border: 1px solid gray;}"
            "QGroupBox::title {"
                             "color: blue;}");
                             */

    QRadioButton *radio1 = new QRadioButton("3");
    QRadioButton *radio2 = new QRadioButton("4");
    QRadioButton *radio3 = new QRadioButton("5");
    QRadioButton *radio4 = new QRadioButton("6");

    radio1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}


QGroupBox *Window2::createCardsOfTheUserGroup()
{
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
    //vbox->addWidget(groupBox1);

    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}


QGroupBox *Window2::createFirstExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));

    QRadioButton *radio1 = new QRadioButton(tr("&Radio button 1"));
    QRadioButton *radio2 = new QRadioButton(tr("R&adio button 2"));
    QRadioButton *radio3 = new QRadioButton(tr("Ra&dio button 3"));

    radio1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window2::createSecondExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("E&xclusive Radio Buttons"));
    groupBox->setCheckable(true);
    groupBox->setChecked(false);

    QRadioButton *radio1 = new QRadioButton(tr("Rad&io button 1"));
    QRadioButton *radio2 = new QRadioButton(tr("Radi&o button 2"));
    QRadioButton *radio3 = new QRadioButton(tr("Radio &button 3"));
    radio1->setChecked(true);
    QCheckBox *checkBox = new QCheckBox(tr("Ind&ependent checkbox"));
    checkBox->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(checkBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window2::createNonExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Non-Exclusive Checkboxes"));
    groupBox->setFlat(true);

    QCheckBox *checkBox1 = new QCheckBox(tr("&Checkbox 1"));
    QCheckBox *checkBox2 = new QCheckBox(tr("C&heckbox 2"));
    checkBox2->setChecked(true);
    QCheckBox *tristateBox = new QCheckBox(tr("Tri-&state button"));
    tristateBox->setTristate(true);
    tristateBox->setCheckState(Qt::PartiallyChecked);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(checkBox1);
    vbox->addWidget(checkBox2);
    vbox->addWidget(tristateBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window2::createPushButtonGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("&Push Buttons"));
    groupBox->setCheckable(true);
    groupBox->setChecked(true);

    QPushButton *pushButton = new QPushButton(tr("&Normal Button"));
    QPushButton *toggleButton = new QPushButton(tr("&Toggle Button"));
    toggleButton->setCheckable(true);
    toggleButton->setChecked(true);
    QPushButton *flatButton = new QPushButton(tr("&Flat Button"));
    flatButton->setFlat(true);

    QPushButton *popupButton = new QPushButton(tr("Pop&up Button"));
    QMenu *menu = new QMenu(this);
    menu->addAction(tr("&First Item"));
    menu->addAction(tr("&Second Item"));
    menu->addAction(tr("&Third Item"));
    menu->addAction(tr("F&ourth Item"));
    popupButton->setMenu(menu);

    QAction *newAction = menu->addAction(tr("Submenu"));
    QMenu *subMenu = new QMenu(tr("Popup Submenu"));
    subMenu->addAction(tr("Item 1"));
    subMenu->addAction(tr("Item 2"));
    subMenu->addAction(tr("Item 3"));
    newAction->setMenu(subMenu);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(pushButton);
    vbox->addWidget(toggleButton);
    vbox->addWidget(flatButton);
    vbox->addWidget(popupButton);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}
