#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QObject>
#include <QDebug>
class MyThread : public QThread
{
        Q_OBJECT
    public:
        MyThread(QObject* parent = nullptr);
        //自定义发送的信号
    signals:
        void mythread_signal(const int);
        //自定义槽
    public slots:
        void mythread_slots(const int);
    protected:
        void run() override;
};

#endif // MYTHREAD_H
