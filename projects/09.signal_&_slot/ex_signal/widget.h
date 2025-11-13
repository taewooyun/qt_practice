#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>

class SignalSlot : public QObject
{
    Q_OBJECT

public:
    void setValue(int val) {
        emit valueChanged(val);
    }

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *lbl;

public slots:
    void setValue(int val);

};

#endif // WIDGET_H
