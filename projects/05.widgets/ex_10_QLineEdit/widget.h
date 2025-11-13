#ifndef WIDGET_H
#define WIDGET_H

#include <QLineEdit>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLineEdit *edit[5];
    QLabel *lbl;

private slots:
    void textChanged(QString str);

};

#endif // WIDGET_H
