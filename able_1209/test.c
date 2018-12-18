#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n = 0;
	printf("请输入一个数:");
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1;j <= n; ++j)
		{
			int sum = i * j;
			printf("%d*%d=%d\t",i,j,sum);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}