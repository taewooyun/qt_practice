#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

#define IMGSOURCE ":/images/jana_480p.png"
#define IMGTARGET ":/images/target_480p.png"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtChromakey, SIGNAL(clicked()),
            this, SLOT(slotChromakey()));

    sourceQImage = QImage(IMGSOURCE);
    targetQImage = QImage(IMGTARGET);
    resultQImage = QImage(targetQImage.width(),
                          targetQImage.height(),
                          QImage::Format_RGB32);

    sourceQImageWidth  = targetQImage.width();
    sourceQImageHeight = targetQImage.height();
    sourceQImageDataSize = targetQImage.width() * targetQImage.height() * 4;

    imgProcess = new ImageProcessing(sourceQImageWidth,
                                     sourceQImageHeight,
                                     sourceQImageDataSize);
}

void Widget::slotChromakey()
{
    imgProcess->chromakeyProcess(sourceQImage,
                                 targetQImage,
                                 resultQImage);

    int width   = ui->labelChromakey->width();
    int height  = ui->labelChromakey->height();

    QPixmap drawPixmap = QPixmap::fromImage(resultQImage)
                                    .scaled(width, height);
    ui->labelChromakey->setPixmap(drawPixmap);
}

Widget::~Widget()
{
    delete ui;
}
