#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

void rev(std::string &s, int n)
{
    if (s.empty() || n <= 1)
    {
        return;
    }
    auto left = s.begin();
    auto right = left;
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (right == s.end())
            {
                break;
            }
            right++;
        }
        reverse(left, right);
        left = right;
        if (right == s.end())
        {
            break;
        }
    }
};

int main()
{
    std::string s;
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::getline(std::cin, s, '\n');
    rev(s, n);
    std::cout << s;
}


/*
data.in
3
abcd efg h ijklmn;

data.out
cbae d gfi hlkj;nm
*/