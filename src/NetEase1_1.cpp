#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int result = 0;
    int vowelInfo = 0;
    int stringIndexOfInfo[32];
    for (int i = 0; i < sizeof(stringIndexOfInfo) / sizeof(int); ++i)
    {
        stringIndexOfInfo[i] = -2;
    }
    stringIndexOfInfo[0] = -1;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case 'a':
        {
            vowelInfo ^= 1;
            break;
        }
        case 'b':
        {
            vowelInfo ^= 2;
            break;
        }
        case 'c':
        {
            vowelInfo ^= 4;
            break;
        }
        case 'x':
        {
            vowelInfo ^= 8;
            break;
        }
        case 'y':
        {
            vowelInfo ^= 16;
            break;
        }
        case 'z':
        {
            vowelInfo ^= 32;
            break;
        }
        default:
            break;
        }
        if (stringIndexOfInfo[vowelInfo] == -2)
        {
            stringIndexOfInfo[vowelInfo] = i;
        }
        else if (i - stringIndexOfInfo[vowelInfo] > result)
        {
            result = i - stringIndexOfInfo[vowelInfo];
        }
    }
    cout << result;
    return 0;
}