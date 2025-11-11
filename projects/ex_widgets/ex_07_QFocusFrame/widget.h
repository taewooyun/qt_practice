#ifndef WIDGET_H
#define WIDGET_H

#include <QFocusFrame>
#include <QWidget>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QFocusFrame *btn_frame;

private slots:
    void btn_click();

};

#endif // WIDGET_H
