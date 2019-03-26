#include <QCoreApplication>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <stdint.h>   //包含有uint、uchar等
#include <queue>
#include <fstream>
#include <set>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    set<int,greater<int>> s;
    s.insert(15);
    s.insert(18);
    s.insert(25);
    s.insert(35);
    s.insert(10);
    s.insert(10);
    s.insert(8);
    s.insert(9);
    set<int>::iterator it = s.begin();
    while(s.end() != it)
    {
        std::cout<<*it<<std::endl;
        it++;
    }

    return a.exec();
}
