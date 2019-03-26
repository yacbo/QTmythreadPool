#ifndef MATLABELOADER_H
#define MATLABELOADER_H
#include <iostream>
using namespace std;

class MatlabeLoader
{
    private:
        MatlabeLoader();
    public:
        ~MatlabeLoader();
    public:
        static MatlabeLoader* instance();
    public:
        void getValue();
};

#endif // MATLABELOADER_H
