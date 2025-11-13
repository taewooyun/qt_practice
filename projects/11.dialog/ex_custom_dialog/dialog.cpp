#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Custom Dialog");

    lbl = new QLabel("Name");
    edit = new QLineEdit("");

    okbtn = new QPushButton("Confirm");
    cancelbtn = new QPushButton("Cancel");
    connect(okbtn, &QPushButton::clicked, this, &Dialog::slot_okbtn);
    connect(cancelbtn, &QPushButton::clicked, this, &Dialog::slot_cancelbtn);

    QHBoxLayout *hlay1 = new QHBoxLayout();
    hlay1->addWidget(lbl);
    hlay1->addWidget(edit);

    QHBoxLayout *hlay2 = new QHBoxLayout();
    hlay2->addWidget(okbtn);
    hlay2->addWidget(cancelbtn);

    QVBoxLayout *vlay = new QVBoxLayout();
    vlay->addLayout(hlay1);
    vlay->addLayout(hlay2);
    setLayout(vlay);
}

void Dialog::slot_okbtn()
{
    emit accepted();
}

void Dialog::slot_cancelbtn()
{
    emit rejected();
}


Dialog::~Dialog()
{
}
