#ifndef WRAPPER_H
#define WRAPPER_H

#include <thread>
#include <iostream>
#include <QThread>
#include <iostream>
#include <functional>

using namespace std;


typedef std::function<void(int)> Fun;  //定义函数指针 返回值为void，参数为int型
class Wrapper
{

    public:
        Wrapper();
    public:
        Fun m_f;

    public:
        void member1();
        std::thread member1_thread();
        void member2(const char *arg1);
        std::thread member2_thread(const char *arg1);
};


class SleeperThread : public QThread
{

    public:
        static void msleep(unsigned long msecs)
        {
            QThread::msleep(msecs);
        }
};



#endif // WRAPPER_H
