#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtStart,     &QPushButton::pressed,
            this,             &Widget::pbtStart);
    connect(ui->pbtStop,      &QPushButton::pressed,
            this,             &Widget::pbtStop);

    m_thread = new MyThread();
    connect(m_thread, &MyThread::logMessage,
            this,     &Widget::threadLogMsg);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::pbtStart()
{
    ui->textEdit->clear();

    if(!m_thread->isRunning())
        m_thread->start();
}

void Widget::pbtStop()
{
    if(!m_thread->isFinished())
        m_thread->stop();
}

void Widget::threadLogMsg(const QString &n)
{
    ui->textEdit->append(n);
}
