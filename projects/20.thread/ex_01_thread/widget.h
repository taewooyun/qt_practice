#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"

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

    MyThread *m_thread;

public slots:
    void pbtStart();
    void pbtStop();

    void threadLogMsg(const QString &n);
};

#endif // WIDGET_H
