#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QWidget>
#include <QPainter>

class ImageButton : public QWidget
{
    Q_OBJECT
public:
    explicit ImageButton(QWidget *parent = 0);
    void setDisabled(bool val);
    bool getDisabled(){return disabled;}

private:
    QString imgFileName;
    qint32  behaviour;
    bool    disabled;

signals:
    void clicked();

protected:
    void paintEvent(QPaintEvent *event);
    virtual void enterEvent(QEnterEvent* event);
    virtual void leaveEvent(QEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // IMAGEBUTTON_H
