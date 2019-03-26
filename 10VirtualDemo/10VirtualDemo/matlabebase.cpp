#include "matlabebase.h"

MatlabeBase::MatlabeBase()
{
    mp = MatlabeLoader::instance();
}

MatlabeBase::~MatlabeBase()
{
  delete mp;
}

bool MatlabeBase::getMat()
{
   std::cout<<"MatlabeWork......getMat()"<<std::endl;
   return true;
}

bool MatlabeBase::setMat()
{
    std::cout<<"MatlabeWork......getMat()"<<std::endl;
    return true;
}

bool MatlabeBase::execMat()
{
    std::cout<<"MatlabeWork......execMat()"<<std::endl;
    return true;
}
