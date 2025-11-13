#include "imagebutton.h"

#define BEHAVIOUR_NOMAL       0
#define BEHAVIOUR_ENTER       1
#define BEHAVIOUR_LEAVE       2
#define BEHAVIOUR_PRESS       3
#define BEHAVIOUR_RELEASE     4
#define BEHAVIOUR_DISABLE     5

ImageButton::ImageButton(QWidget *parent) :
    QWidget(parent),
    disabled(false)
{
    behaviour = BEHAVIOUR_NOMAL;

    QImage image(":/resources/normal.png");

    this->setFixedWidth(image.width());
    this->setFixedHeight(image.height());
}

void ImageButton::setDisabled(bool val)
{
    disabled = val;
    update();
}

void ImageButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter;
    painter.begin(this);

    if(disabled == true) {
        imgFileName = QString(":/resources/disable.png");
    } else {
        if(this->behaviour == BEHAVIOUR_NOMAL)
            imgFileName = QString(":/resources/normal.png");
        else if(this->behaviour == BEHAVIOUR_ENTER)
            imgFileName = QString(":/resources/enter.png");
        else if(this->behaviour == BEHAVIOUR_LEAVE)
            imgFileName = QString(":/resources/normal.png");
        else if(this->behaviour == BEHAVIOUR_PRESS)
            imgFileName = QString(":/resources/press.png");
    }

    QImage image(imgFileName);
    painter.drawImage(0, 0, image);
    painter.end();
}

void ImageButton::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event);
    this->behaviour = BEHAVIOUR_ENTER;
    update();
}

void ImageButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->behaviour = BEHAVIOUR_NOMAL;
    update();
}

void ImageButton::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    this->behaviour = BEHAVIOUR_PRESS;
    update();

    emit clicked();
}

void ImageButton::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    this->behaviour = BEHAVIOUR_ENTER;
    update();
}

void ImageButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
}







