#ifndef ENGINE_H
#define ENGINE_H

typedef void(*Func)();
class Engine
{
public:
    Engine();
public:
    void setfunc(Func f);
public:
    Func m_f;
};

#endif // ENGINE_H
