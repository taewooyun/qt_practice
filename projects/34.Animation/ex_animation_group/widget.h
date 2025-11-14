#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void slot_sequential();
   void slot_parallel();

private:
    QPropertyAnimation *anim1;
    QPropertyAnimation *anim2;
    QSequentialAnimationGroup *sGroup;
   QParallelAnimationGroup *pGroup;

};
#endif // WIDGET_H
