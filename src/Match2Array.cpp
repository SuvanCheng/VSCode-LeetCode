#include <iostream>
#include <vector>

using namespace std;

int Match2Array(const int *pArray1, int iSize1, const int *pArray2, int iSize2)
{
    const int *piFirEnd = pArray1 + iSize1, *piSecEnd = pArray2 + iSize2;
    int iRet = 0;

    while (pArray1 < piFirEnd && pArray2 < piSecEnd)
    {
        if (*pArray1 == *pArray2)
        {

            pArray1++;
            pArray2++;
            iRet++;
        }
        else if (*pArray1 < *pArray2)
        {
            pArray1++;
        }
        else
        {
            pArray2++;
        }
    }

    return iRet;
}

int main()
{
    int n, p, q, x, e; //
    vector<int> a, b;  //
    cin >> n;          //一共有的土地
    cin >> p;          //a想要的土地
    cin >> q;          //b想要的土地

    int aa[p], bb[q]; //第二行数组aa，第三行数组bb

    for (int i = 0; i < p; ++i) //存为 vector a
    {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < q; ++i) //存为 vector b
    {
        cin >> x;
        b.push_back(x);
    }

    for (int i = 0; i < p; ++i) //转为 array aa
    {
        aa[i] = a[i];
    }

    for (int i = 0; i < q; ++i) //转为 array bb
    {
        bb[i] = b[i];
    }

    e = Match2Array(aa, p, bb, q);             // 求 aa bb 中相同元素的个数
    cout << p - e << " " << q - e << " " << e; //输出

    cout << endl;
}
