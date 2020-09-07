/*

有n首歌曲，歌曲时长不一（大于1分钟），现在要求播放t分钟，
但如果第t分钟结束后，歌曲并未放完，则继续放完为止，
现在歌曲的位置可以任意调整，请问最多能听多少分钟的歌曲？
1 <= n <= 1000; t = 100000

——————data.in——————
5
1 2 3 4 5
14

——————data.out——————
15

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, x, t, sum = 0; //n首音乐
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cin >> t;

	for (int i = 0; i < n; ++i)
	{
		if (t > v[i])
		{
			sum += v[i];
			t -= v[i];
		}
		else
		{
			sum += v[n-1];
		}
	}

	cout << sum; //输出

	return 0;
}
