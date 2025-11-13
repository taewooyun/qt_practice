#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lbl = new QLabel("", this);
    lbl->setGeometry(10, 10, 250, 40);

    SignalSlot myObject;

    // New Style
    connect(&myObject, &SignalSlot::valueChanged,
            this,      &Widget::setValue);

    //Old Style
    /*
    connect(&myObject, SIGNAL(valueChanged(int)),
            this,      SLOT(setValue(int)));
    */

    myObject.setValue(50);
}


void Widget::setValue(int val)
{
    QString labelText = QString("Signal emmit, Value : %1").arg(val);
    lbl->setText(labelText);
}

Widget::~Widget()
{
}



