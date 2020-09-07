#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    char a = 321;
    cout << (int)a;
    cout << endl;
}

/*
在C/C++中，将一个超出某类型范围的整数赋给这个类型的变量时，将自dao动从右端开始截取这个变量能承载的长度赋值。
比如，char a=321; 执行后a值是65。
因为a的取值范围是-128~127，321(101000001)被从右端起截取了8位(1字节)赋给了a，而01000001刚好是十进制数65。
*/