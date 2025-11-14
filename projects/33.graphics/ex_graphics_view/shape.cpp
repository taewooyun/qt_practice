#include "shape.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

Shape::Shape()
{
    setFlags(QGraphicsItem::ItemIsSelectable|
             QGraphicsItem::ItemIsMovable);

    color = QColor(QRandomGenerator::global()->bounded(256),
                   QRandomGenerator::global()->bounded(256),
                   QRandomGenerator::global()->bounded(256));
}

QRectF Shape::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

QPainterPath Shape::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 50, 50);

    return path;
}

void Shape::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *,
                  QWidget *)
{
    if(scene()->collidingItems(this).isEmpty()) {
        painter->setBrush(color);
    } else {
        painter->setBrush(QColor(Qt::red));
    }

    painter->drawRect(0, 0, 50, 50);
}

void Shape::advance(int step)
{
   update();
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF eventpos = event->pos();
    QPointF shapePos = this->pos();

    QPointF wPos(eventpos.x() + shapePos.x() - 25,
                 eventpos.y() + shapePos.y() - 25);

    setPos(wPos);
    setPos(wPos);

    update();

    QGraphicsItem::mouseMoveEvent(event);
}


