#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include <QAudioFormat>
#include <QMediaPlayer>

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

    QString         m_fName;
    QMediaPlayer    *m_player;
    QAudioOutput    *m_audioOutput;
    qint64          m_duration;

private slots:
    void onOpenBtn();
    void onPlayBtn();
    void onPauseBtn();
    void onStopBtn();

    void sliderValueChange(int val);

    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);

    void seek(int seconds);
};
#endif // WIDGET_H
