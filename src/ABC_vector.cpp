#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void printVector(const vector<int> &v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}
int main()
{
    //1、merge
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 4, 5, 6, 7};
    vector<int> v3;
    v3.resize(v1.size() + v2.size()); //合并前需要准备空间
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    printVector(v3); //1 1 2 3 4 4 5 5 6 7

    vector<int> v4; //使用back_inserter不用提前准备空间
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));

    printVector(v4); //1 1 2 3 4 4 5 5 6 7
    //2、insert
    v2.insert(v2.end(), v1.begin(), v1.end());
    printVector(v2); //1 4 5 6 7 1 2 3 4 5

    return 0;
}
