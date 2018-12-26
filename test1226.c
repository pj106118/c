//递归方式实现打印一个整数的每一位
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void stamp(int a)
{
	if (a > 9)
	{
		stamp( a / 10);
	}
	printf("%d ", a%10);

}

int main()
{
	int a = 0;
	printf("请输入一个数：");
	scanf("%d",&a);
	stamp(a);
	system("pause");
	return 0;
}