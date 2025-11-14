#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(350, 200);

    QPushButton *btn = new QPushButton("Button", this);
    connect(btn, &QPushButton::pressed,
            this, &Widget::btnClicked);
    btn->setGeometry(10, 10, 100, 30);

    animation = new QPropertyAnimation(btn, "geometry", this);

    animation->setDuration(3000); // 3 seconds
    animation->setStartValue(QRect(10, 10, 100, 30)); // Start position
    animation->setEndValue(QRect(200, 150, 100, 30)); // End position

    animation->setEasingCurve(QEasingCurve::OutInQuart);
}

void Widget::btnClicked()
{
    animation->start();
}

Widget::~Widget()
{
}

