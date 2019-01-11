//第二种求平均值的方式 float  num = a+（b-a）/ 2.0
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void everage(int* a, int* b)
{
	float num = 0;
	num = *a + ( *b - *a ) / 2.0;
	printf("%f\n", num);
}

int main()
{
	int a = 0;
	int b = 0;
	printf("请输入两个数：\n");
	scanf("%d,%d", &a, &b);
	everage(&a, &b);
	system("pause");
	return 0;
}