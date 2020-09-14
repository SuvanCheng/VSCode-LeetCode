#include <iostream>
#include <vector>
#include <string>
using namespace std;
void stringFilter(vector<char> &pInputStr, long lInputLen, vector<char> &pOutputStr);

int main()
{
    vector<char> pInStr;
    vector<char> pOutStr;
    string str;
    cin >> str;
    int n = str.length(); //获取输入的字符串长度

    const char *TempInStr = str.c_str(); //把string转换成char指针或者const char *TempInStr = str.data();
    for (int i = 0; i < n; i++)          //将输入的字符串赋给vector变量
    {
        pInStr.push_back(TempInStr[i]);
    }
    long length = pInStr.size();
    stringFilter(pInStr, length, pOutStr);

    for (vector<char>::size_type ix = 0; ix != pOutStr.size(); ++ix)
    { //输出结果
        cout << pOutStr[ix];
    }
    return 0;
}

void stringFilter(vector<char> &pInputStr, long lInputLen, vector<char> &pOutputStr)
{
    vector<char> pStrIn = pInputStr;
    long length = lInputLen;
    int a[128] = {0};

    if (pInputStr.empty() || lInputLen < 0)
        return;
    for (int i = 0; i < length; i++)
    {
        if (a[pStrIn[i]] == 0)
        {
            pOutputStr.push_back(pStrIn[i]);
        }
        a[pStrIn[i]]++;
    }
}