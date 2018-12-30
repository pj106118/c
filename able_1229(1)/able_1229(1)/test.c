//求第n个斐波那契数(不用递归的方法，用循环）
//来源于生兔子问题，一对兔子，在第三个月能够再生一对兔子，假设每次生的都是一对（一公一母），并且兔子不会死，请问第n个月一共有多少对兔子？（1,1,2,3,5,8,13.......)
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Fib(int n)
{
	if (n == 1 || n == 2)    //  |按位或，||逻辑或
	{
		return 1;
	}
	int last1 = 1;    //第i - 1项
	int last2 = 1;    //第i - 2项
	int cur = 0;       //第 i 项
	for (int i = 3; i <= n; ++i)
	{
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}
int main()
{
	int n;
	printf("请输入一个数字：\n");
	scanf("%d", &n);
	printf("%d \n", Fib(n));
	system("pause");
	return 0;
}