#ifndef TESTTOOL_H
#define TESTTOOL_H


class Base
{
public:
    virtual void func1(int) = 0;
};

class Derived :public Base
{
public:
    void func1(int) override;
};

#endif // TESTTOOL_H
