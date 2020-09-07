//标准库的string类提供了三个成员函数来从一个string得到c类型的字符数组
//主要介绍c_str
//c_str()：生成一个const char*指针，指向以空字符终止的数组。
//这个数组应该是string类内部的数组
#include <iostream>
//需要包含cstring的字符串
#include <cstring>
using namespace std;

int main()
{
    //string-->char*
    //c_str()函数返回一个指向正规C字符串的指针, 内容与本string串
    //这个数组的数据是临时的，当有一个改变这些数据的成员函数被调用后，其中的数据就会失效。
    //因此要么现用先转换，要么把它的数据复制到用户自己可以管理的内存中
    const char *c;
    string s = "1234";
    c = s.c_str();
    cout << c << endl;
    s = "abcde";
    cout << c << endl;
}