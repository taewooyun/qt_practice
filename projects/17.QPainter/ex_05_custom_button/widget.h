#ifndef WIDGET_H
#define WIDGET_H

#include "imagebutton.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    ImageButton *imgBtn1;
    ImageButton *imgBtn2;

public slots:
    void clicked();

};

#endif // WIDGET_H
