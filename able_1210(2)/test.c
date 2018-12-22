#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int Isprime()
{
	int j, t, n;
	printf("请输入一个数：\n");
	scanf("%d", &n);                   //输入一个数判断是否是素数
	t = sqrt(n);
	for (j = 2; j <= t; j++)
		if (n%j == 0)
			break;
	if (j > t)
		return 1;
	else
		return -1;
}
int main()
{
	int num = Isprime();
	if (num == 1)
		printf("您输入的是素数！");
	else
		printf("您输入的不是素数！");
	system("pause");
	return 0;
}
