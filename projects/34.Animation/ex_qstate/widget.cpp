#include "widget.h"
#include <QPushButton>
#include <QtStateMachine/QStateMachine>
#include <QSignalTransition>
#include <QStateMachine>
#include <QPropertyAnimation>
#include <QSignalTransition>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(360, 290);

    QPushButton *button = new QPushButton("Button", this);
    button->setGeometry(10, 10, 100, 30);

    QStateMachine *machine = new QStateMachine;

    QState *state1 = new QState(machine);
    state1->assignProperty(button, "geometry", QRect(10, 10, 100, 30));
    machine->setInitialState(state1);

    QState *state2 = new QState(machine);
    state2->assignProperty(button, "geometry", QRect(250, 250, 100, 30));

    QSignalTransition *t1 =
        state1->addTransition(button, SIGNAL(clicked()), state2);
    t1->addAnimation(new QPropertyAnimation(button, "geometry"));

    QSignalTransition *t2 =
        state2->addTransition(button, SIGNAL(clicked()), state1);
    t2->addAnimation(new QPropertyAnimation(button, "geometry"));

    machine->start();
}

Widget::~Widget()
{
}

