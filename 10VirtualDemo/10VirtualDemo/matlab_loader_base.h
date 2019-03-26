#ifndef MATLAB_LOADER_BASE_H
#define MATLAB_LOADER_BASE_H


class Matlab_Loader_base
{
public:
    Matlab_Loader_base();
    ~Matlab_Loader_base();
public:
    virtual bool setMat();
    virtual bool getMat();
    virtual bool execMat();

public:
    MatlabeLoader* mp;
};

#endif // MATLAB_LOADER_BASE_H
