#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPixmap m_bgImage;
    QPushButton *pbtHello;

private slots:
    void slot_pbtHello();

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // WIDGET_H
