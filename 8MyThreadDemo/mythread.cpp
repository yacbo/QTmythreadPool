#include "mythread.h"

MyThread::MyThread(QObject *parent)
{

}

void MyThread::run()
{
    qDebug()<<"myThread run() start to execute";
    qDebug()<<"current thread ID:"<<QThread::currentThreadId()<<'\n';
    //循环一千次
    int count = 0;
    for(int i = 0;i!=1000;++i)
    {
     ++count;
    }
    //发送结束信号
    emit mythread_signal(count);
    exec();
}

void MyThread::mythread_slots(const int val)
{
    qDebug()<<"myThreadSlot() start to execute";
    qDebug()<<"current thread ID:"<<QThread::currentThreadId()<<'\n';
    //循环一千次
    int count = 2000;
    for(int i = 0;i!=1000;++i)
    {
     ++count;
    }
    emit mythread_signal(count);
}
