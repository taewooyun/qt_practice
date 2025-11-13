#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    steps = 0;
    pd = new QProgressDialog("File copy progress", "Cancel", 0, 100);
    connect(pd, SIGNAL(canceled()), this, SLOT(cancel()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(perform()));
    timer->start(100);
}

void Widget::perform()
{
    pd->setValue(steps);
    steps++;

    if (steps > pd->maximum())
        timer->stop();
}

void Widget::cancel()
{
    timer->stop();
}


Widget::~Widget()
{
    delete ui;
}

