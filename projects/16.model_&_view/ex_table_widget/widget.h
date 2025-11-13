#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHeaderView>
#include <QPainter>
#include <QCheckBox>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

public slots:
    void checkBoxClicked(bool state);
};



#endif // WIDGET_H
