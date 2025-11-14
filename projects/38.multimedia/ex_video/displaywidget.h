#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QVideoWidget>

class DisplayWidget : public QVideoWidget
{
    Q_OBJECT
public:
    DisplayWidget();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // DISPLAYWIDGET_H
