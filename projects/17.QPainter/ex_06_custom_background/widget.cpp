#include "widget.h"
#include <QPainter>
#include <QPaintEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint)
{
    m_bgImage = QPixmap(":/resources/background.png", "png");
    QBitmap bitmap = m_bgImage.createHeuristicMask();
    setFixedSize(m_bgImage.size());
    setMask(bitmap);

    pbtHello = new QPushButton("Hello world.", this);
    connect(pbtHello, SIGNAL(pressed()), this, SLOT(slot_pbtHello()));

    pbtHello->setGeometry(50, 120, 100, 30);
}

void Widget::slot_pbtHello()
{
    qDebug() << Q_FUNC_INFO;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(event->rect(), m_bgImage);

    painter.setPen(QColor(116, 116, 118));
    painter.setBrush(QColor(116, 116, 118));
    painter.drawRect(25, 65, 145, 260);
}

Widget::~Widget()
{
}

