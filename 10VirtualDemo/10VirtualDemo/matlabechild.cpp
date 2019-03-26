#include "matlabechild.h"

MatlabeChild::MatlabeChild()
{

}

MatlabeChild::~MatlabeChild()
{

}

bool MatlabeChild::setMat()
{
    mp->getValue();
    std::cout<<"MatlabeChild......setMat"<<std::endl;
}

bool MatlabeChild::getMat()
{
    mp->getValue();
    std::cout<<"MatlabeChild......getMat"<<std::endl;
}

bool MatlabeChild::execMat()
{
    mp->getValue();
    std::cout<<"MatlabeChild......execMat"<<std::endl;
}
