#include <stdlib.h>
#include <cstring>
#include <string>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "comm.h"

#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef std::vector<int> IntVec;

//字符串"12 2 3564 124"转成整形数组
IntVec to_int_vec(const char* content)
{
    IntVec vec;
    std::string param;
    std::istringstream text(content);
    while (text >> param) {
        vec.push_back(std::stoul(param));
    }
    return vec;
}


int main(int argc, char *argv[])
{
    double mat[1][4] = {2.01,1.02,3.21,6.213 };
    double douArr[1][4]={0};
    memcpy(douArr,mat,1*4*sizeof(double));
    int intValue = (int)douArr[0][0];
     std::cout<<intValue<<std::endl;

    /*
        //枚举测试
        int a = 2;
        switch (a)
        {
            case monday:   //1
            {
                std::cout<<"monday"<<std::endl;
            }
                break;
            case tuesday:   //2
            {
                std::cout<<"tuesday"<<std::endl;
            }
                break;
            case wendsday:  //3
            {
                std::cout<<"wendsday"<<std::endl;
            }
                break;
        }
    */

    //通过该指令可以找到要执行的exe程序
    //ShellExecute(NULL, L"open", L"Notepad.exe", NULL, NULL, SW_SHOWNORMAL);
    //cout << "Hello World!" << endl;
    char arr[] = "0 1 3 5 71";
    IntVec aa = to_int_vec(arr);
    for(int num:aa)
    {
        num = num + 5;
        std::cout<<num<<"\t";
    }
    return 0;
}
