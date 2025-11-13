#include "widget.h"

#include <QPushButton>
#include <QFocusFrame>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("QPushButton");

    QPushButton *btn[3];

    int ypos = 30;
    for(int i = 0 ; i < 3 ; i++)
    {
        btn[i] = new QPushButton(QString("Frame's button %1").arg(i), this);
        btn[i]->setGeometry(10, ypos, 300, 40);
        ypos += 50;
    }

    connect(btn[0], &QPushButton::clicked,  this, &Widget::btn_click);
    connect(btn[1], &QPushButton::clicked,  this, &Widget::btn_click);
    connect(btn[2], &QPushButton::clicked, this, &Widget::btn_click);

    btn_frame = new QFocusFrame(this);
}

void Widget::btn_click()
{
    qDebug("Button Click");
    btn_frame->setWidget(qobject_cast<QPushButton*>(sender()));
    btn_frame->setAutoFillBackground(true);
    //
}

Widget::~Widget()
{
}

