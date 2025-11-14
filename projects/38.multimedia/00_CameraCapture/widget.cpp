#include "widget.h"
#include "./ui_widget.h"

#include <QMediaDevices>
#include <QMessageBox>
#include <QLabel>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtStart, SIGNAL(clicked()),
            this, SLOT(onStartBtn()));
    connect(ui->pbtStop,  SIGNAL(clicked()),
            this, SLOT(onStopBtn()));
    connect(ui->pbtCapture, SIGNAL(clicked()),
            this, SLOT(onCaptureBtn()));

    cameraDevicesSearch();

    ui->pbtStart->setEnabled(true);
    ui->pbtStop->setEnabled(false);
    ui->pbtCapture->setEnabled(false);

    m_videoWidget = new QVideoWidget();
    QHBoxLayout *hLay = new QHBoxLayout;
    hLay->addWidget(m_videoWidget);
    ui->widget->setLayout(hLay);
}

void Widget::cameraDevicesSearch()
{
    ui->comboBox->clear();

    mCamList = QMediaDevices::videoInputs();
    foreach(const QCameraDevice &camDev, mCamList)
        ui->comboBox->addItem(camDev.description());
}

void Widget::viewCaptureImgDialog(const QImage &img)
{
    QDialog viewDialog(this, Qt::Dialog);
    viewDialog.setWindowTitle("Capture Image");

    QLabel doneLabel("");
    doneLabel.setPixmap(QPixmap::fromImage(img));

    QHBoxLayout lay;
    lay.addWidget(&doneLabel);

    viewDialog.setLayout(&lay);
    viewDialog.resize(img.size());
    viewDialog.exec();
}

void Widget::onStartBtn()
{
    m_audioInput.reset(new QAudioInput);
    m_captureSession.setAudioInput(m_audioInput.get());

    int currCamIndex = ui->comboBox->currentIndex();

    mCamera.reset(new QCamera(mCamList.at(currCamIndex)));
    connect(mCamera.data(), &QCamera::errorOccurred,
            this,           &Widget::camError);

    m_captureSession.setCamera(mCamera.data());
    m_captureSession.setVideoOutput(m_videoWidget);

    if (!m_imageCapture) {
        m_imageCapture.reset(new QImageCapture);
        m_captureSession.setImageCapture(m_imageCapture.get());

        connect(m_imageCapture.get(), &QImageCapture::imageCaptured,
                this,                 &Widget::imageCaptured);
    }

    mCamera->start();

    ui->pbtStart->setEnabled(false);
    ui->pbtStop->setEnabled(true);
    ui->pbtCapture->setEnabled(true);
}

void Widget::onStopBtn()
{
    mCamera->stop();
    m_videoWidget->clearMask();

    ui->pbtStart->setEnabled(true);
    ui->pbtStop->setEnabled(false);
    ui->pbtCapture->setEnabled(false);
}

void Widget::onCaptureBtn()
{
    m_imageCapture->capture();
}

void Widget::camError()
{
    if ( mCamera->error() != QCamera::NoError )
    {
        QMessageBox::warning(this,
                             tr("Camera Error"),
                             mCamera->errorString());
    }
}

void Widget::imageCaptured(int requestId, const QImage &img)
{
    QImage scaledImgImage =
        img.scaled(m_videoWidget->size(),
                   Qt::KeepAspectRatio,
                   Qt::SmoothTransformation);

    viewCaptureImgDialog(scaledImgImage);
}

Widget::~Widget()
{
    delete ui;
}

