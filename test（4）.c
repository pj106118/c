#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	printf("请输入一个数字：");
	scanf("%d", &i);
	if (i >= 65 && i <= 90)
		printf("%c\n", i + 32);
	if (i >= 97 && i <= 122)
		printf("%c\n", i - 32);
	system("pause");
	return 0;
}