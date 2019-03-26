#ifndef MATLABEWORK_H
#define MATLABEWORK_H
#include "matlabeloader.h"

class MatlabeBase
{
public:
    MatlabeBase();
    ~MatlabeBase();
public:
    virtual bool setMat();
    virtual bool getMat();
    virtual bool execMat();

public:
    MatlabeLoader* mp;
};

#endif // MATLABEWORK_H
