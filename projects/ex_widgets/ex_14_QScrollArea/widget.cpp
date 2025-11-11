#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QImage image;
    QScrollArea *area;

    QLabel *lbl = new QLabel(this);

    image = QImage(":resources/fish.png");

    lbl->setPixmap(QPixmap::fromImage(image));

    area = new QScrollArea(this);
    area->setWidget(lbl);
    area->setBackgroundRole(QPalette::Dark);

    area->setGeometry(0, 0, image.width()-100, image.height()-100);
}

Widget::~Widget()
{

}
