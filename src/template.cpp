#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef struct tagListNode{
    int data;
    struct tagListNode* next;
}ListNode, *List;

//自制轮子

int main()
{
    int minSize, maxSize, n, fishsize, count = 0;
    //单整数 输入
    cin >> minSize >> maxSize >> n;

    //多整数 输入
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    int num;
    cin >> num;
    int *arr = new int[n + 1];
    for (int i = 0; i <= num; i++)
    {
        cin >> arr[i];
    }

    //字符串输入
    string str1, str2;
    cin >> str1 >> str2;

    //输出
    cout << count;
    cout << (int)(count + 0.1) << " " << endl;

    for (int i = 0; i < vec.size(); ++i)
    {
        i == 0 ? cout << vec[i] : cout << " " << vec[i];
    }
    return 0;
}