//求平均值的第三种方式
#include<stdio.h>
#include<stdlib.h>

void everage(int a, int b)
{
	int num = 0;
    num = ( a & b)+ ((a^b) >> 1),
	printf("%d\n", num);
}

int main()
{
	int a = 7;
	int b = 9;
	everage(a, b);
	system("pause");
	return 0;
}