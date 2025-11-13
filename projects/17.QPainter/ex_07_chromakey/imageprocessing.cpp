#include "imageprocessing.h"
#include <QDebug>

ImageProcessing::ImageProcessing(int width, int height, int dataSize)
{
    this->imageWidth  = width;
    this->imageHeight = height;
    this->imageDataSize = dataSize;

    qDebug() << "dataSize : " << dataSize;
}

void ImageProcessing::chromakeyProcess(QImage& sourceImage,
                                       QImage& targetImage,
                                       QImage& resultImage)
{
    uchar *pSourceData = sourceImage.bits();
    uchar *pTargetData = targetImage.bits();
    uchar *pResultData = resultImage.bits();

    QColor maskColor = QColor::fromRgb(sourceImage.pixel(1,1));
    int kred    = maskColor.red();
    int kgreen  = maskColor.green();
    int kblue   = maskColor.blue();

    int sPixRed, sPixGreen, sPixBlue;

    for (int inc = 0; inc < this->imageDataSize ; inc += 4)
    {
        sPixRed   = pSourceData[inc+2];
        sPixGreen = pSourceData[inc+1];
        sPixBlue  = pSourceData[inc];

        if((abs(kred - sPixRed) + abs(kgreen - sPixGreen) + abs(kblue - sPixBlue)) / 5 < 22 )
        {
            pResultData[inc+2] = pTargetData[inc+2];
            pResultData[inc+1] = pTargetData[inc+1];
            pResultData[inc] = pTargetData[inc+0];
        }
        else
        {
            pResultData[inc+2] = pSourceData[inc+2];
            pResultData[inc+1] = pSourceData[inc+1];
            pResultData[inc] = pSourceData[inc+0];
        }
    }
}






