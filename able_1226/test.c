//不用递归求n的阶乘
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	int i = 1;
	int sum = 1;
	printf("请输入要求的阶乘数：\n");
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		sum *= i;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}