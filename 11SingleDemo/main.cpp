#include <QCoreApplication>
#include "singleclass.h"
#include "QDebug"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SingleClass* p1 = SingleClass::get_instace();
    SingleClass* p2 = SingleClass::get_instace();
    if(p1 = p2)
    {
        qDebug()<<"p1=p2";
    }

    /*读取文件*/
    char buf[256];
    ifstream ifs("E:/QtProject/QTmythreadPool/11SingleDemo/1.txt");
    while (!ifs.eof()) {
        ifs.getline(buf,256,'\n');
        qDebug()<<buf;
    }
    ifs.close();
    //system("pause");

    return a.exec();
}
