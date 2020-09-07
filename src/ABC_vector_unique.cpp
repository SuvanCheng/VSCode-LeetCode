/*
题目标题：
将两个整型数组按照升序合并，并且过滤掉重复数组元素

详细描述：
原型：voidCombineBySort(int* pArray1,intiArray1Num,int* pArray2,intiArray2Num,int* pOutputArray,int* iOutputNum);

输入参数：

    int* pArray1 ：整型数组1

    intiArray1Num：数组1元素个数

    int* pArray2 ：整型数组2

    intiArray2Num：数组2元素个数

输出参数（指针指向的内存区域保证有效）：

    int* pOutputArray：合并后的数组

    int* iOutputNum：合并后数组元素个数

返回值：
    void
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num1, num2, i, con;
    vector<int> vec;
    cin >> num1;
    for (i = 0; i < num1; i++)
    {
        cin >> con;
        vec.push_back(con);
    }
    cin >> num2;
    for (i = 0; i < num2; i++)
    {
        cin >> con;
        vec.push_back(con);
    }
    sort(vec.begin(), vec.end());
    //unique返回值是重复元素的开始位置。
    //如果vector中存储的元素是自定义的结构或者是类，那么就需要重载操作符。
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}