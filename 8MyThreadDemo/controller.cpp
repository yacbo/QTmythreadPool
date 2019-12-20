#include "controller.h"

Controller::Controller(QObject *parent)
{
   pMyThread = new MyThread();
   connect(pMyThread,&MyThread::mythread_signal,this,&Controller::handleResults);

   //该线程结束时销毁
   connect(pMyThread,&QThread::finished,this,&QObject::deleteLater);
   connect(this,&Controller::operate,pMyThread,&MyThread::mythread_slots);

   //启动该线程
   pMyThread->start();
   QThread::sleep(5);
   emit operate(999);
}

Controller::~Controller()
{
    pMyThread->quit();
    pMyThread->wait();
}
