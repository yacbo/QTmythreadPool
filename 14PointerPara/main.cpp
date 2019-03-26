#include <QCoreApplication>
#include <iostream>
#include <sstream>
#include "car.h"
#include "common.h"
#include <string>
#include <cstring>
using namespace std;
/*************函数指针 方式1*****************/
int add(int a,int b)
{
    return a+b;
}

typedef int(MyFuncType)(int a,int b);   //定义了一个函数指针类型

int MainOp(MyFuncType myadd)
{
    return myadd(8,9);
}
/**************函数指针 方式2*****************/
int MainOp2(int(MyFuncType2)(int a,int b))
{
    int c = MyFuncType2(5,6);
    return c;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int myInt = 100;
    int *p  = NULL;
    p = (int*)&myInt;
    *p=10;
    cout<<myInt<<endl;
    cout<<*p<<endl;

    /*********类相关回调的使用********/
    Engine *engine = NULL;
    Car *car = NULL;
    engine  = new Engine();
    car = new Car(engine);
    engine->m_f();

    MyFuncType *myPointerFunc = NULL;//定义函数指针
    myPointerFunc = &add;//函数指针赋值
    int value = myPointerFunc(5,6);//调用
    std::cout<<value<<std::endl;

    double d = 9.133;
    string strD = to_string(d);
    cout<<"d:"<<strD<<endl;//d:9.133000

    stringstream ss;
    ss<<"d:"<<d;
    cout<<ss.str()<<endl;//d:9.133
    ss.clear();
    ss.str("");

    //运用函数模板
    string result = "";
    Util::to_string(result,true);  //转成string
    cout<<"result:"<<result<<endl;

    char aa = Util::convert<char>("a165");   //转成int等基本类型
    cout<<"aInt:"<<aa<<endl;

    string strv = "12 56 34 564 213 ";
    vector<int> v = Util::convet_vecInt(strv);
    for(auto i : v)
    {
        cout<<i<<endl;
    }

    return a.exec();
}
