#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>

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
    QFile *mFile;

private slots:
    void slotPbtOpenPress();
    void slotPbtWritePress();
    void slotPbtClosePress();
    void slotAboutToClose();
};

#endif // WIDGET_H
