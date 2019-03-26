#ifndef MATLABECHILD_H
#define MATLABECHILD_H
#include "matlabebase.h"

class MatlabeChild : public MatlabeBase
{
public:
    MatlabeChild();
    ~MatlabeChild();
public:
    virtual bool setMat();
    virtual bool getMat();
    virtual bool execMat();
};

#endif // MATLABECHILD_H
