#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, p, q, x, e;          //
    cin >> n >> p >> q;         //b想要的土地
    vector<int> a, b;           //
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

    for (int i = 0; i < b.size(); ++i)
    {
        i == 0 ? cout << b[i] : cout << " " << b[i];
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                ++e;
                cout << a[i] << " ";
                break;
            }
        }
    }
    cout << endl;
    cout << p - e << " " << q - e << " " << e; //输出

    cout << endl;
}
