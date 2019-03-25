#define _CRT_SECURE_NO_WARNINGS
#include<io.h>
#include<string>
#include<cstring>
#include<direct.h>
#include<fstream>
#include<iostream>
#include<io.h>
#include<string>
#include<cstring>
#include<direct.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <tchar.h>
#include "copydir.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Server is running!!!" << endl;
    #ifdef _WIN32
        string src = "D:\\a";
        string des = "C:";
        CopyDir cd;
        cd.copy(src, des);
    #else
        std::string src = "/media/myUbuntu/F/data/test";
        std::string des = "/media/myUbuntu/F/data/test2";
        CopyDir cd;
        cd.copy(src, des);
    #endif
    return 0;
}
