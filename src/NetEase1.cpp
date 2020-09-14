#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<char> pInStr;
    string str;
    cin >> str;

    const char *TempInStr = str.c_str();   //把string转换成char指针或者const char *TempInStr = str.data();
    for (int i = 0; i < str.length(); i++) //将输入的字符串赋给vector变量
    {
        pInStr.push_back(TempInStr[i]);
    }

    long length = pInStr.size();
    long llength = pInStr.size();

    for (int j = 0; j < llength; ++j)
    {
        int a[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //小写
        for (int i = 0; i < pInStr.size(); ++i)
        {
            if (pInStr[i] >= 'a' && pInStr[i] <= 'z')
                a[pInStr[i] - 'a']++;
        }
        if ((a[0] % 2 == 0) &&
            (a[1] % 2 == 0) &&
            (a[2] % 2 == 0) &&
            (a[23] % 2 == 0) &&
            (a[24] % 2 == 0) &&
            (a[25] % 2 == 0))
        {
            cout << pInStr.size();
            break;
        }
        pInStr.pop_back();
    }

    return 0;
}


/*
data.in
amacd

data.out
3
*/