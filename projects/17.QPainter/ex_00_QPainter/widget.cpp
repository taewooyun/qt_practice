#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// Basic Drawing
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    painter.setPen(Qt::blue);
    painter.drawLine(10, 10, 100, 40); // Line
    painter.drawRect(120, 10, 80, 80); // Rect

    QRectF rect(230.0, 10.0, 80.0, 80.0);
    painter.drawRoundedRect(rect, 20, 20); // Round rect

    QPointF p1[3] = {
        QPointF(10.0, 110.0),
        QPointF(110.0, 110.0),
        QPointF(110.0, 190.0)
    };
    painter.drawPolyline(p1, 3);

    QPointF p2[3] = {
        QPointF(120.0, 110.0),
        QPointF(220.0, 110.0),
        QPointF(220.0, 190.0)
    };
    painter.drawPolygon(p2, 3);

    painter.setFont(QFont("Arial", 16));
    painter.setPen(Qt::black);
    QRect font_rect(10, 200, 440, 50);
    painter.drawText(font_rect, Qt::AlignCenter,
                     "Qt Korea Community (https://www.qt-dev.com)");

    painter.end();
}
