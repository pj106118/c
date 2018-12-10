#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void main()
{
	int i, j, n;
	printf("请输入一个数字");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 2 * i - 1; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = n - 1; i >= 0; i--)
	{
		for (j = 2 * i - 1; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
}