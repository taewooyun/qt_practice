#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QComboBox>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QComboBox *combo;

private slots:
    void valueChanged();

};

#endif // WIDGET_H
