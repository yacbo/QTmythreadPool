#include "controller.h"

Controller::Controller(QObject *parent)
{
   myThrd = new MyThread();
   connect(myThrd,&MyThread::mythread_signal,this,&Controller::handleResults);
   //该线程结束时销毁
   connect(myThrd,&QThread::finished,this,&QObject::deleteLater);
   connect(this,&Controller::operate,myThrd,&MyThread::mythread_slots);
   //启动该线程
   myThrd->start();
   QThread::sleep(5);
   emit operate(999);
}

Controller::~Controller()
{
    myThrd->quit();
    myThrd->wait();
}
