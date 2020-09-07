#include "stdlib.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void inputVector(int n)
{
    cin >> n;
    vector<int> nums;
    int temp_num;
    for (int i = 0; i < n; i++)
    {
        cin >> temp_num;
        nums.push_back(temp_num);
    }
}

void DDimVector(int m, int n)
{
    cin >> m >> n;

    //注意下面这一行：vector <int后两个 "> "之间要有空格！否则会被认为是重载 "> > "。
    vector<vector<int>> p(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << p[i][j] << " ";
        cout << endl;
    }
}

vector<vector<int>> DDimVectorPlus(int rows)
{
    vector<vector<int>> data(rows);

    int temp = 0;
    for (int i = 0; i < rows; i++)
    {
        while (cin >> temp)
        {
            data[i].push_back(temp);
            if (getchar() == '\n')
                break;
        }
    }
    return data;
}

void inputStr()
{
    char str[30];
    cin >> str;
    for (int i = 0; i < 5; i++)
    {
        cout << str[i];
    }
}

void inputStrPlus(int len)
{
    char str[30];
    cin.getline(str, len); //读入整行数据，它使用回车键输入的换行符来确定输入结尾。
    //cin.get(str,len);//这个还会保留换行符
}

void inputStrSustain()
{
    string str;
    //getline(cin, str);
}

int main()
{
    //一维数组输入
    //二维数组输入
    //字符串输入(不带空格)
    //字符串输入(带空格)

    int n, m;
    cin >> n >> m;
    vector<vector<int>> data;
    data = DDimVectorPlus(m);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < data[i].size(); ++j)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}