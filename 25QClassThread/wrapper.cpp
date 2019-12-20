#include "wrapper.h"
#include <synchapi.h>
Wrapper::Wrapper()
{
}

void Wrapper::member1()
{
    int n = 0;
    while(n<10)
    {
        cout<<"member "<<n<<endl;
        n++;
        m_f(n); //调用回调方法
        SleeperThread::msleep(500); //
    }
}


std::thread Wrapper::member1_thread()
{
    return thread(&Wrapper::member1,this);
}

void Wrapper::member2(const char *arg1)
{
    std::cout<<arg1<<std::endl;
}

std::thread Wrapper::member2_thread(const char *arg1)
{
    return thread(&Wrapper::member2,this,arg1);
}
