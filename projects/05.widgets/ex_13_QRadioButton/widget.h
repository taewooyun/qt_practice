#ifndef WIDGET_H
#define WIDGET_H

#include <QRadioButton>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:

};

#endif // WIDGET_H
