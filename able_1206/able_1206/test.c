#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int Menu()
{
printf("*********************\n");
printf("1.开始游戏\n");
printf("2.结束游戏\n");
printf("*********************\n");
printf("请输入您的选择:\n");
int a = 0;
scanf("%d", &a);
return a;
}                            //猜数字游戏的菜单

void game()
{
	
	int v = rand() % 100;   //使电脑生成的随机数在0到99之间
	while (1)
	{
		printf("请输入一个数字(0-99):\n");
		int b = 0;
		scanf("%d", &b);
		if (b < v)              //对电脑生成的随机数与用户输入的数字进行比较
		{
			printf("低了！");
		}
		else if (b > v)
		{
			printf("高了！");
		}
		else
		{
			printf("猜对了！");
			break;
		}
	}
}
void main()
{
	srand(time(0));
	int a = Menu();	
	while (1)
	{
		if (a == 1)
		{                      //开始游戏
			game();
			break;
		}
		else if (a == 2)
		{            //游戏结束
			printf("游戏结束！");
			break;
		}
		else
		{
			printf("输入错误！");
			break;
		}
	}
	system("pause");
}