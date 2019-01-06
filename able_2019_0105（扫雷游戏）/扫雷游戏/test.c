//扫雷游戏

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define COLS 11         //列数
#define ROWS 11         //行数
#define COL (COLS-2)
#define ROW (ROWS-2) 
#define MAX 10         //雷的个数

void menu()
{
	printf("*********************************\n");
	printf("*********1.开始游戏**************\n");
	printf("*********2.结束游戏**************\n");
	printf("*********************************\n");
}


void init_board(char mine[ROWS][COLS], char set, int row, int col)//初始化棋盘函数为set
{
	memset(mine, set, row*col * sizeof(mine[0][0])); //memset本身就有初始化功能 括号内容依次为：
}	                                              //数组名，初始化目标，总共初始化字节

void set_mine(char mine[ROWS][COLS])//随机布雷函数
{
	int count = MAX;//设置计数器，记录要布入雷的个数
	while (count>0)
	{
		int x = rand() % 9 + 1;     //产生1到9的随机数字
		int y = rand() % 9 + 1;
		if ((mine[x][y]) == '0')     //判断同一位置是否重复布雷
		{
			mine[x][y] = '1';
			count--;      //每成功布雷一颗，计数器就减一
		}
	}
}

void display(char mine[ROWS][COLS], int row, int col)     //打印棋盘函数
{
	int i = 0;
	int j = 0;
	printf("  ");       //两个空格，为了使对齐，一个留给列号，一个留给棋盘
	for (i = 1; i <= row - 2; i++)         //打印列号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row - 2; i++)      //输出的是棋盘信息
	{
		printf("%d ", i);
		for (j = 1; j <= col - 2; j++)
		{
			printf("%c ", mine[i][j]);//
		}
		printf("\n");
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)  //统计坐标周围雷数目的函数
{
	return mine[x - 1][y - 1]
		+ mine[x][y - 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1]
		+ mine[x][y + 1] + mine[x - 1][y + 1]
		+ mine[x - 1][y] - 8 * '0';  //由于数组中存放的是字符'0',周围是8个数字，
	                                 //所以-8*'0'才能返回雷数的int值
}

enum Option //枚举，增加代码可读性
{
	EXIT,  //默认为0
	PLAY   //为1
};

void game()
{
	char mine[ROWS][COLS] = { 0 };//非雷的位置可初始化为零
	char show[ROWS][COLS] = { 0 };//创建一个和mine一样大的数组来存放，坐标周围雷的数目
	int x = 0;
	int y = 0;
	int win = 0;
	init_board(mine, '0', ROWS, COLS);//初始化数组,各位置放零
	init_board(show, '*', ROWS, COLS);//初始化数组，各位置放*

	set_mine(mine);//布雷
	display(show, ROWS, COLS);//打印棋盘
	while (win<(ROW*COL - MAX)) //非雷的个数
	{
		printf("请输入排查坐标：>");
		scanf("%d%d", &x, &y);
		system("cls");
		if (((x >= 1) && (x <= ROWS - 2)) && ((y >= 1) && (y <= COLS - 2)))//判断输入坐标是否在棋盘内
		{
			if (mine[x][y] == '1')
			{
				printf("很不幸，踩到地雷\n");
				break;
			}
			else    //每进入一次意味着排完一颗雷
			{

				int count = get_mine_count(mine, x, y);//通过此函数统计指定坐标周围有几个雷
				show[x][y] = count + '0';//为了打印*，所以把display函数打印的类型改为%c打印出来的是字符。-
				win++;
				display(show, ROWS, COLS);//-为了把数字也能打印出来，所以+'0',否则打印的是数字作为的ASCLL码的值
			}
		}
		else
		{
			printf("坐标输入有误\n");

		}
	}
	if (win == ROW*COL - MAX)
	{
		printf("恭喜你，排雷成功\n");
	}
	printf("雷阵如下\n");
	display(mine, ROWS, COLS);//为了在游戏结束后显示雷阵
}

void test()//为使主函数清洁，将使打印菜单指令置于此
{
	int input = 0;
	srand((unsigned int)time(NULL));//unsigned作为返回值的强制类型转换，如果NULL处不是空指针
									//而是某个地址，会将返回值所携带的信息往所指向内容中存一份
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);
}

int main()
{
	test();

	system("pause");
	return 0;
}