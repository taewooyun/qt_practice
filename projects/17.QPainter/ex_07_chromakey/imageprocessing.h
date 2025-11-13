#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QImage>
#include <QColor>

class ImageProcessing
{
public:
    ImageProcessing(int width, int height, int dataSize);

    void chromakeyProcess(QImage& sourceImage,
                          QImage& targetImage,
                          QImage& resultImage);

private:
    int imageWidth;
    int imageHeight;
    int imageDataSize;

};

#endif // IMAGEPROCESSING_H
