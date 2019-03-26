#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
namespace Util {

    template<class T>
    void to_string(string &result, const T &t)
    {
        ostringstream oss;  //创建一个流
        oss << t;  //把值传递入流中
        result = oss.str();  //获取转换后的字符并将其写入result
    }

//可以更进一步定义一个通用的转换模板，用于任意类型之间的转换。
//函数模板convert()含有两个模板参数out_type和in_value，功能是将in_value值转换成out_type类型：
    template<class out_type, class in_value>
    out_type convert(const in_value & t)
    {
        stringstream stream;
        stream << t;  //向流中传值
        out_type result;  //这里存储转换结果
        stream >> result;  //向result中写入值
        return result;
    }

    vector<int> convet_vecInt(const string str)
    {
        vector<int> v;stringstream ss;ss<<str;
        while(1)
        {
            int a;ss>>a;
            if(ss.fail())
                break;
            v.push_back(a);
        }
        return v;
    }
}


#endif // COMMON_H
