/*
两个字符串S、T，相似度定义为即为S的字串,又为T的子序列的不同字符串数量（位置不同也算不同）。
字符串中任意个连续的字符组成的子序列又称为该串的子串。
子序列指序列的一部分按原有次序排列而得到的序列。
现在你需要求出他们的相似的是多少。

输入描述：
第一行两个空格分隔的正整数 n，m，分别代表S和T的长度。(1<=n, m<=5000)
第二行一个字符串S，保证只包含小写字母。
第三行一个字符串T，保证只包含小写字母。

输出描述：
仅一行一个正整数代表他们的相似度。

示例
2  4
ac
abca

输出
3
说明：a，c，ac均是S的子串，也是T的子序列。
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string src1, src2;
    cin >> src1 >> src2;  //data.in
    //先动态申请一个二维数组用来存储权值
    int **grid = new int *[src1.length() + 1]; //多申请一行（防止访问越界）
    for (size_t i = 0; i < src1.length() + 1; i++)
    {
        grid[i] = new int[src2.length() + 1];
    }
    //为了不影响正确的权值把多申请一行一列的权值赋值为0
    for (size_t i = 0; i < src1.length() + 1; i++)
    {
        grid[i][0] = 0;
    }
    for (size_t i = 0; i < src2.length() + 1; i++)
    {
        grid[0][i] = 0;
    }
    //开始计算权值
    for (size_t i = 1; i < src1.length() + 1; i++)
    {
        for (size_t j = 1; j < src2.length() + 1; j++)
        {
            //因为多申请了一行一列所以字符串要-1，否则访问越界
            if (src1.at(i - 1) == src2.at(j - 1))
            {
                //相同时，取左上角的权值+1
                grid[i][j] = grid[i - 1][j - 1] + 1;
            }
            else
            {
                //当不相同时，上边和左边的权值谁大就取谁
                if (grid[i - 1][j] > grid[i][j - 1])
                {
                    grid[i][j] = grid[i - 1][j];
                }
                else
                {
                    grid[i][j] = grid[i][j - 1];
                }
            }
        }
    }
    //因为我们在申请内存的时候多申请了一行，所以length不用减1

    int num = grid[src1.length()][src2.length()];
    int sum = 0;
    for (int i = 0; i <= num; i++)
        sum += i;

    cout << "相似度：" << sum << endl;
    return 0;
}