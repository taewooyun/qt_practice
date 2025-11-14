#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <QCamera>
#include <QImageCapture>
#include <QMediaCaptureSession>
#include <QAudioInput>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QList<QCameraDevice>     mCamList;

    QVideoWidget                    *m_videoWidget;

    QScopedPointer<QImageCapture>   m_imageCapture;
    QMediaCaptureSession            m_captureSession;
    QScopedPointer<QCamera>         mCamera;
    QScopedPointer<QAudioInput>     m_audioInput;

    void cameraDevicesSearch();
    void viewCaptureImgDialog(const QImage &img);

private slots:
    void onStartBtn();
    void onStopBtn();
    void onCaptureBtn();
    void camError();

    void imageCaptured(int requestId, const QImage &img);
};
#endif // WIDGET_H
