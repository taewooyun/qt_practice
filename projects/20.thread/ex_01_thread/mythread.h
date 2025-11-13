#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>
#include <QDateTime>

class MyThread : public QThread
{
    Q_OBJECT
    void run() override
    {
        m_threadStop = false;

        while(!m_threadStop)
        {
            QDateTime dt;
            QString str;

            m_mutex.lock();
            dt = QDateTime::currentDateTime();
            str = QString("Current time: %1")
                      .arg(dt.toString("hh:mm:ss"));

            m_mutex.unlock();

            emit logMessage(str);
            sleep(1);
        }
    }

signals:
    void logMessage(const QString &n);

public:
    MyThread();

    void stop() {
        m_threadStop = true;

    }

private:
    bool m_threadStop;

    QMutex m_mutex;
};

#endif // MYTHREAD_H
