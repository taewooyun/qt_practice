#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(320, 270);
    QPushButton *btn1 = new QPushButton("First", this);
    btn1->setGeometry(10, 10, 100, 30);

    QPushButton *btn2 = new QPushButton("Second", this);
    btn2->setGeometry(10, 45, 100, 30);

    anim1 = new QPropertyAnimation(btn1, "geometry");
    anim1->setDuration(2000); // 2 Seconds (Unit: Miliseconds)
    anim1->setStartValue(QRect(10, 10, 100, 30)); // Start Position
    anim1->setEndValue(QRect(200, 150, 100, 30)); // End Position

    anim2 = new QPropertyAnimation(btn2, "geometry");
    anim2->setDuration(2000); // 2 Seconds (Unit: Miliseconds)
    anim2->setStartValue(QRect(10, 45, 100, 30)); // Start Position
    anim2->setEndValue(QRect(200, 195, 100, 30)); // End Position

    // sGroup = new QSequentialAnimationGroup; // Sequential Group
    // sGroup->addAnimation(anim1);
    // sGroup->addAnimation(anim2);

    // connect(btn1, SIGNAL(clicked()), this, SLOT(slot_sequential()));

   pGroup = new QParallelAnimationGroup; // Parallel Group
   pGroup->addAnimation(anim1);
   pGroup->addAnimation(anim2);

   connect(btn1, SIGNAL(clicked()), this, SLOT(slot_parallel()));
}

void Widget::slot_sequential()
{
    sGroup->start(QPropertyAnimation::DeleteWhenStopped);
}

void Widget::slot_parallel()
{
   pGroup->start(QPropertyAnimation::DeleteWhenStopped);
}

Widget::~Widget()
{
}
