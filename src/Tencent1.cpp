/*打印两个链表的公共部分
	方法：
	指针分别指向两个链表的首部，谁小谁移动到下一个，如果相同那么打印并且两个指针都移动*/
#include <iostream>

#include <list> 
using namespace std;
 
 

//创建一个list容器的实例LISTINT 
typedef list<int> LISTINT; 
//创建一个list容器的实例LISTCHAR 
typedef list<int> LISTCHAR;


int* GetCommonFromTwoList(Linklist L1, int n1, Linklist L2, int n2)
{
	Linklist node1 = L1;
	Linklist node2 = L2;
 
	int n = n1 > n2 ? n1 : n2;
	int *p = new int[n];
	int i = 0;
	for (int i = 0; i < n; ++i)
	{
		p[i++] = node1.value == node2.value ? ((node1++).value + (node2++).value) >> 2 : node1.value < node2.value ? (node2++).value : (node1++).value;
	
	}
 
	return *p;
}
 
int main(int argc, char const *argv[])
{
    int a , b;
    cin >> a >> b;
    
	/* code */
	return 0;
}