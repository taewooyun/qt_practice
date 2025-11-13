#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "imageprocessing.h"

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
    ImageProcessing *imgProcess;

    QImage sourceQImage;
    QImage targetQImage;
    QImage resultQImage;

    int sourceQImageWidth;
    int sourceQImageHeight;
    int sourceQImageDataSize;

private slots:
    void slotChromakey();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
