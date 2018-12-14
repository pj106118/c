#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int to_find = 5;                   //to_find是需要寻找的数字
	int n = sizeof(a)/sizeof a[0];    //n代表总个数
	int left = 0;
	int right = n-1;                 //left和right代表的都是数组的下标
	while (1)
	{
		if (to_find > a[(left+right)/2]) //如果寻找的值比中间的值大，就把中间值的下标赋给左边
		{
			left = (left + right) / 2 +1;
		}
		else if (to_find < a[(left + right) / 2]) ////如果寻找的值比中间的值大，就把中间值的下标赋给右边
		{
			right = (left + right) / 2 - 1;
		}
		else
			break;
	}
	printf("%d\n", (left + right) / 2);
	system("pause");
	return 0;
}