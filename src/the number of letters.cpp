#include <iostream>
#include <vector>
#include <string>
using namespace std;

int A[26]; //大写bai
int a[26]; //小写

int main()
{
    char n[10000]; //输入串
    cin >> n;
    for (int i = 0; n[i] != 0; i++)
    {
        if (n[i] >= 'a' && n[i] <= 'z')
            a[n[i] - 'a']++; //小写检测du
        else
            A[n[i] - 'A']++; //大写检测
    }

    for (int i = 0; i <= 26; i++)
        if (A[i] != 0)
            cout << char(i + 'A') << ' ' << A[i] << '\n';
    for (int i = 0; i <= 26; i++)
        if (a[i] != 0)
            cout << char(i + 'a') << ' ' << a[i] << '\n'; //输出
    return 0;
}
