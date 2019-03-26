#ifndef CAR_H
#define CAR_H
#include "engine.h"
#include <iostream>

class Car
{
public:
    Car(Engine *engine);

public:
    static void show_info();

public:
    Engine *m_Engine;
};

#endif // CAR_H
