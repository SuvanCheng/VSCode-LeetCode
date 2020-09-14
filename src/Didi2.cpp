#include "iostream"
#include "cstring"
#include "cstdio"

using namespace std;
#define INF 0x7f7f7f7f

const int N = 105; //点的个数上限

int maze[N][N];
int dis[N];
bool vis[N];

//点的个数和边的条数
int n, m;

void init()
{
    memset(maze, INF, sizeof(maze));
    memset(dis, INF, sizeof(dis));
    memset(vis, false, sizeof(vis));
}

void dijkstra(int st)
{
    dis[st] = 0;
    for (int i = 1; i <= n; i++)
    {
        //找到和起点距离最短的点
        int minx = INF;
        int minmark;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == false && dis[j] <= minx)
            {
                minx = dis[j];
                minmark = j;
            }
        }
        //并标记
        vis[minmark] = true;
        //更新所有和它连接的点的距离
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == false && dis[j] > dis[minmark] + maze[minmark][j])
                dis[j] = dis[minmark] + maze[minmark][j];
        }
    }
}

int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        //每组数据都要初始化
        init();
        for (int i = 1; i <= m; i++)
        {
            int x, y, len;
            scanf("%d %d %d", &x, &y, &len);
            if (x != y && maze[x][y] > len)
            {
                maze[y][x] = len;
                maze[x][y] = len;
            }
        }
        //以1为起点跑一次dij
        int i, j, month, day, hour;

        //输入出发地点i、目的地j、出发时间M.D/H
        scanf("%d %d %d.%d/%d", &i, &j, &month, &day, &hour);

        //对出发地点进行dijkstra求算
        dijkstra(i);

        //输出到n的距离
        printf("%d\n", dis[j]);
        hour += dis[j];
        day += hour / 24;
        hour %= 24;
        month += day / 31;
        day %= 31;
        printf("%d.%d/%d", month, day, hour);
    }
}

/*
data.in
4 4
1 2 25
1 3 18
2 4 28
3 4 22
1 4 7.9/8

data.out
40
7.11/0
*/