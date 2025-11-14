#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPropertyAnimation *animation;

public slots:
    void btnClicked();

};
#endif // WIDGET_H
