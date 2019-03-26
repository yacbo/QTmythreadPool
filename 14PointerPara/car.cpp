#include "car.h"

Car::Car(Engine *engine)
{
    m_Engine = engine;
    m_Engine->setfunc(&Car::show_info);
}


void Car::show_info()
{
   std::cout<<"this is my first car."<<std::endl;
}


