#include "singleclass.h"

SingleClass::SingleClass()
{

}

SingleClass * SingleClass::get_instace()
{
    static SingleClass single;
    return &single;
}
