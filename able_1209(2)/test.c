#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Isleap(int a)
{
	
	if (a % 4 != 0)
		return -1;
	else
		if (a % 100 != 0)
			return 1;
		else
		{
			if (a % 400 == 0)
				return 1;
			else
				return -1;
		}
	
}
void main()
{
	int a;
	printf("请输入一个数字:");
	scanf("%d", &a);
	int temp = Isleap(a);
	if (temp == 1)
		printf("是闰年！");
	if (temp == -1)
		printf("不是闰年！");
	system("pause");
}