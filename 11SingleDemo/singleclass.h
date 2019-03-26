#ifndef SINGLECLASS_H
#define SINGLECLASS_H
#include <iostream>
using namespace std;
class SingleClass
{
private:
   SingleClass();

public :
   static SingleClass *get_instace();

};


//类模板
template <typename T>
class Complex{
public:
    Complex(T a,T b)  //构造函数
    {
        this->a = a;
        this->b = b;
    }

    Complex<T> operator+(Complex &c)  //运算符重载
    {
        Complex<T> tmp(this->a+c.a,this->b+c.b);
        return tmp;
    }

private:
    T a;
    T b;
};



/*适配器模式*/
class Current18v
{
public:
    virtual void useCurrent18v() = 0;
};

class Current220v
{
public:
    void useCurrent220v()
    {
        std::cout << "220v,欢迎使用." << std::endl;
    }
};

class Adapter : public Current18v
{
public:
    Adapter(Current220v* current)
    {
        m_current = current;
    }

    virtual void useCurrent18v()
    {
        m_current->useCurrent220v();
    }
private:
    Current220v *m_current;
};

/*装饰者模式*/
class Car
{
public:
    virtual void show() = 0;
};

class RunCar : public Car
{
public:
    virtual void show()
    {
        cout<<"可以跑."<<endl;
    }
};

class SwimCarDirector : public Car
{
public:
    SwimCarDirector(Car *car)
    {
        m_car = car;
    }

    void swim()
    {
        cout<<"可以游泳"<<endl;
    }

    virtual void show()
    {
        m_car->show();
        swim();
    }
private:
    Car *m_car;
};


class FlyCarDirector : public Car
{
public:
    FlyCarDirector(Car *car)
    {
        m_car = car;
    }
    void fly()
    {
        cout<<"可以飞"<<endl;
    }
    virtual void show()
    {
        m_car->show();
        fly();
    }
private:
    Car *m_car;
};

/*函数模板*/
template <typename T>
void myswap(T&a,T&b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

#endif // SINGLECLASS_H
