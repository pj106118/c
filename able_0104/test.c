//三子棋游戏
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

char arr[ROW][COL];

int IsFull()
{
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)
		{
			if (arr[row][col] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

void Init()
{
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)
		{
			arr[row][col] = ' ';
		}
	}
}

void print()
{
	for (int row = 0; row < ROW; ++row)
	{
		printf("| %c | %c | %c |\n", arr[row][0], arr[row][1], arr[row][2]);
		if (row != ROW - 1)
		{
			printf("|---|---|---|\n");
		}
	}
}

void playermove()
{
	printf("玩家落子！\n");
	while (1)
	{
		printf("请输入一组坐标(row col):\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row,&col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("坐标非法，请重新输入！\n");
			continue;
		}
		if (arr[row][col] != ' ')
		{
			printf("当前位置已经有子，请重新输入！");
			continue;
		}
		arr[row][col] = 'x';
		break;
	}

}

char checkwinner()
{
	//行
	for (int row = 0; row < ROW; ++row)
	{
		if (arr[row][0] == arr[row][1] && arr[row][1] == arr[row][2] && arr[row][0] != ' ')
		{
			return arr[row][0];
		}
	}
	//列
	for (int col = 0; col < COL; ++col)
	{
		if (arr[0][col] == arr[1][col] && arr[1][col] == arr[2][col] && arr[0][col] != ' ')
		{
			return arr[0][col];
		}
	}
	//对角
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
	{
		return arr[0][0];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
	{
		return arr[0][2];
	}
	if (IsFull())
	{
		return 'q';
	}
	return ' ';
}

void computermove()
{
	printf("电脑落子！\n");
	while (1)
	{
		int row = rand() % ROW;
		int col = rand() % COL;
		if (arr[row][col] != ' ')
		{
			continue;
		}
		arr[row][col] = 'o';
		break;
	}
}

int main()
{
	srand((unsigned int)time(0));
	Init();           //初始化
	char winner = '\0';
	while (1)
	{
		print();          //打印棋盘
		playermove();    //玩家下棋 
		winner = checkwinner();
		if (winner != ' ')
		{
			break;
		}
		computermove();
		winner = checkwinner();
		if (winner != ' ')
		{
			break;
		}
	}
	print();
	if (winner == 'x')
	{
		printf("你赢了！真棒\n");
		
	}
	else if (winner == 'o')
	{
		printf("你输了！真菜\n");
		
	}
	else
	{
		printf("平局！\n");
		
	}

	system("pause");
	return 0;
}