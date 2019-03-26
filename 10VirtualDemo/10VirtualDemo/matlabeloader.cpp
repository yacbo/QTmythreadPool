#include "matlabeloader.h"


MatlabeLoader::MatlabeLoader()
{
    std::cout<<"MatlabeLoader......"<<std::endl;
}

MatlabeLoader::~MatlabeLoader()
{
    std::cout<<"~MatlabeLoader......"<<std::endl;
}

MatlabeLoader* MatlabeLoader::instance()
{
    static MatlabeLoader a;
    return &a;
}

void MatlabeLoader::getValue()
{
   std::cout<<"matlab......getValue()"<<std::endl;
}
