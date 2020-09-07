#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Match2Vcetor(vector<int> v, vector<int> u)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < u.size(); j++)
		{
			if (v[i] == u[j])
			{
				return true;
				break;
			}
		}
	}
}

int main()
{
	int n, m, w, x; // n(1-100000) 总人数; m(1-500) 小团队数量; w(1-100) 小队人数; x 编号
	cin >> n >> m;
	vector<int> v, u(1, 0);
	vector<vector<int>> data(m);

	//存输入为N组数据 每组数据的个数不确定的情况
	for (int i = 0; i < m; i++)
	{
		cin >> w;
		for (int j = 0; j < w; j++)
		{
			cin >> x;
			data[i].push_back(x);
		}
	}

	//每一组都与其它比对，确定是否具有交集
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < m; ++i)
		{
			if (!data[i].empty() && Match2Vcetor(data[i], u)) //如果该团队不为空，且与 u 有交集
			{
				v.resize(data[i].size() + u.size());
				merge(data[i].begin(), data[i].end(), u.begin(), u.end(), v.begin()); //合并具有交集的团队
				sort(v.begin(), v.end());											  //排序合并后的交集
				vector<int>::iterator ite = unique(v.begin(), v.end());				  //迭代器
				v.erase(ite, v.end());												  //剔除重复项
				data[i].clear();													  //清空已经合并的团队
				u = v;
			}
		}
	}

	cout << "被通知的人：";
	for (int j = 0; j < v.size(); ++j)
	{
		cout << v[j] << " ";
	}
	cout << endl
		 << "通知的人数：" << v.size();

	return 0;
}

/*
data.in
10 3
2 0 1
5 6 5 3 2 7
2 6 1

data.out
7
*/