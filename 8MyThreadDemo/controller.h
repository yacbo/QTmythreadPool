#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mythread.h"
#include <QObject>

class Controller :public QObject
{
        Q_OBJECT
    public:
        Controller(QObject* parent = nullptr);
        ~Controller();
    public slots:
        void handleResults(const int rslt)//处理线程执行的结果
        {
            qDebug()<<"receive the resultReady signal----";
            qDebug()<<"current thread ID:"<<QThread::currentThreadId()<<'\n';
            qDebug()<<"the last result is:"<<rslt<<'\n';
        }
    signals:
        void operate(const int);//发送信号触发线程
    private:
        MyThread *pMyThread;
};

#endif // CONTROLLER_H
