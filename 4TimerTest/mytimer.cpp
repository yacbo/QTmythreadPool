#include "mytimer.h"
#include<QDebug>
#include <QTimer>
#include <thread>
#include "threadsafe_queue.h"

#define TIMER_TIMEOUT   (1*1000)

MyQueueNameSpace::threadsafe_queue<std::string> qe;

MyTimer::MyTimer(QObject *parent)
    :QObject(parent)
{
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handle_timeout()));
    m_pTimer->start(TIMER_TIMEOUT);
}

MyTimer::~MyTimer()
{
  if(m_pTimer)
  {
      delete m_pTimer;
      m_pTimer = nullptr;
  }
}

void thread_function()
{
    qDebug() << "Enter timeout processing function.\n";
    std::string str = "";
    if(qe.try_pop(str))
        qDebug() << str.data();
//    if(m_pTimer->isActive()){
//        m_pTimer->stop();
//    }
}


void MyTimer::handle_timeout()
{
    std::thread threadObj1(thread_function);
    threadObj1.detach();
//    qDebug() << "Enter timeout processing function.\n";
//    std::string str = "";
//    if(qe.try_pop(str))
//        qDebug() << str.data();
//    if(m_pTimer->isActive()){
//        m_pTimer->stop();
//    }
}
