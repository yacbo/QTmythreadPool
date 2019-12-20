#include "controller.h"
#include <worker.h>

Controller::Controller(QObject *parent) : QObject(parent)
{
    Worker *worker = new Worker;
    //调用moveToThread将该任务交给workThread
    worker->moveToThread(&thread);
    //operate信号发射后启动线程工作
    connect(this, SIGNAL(operate(const int)), worker, SLOT(doWork(int)));
    //该线程结束时销毁
    connect(&thread, &QThread::finished, worker, &QObject::deleteLater);
    //线程结束后发送信号，对结果进行处理
    connect(worker, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
    //启动线程
    thread.start();
    //发射信号，开始执行
    qDebug()<<"emit the signal to execute!---------------------------------";
    qDebug()<<"current thread ID:"<<QThread::currentThreadId()<<'\n';
    emit operate(10);
}
//析构函数中调用quit()函数结束线程
Controller::~Controller()
{
    thread.quit();
    thread.wait();
}
