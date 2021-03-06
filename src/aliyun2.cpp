/*
在一个出错率很高的信息传输系统中，传送m位的二进制字符串。现在接收方得到了n个字符串，
以及每个字符串正确的位数，请问发送方的原始的字符串信息有多少可能？若结果唯一，则求出原始字符串。

输入描述：
第一行两个数字，n为接收方得到的字符串个数，m为字符串长度；
接下来n行，每行一个长度为 m 的仅含0和1的字符串，空格后一个单独数字 c 表示正确的位数(0<=c<=m).

输出描述：
若结果不唯一，一行一个数字表示可能的结果数；
若结果唯一，一行长度为m的字符串表示结果。

示例：
输入
3 5
01101 4
10100 3
00011 3

输出
00101
说明：结果唯一为 00101
*/