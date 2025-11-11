#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    progress[0] = new QProgressBar(this);
    progress[0]->setMinimum(0);
    progress[0]->setMaximum(100);
    progress[0]->setValue(50);
    progress[0]->setOrientation(Qt::Horizontal);

    progress[1] = new QProgressBar(this);
    progress[1]->setMinimum(0);
    progress[1]->setMaximum(100);
    progress[1]->setValue(70);
    progress[1]->setOrientation(Qt::Horizontal);

    progress[0]->setGeometry(10,30, 300, 30);
    progress[1]->setGeometry(10,70, 300, 30);

}

Widget::~Widget()
{
}
