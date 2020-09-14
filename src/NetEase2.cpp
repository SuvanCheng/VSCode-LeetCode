#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> nums;
    int temp_num;

    while (1)
    {
        cin >> temp_num;
        nums.push_back(temp_num); //每输入一个数字就把它添加到数组的最后
        if (cin.get() == '\n')   //如果是回车符则跳出循环
            break;
    }

    vector<int> res(7, 0);

    for (auto num : nums)
    {
        vector<int> cur = res;
        for (auto i : cur)
        {
            res[(i + num) % 7] = max(res[(i + num) % 7], num + i);
        }
    }
    cout << res[0];
    return 0;
}