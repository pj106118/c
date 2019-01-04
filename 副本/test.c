#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define M 9
#define N 9
//0代表通路，2代表墙体,1是老鼠位置，3是粮仓位置
int maze[M][N] = {
	{ 2,2,2,2,2,2,2,2,2 },
	{ 2,0,0,0,2,0,0,0,2 },
	{ 2,0,2,0,0,0,2,2,2 },
	{ 2,0,0,2,2,0,0,0,2 },
	{ 2,0,0,0,1,2,2,0,2 },
	{ 2,0,2,0,2,0,0,0,2 },
	{ 2,0,2,0,2,0,0,2,2 },
	{ 2,0,0,0,0,0,0,3,2 },
	{ 2,2,2,2,2,2,2,2,2 }
};


struct best                  //用于记录最短路径的结构体
{
	int min;
	int b[M][N];
}Best;

int m = 4, n = 4;            //老鼠的初始位置
int p = 4, q = 4;           //老鼠位置二次定位
int x = 7, y = 7;            //粮仓初始位置
int g, answer;		    //g:统计有效路径，防止路径过多，造成循环过度；
						//answer:统计该地图的所有可能性；

void game()  //走迷宫游戏，包含时间统计，以及对老鼠的移动控制，游戏模块
{
	int i, j, v = 0, t = 0;          //t为初始时间
									 //v代表移动成功后，v加1，否则加0
	char str;                      //存放字符w,s,a,d
	time_t start, end;
	start = time(NULL);

	maze[x][y] = 3;        //放粮仓的位置

	m = p;
	n = q;
	maze[m][n] = 1;    //重新定位老鼠位置

	printf("显示迷宫：\n");     //地图初始化
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (maze[i][j] == 2) {
				printf("▉");
			}

			else if (maze[i][j] == 1)
			{
				printf("鼠");
			}
			else if (maze[i][j] == 3)
			{
				printf("粮");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("（按w↑s↓a← d→移动）\n请在60秒内通关\n"); //初始化地图

	while (1)
	{
		printf("时间：%d\r", t);
		if (kbhit())	 //输入控制
						 //如果有输入就返回非零值,否则返回0.
		{
			str = getch();    //接受用户从键盘输入的字符，并存入str中
			if (str == 'w') //上
			{
				if (maze[m - 1][n] == 0)
				{
					maze[m - 1][n] = 1;
					maze[m][n] = 0;
					m = m - 1;
				}
				else if (maze[m - 1][n] == 3)
				{
					maze[m][n] = 0;
					v = 1;
				}
			}
			else if (str == 's')   //下
			{
				if (maze[m + 1][n] == 0)
				{
					maze[m + 1][n] = 1;
					maze[m][n] = 0;
					m = m + 1;
				}
				else if (maze[m + 1][n] == 3)
				{
					maze[m][n] = 0;
					v = 1;
				}
			}
			else if (str == 'a')   //左
			{
				if (maze[m][n - 1] == 0)
				{
					maze[m][n - 1] = 1;
					maze[m][n] = 0;
					n = n - 1;
				}
				else if (maze[m][n - 1] == 3)
				{
					maze[m][n] = 0;
					v = 1;
				}
			}
			else if (str == 'd')  //右
			{
				if (maze[m][n + 1] == 0)
				{
					maze[m][n + 1] = 1;
					maze[m][n] = 0;
					n = n + 1;
				}
				else if (maze[m][n + 1] == 3)
				{
					maze[m][n] = 0;
					v = 1;
				}
			}
			else;

			system("cls");   //cls是为了清屏
			printf("显示迷宫：\n");  //显示游戏地图
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)
				{
					if (maze[i][j] == 2)
					{
						printf("▉");
					}

					else if (maze[i][j] == 1)
					{
						printf("鼠");
					}
					else if (maze[i][j] == 3)
					{
						printf("粮");
					}
					else
					{
						printf("  ");
					}
				}
				printf("\n");
			}
			printf("（按w↑s↓a← d→移动）\n请在60秒内通关\n");
		}
		else;

		if (v == 1)  //判断是否通关
		{
			printf("\n恭喜通关！\n");
			system("pause");
			break;
		}

		if (t>60)   //规定时间到后结束游戏
		{
			printf("\n未在规定时间内通关，游戏失败。\n");
			maze[m][n] = 0;   //清除最后所在位置
			system("pause");
			break;
		}

		end = time(NULL);
		t = difftime(end, start);
	}

}

void create_plat()   //新建地图，并存入文件的模块
{
	int i, j, s;
cc:	printf("请输入0和2,0代表通路，2代表墙体(数字用空格隔开)，输入规格是%dx%d，有边缘墙体无需再次输入\n", M - 2, M - 2);
	for (i = 1; i <= M - 2; i++)
	{
		printf("第%d行:", i);
		for (j = 1; j <= N - 2; j++)
		{
			scanf("%d", &s);
			if (s == 0 || s == 2)
				maze[i][j] = s;
			else
			{
				system("cls");         //清屏
				printf("输入错误请重新输入!\n");
				goto cc;           //跳转到cc去做执行
			}
		}
	}

aa: printf("请设置老鼠的初始位置x,y即行列（1~%d,1~%d）:\n", M - 2, N - 2);

	for (i = 0; i<30; i++)
		fflush(stdin);     //清除来自键盘的30多个缓存字符，防止死循环bug

	scanf("%d,%d", &p, &q);
	if (p <= (M - 2) && q <= (M - 2) && p>0 && q>0)
		maze[p][q] = 1;
	else
	{
		system("cls");    //清屏
		printf("输入错误，请重新输入,在%dx%d的范围内。\n", M - 2, N - 2);
		goto aa;
	}

bb: printf("请设置粮仓的位置x,y:\n");

	//清除来自键盘的30多个缓存字符，防止死循环bug
	for (i = 0; i<30; i++)
		fflush(stdin);

	scanf("%d,%d", &x, &y);
	if (x <= (M - 2) && y <= (N - 2) && x>0 && y>0 && (x != p || y != q))
		maze[x][y] = 3;
	else
	{
		system("cls");
		printf("输入错误，请重新输入,在%dx%d的范围内。\n", M - 2, N - 2);
		goto bb;
	}

	//文件保存地图
	FILE *fp;
	fp = fopen("plat.txt", "w");
	for (i = 0; i<M; i++)
	{
		for (j = 0; j<N; j++)
			fprintf(fp, "%d\t", maze[i][j]);
		fprintf(fp, "%c", '\n');
	}
	fprintf(fp, "%d\t", p);
	fprintf(fp, "%d\t", q);
	fprintf(fp, "%d\t", x);
	fprintf(fp, "%d\t", y);
	fclose(fp);

	printf("地图新建完成,并保存成功！\n");
	system("pause");
}

void show_plat()   //地图展示模块
{
	int i, j;
	system("cls");

	maze[x][y] = 3;    //粮仓位置

	m = p;
	n = q;
	maze[m][n] = 1;      //老鼠位置

	printf("显示迷宫：\n");  //显示游戏地图
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (maze[i][j] == 2)
			{
				printf("▉");
			}

			else if (maze[i][j] == 1)
			{
				printf("鼠");
			}
			else if (maze[i][j] == 3)
			{
				printf("粮");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("已显示地图\n");
	system("pause");
}

void alter_plat()    //修改地图模块
{
	int i, j, select, a, b;
	FILE *fp;
	while (1)
	{
		system("cls");

		m = p;
		n = q;
		maze[m][n] = 1;

		printf("显示迷宫：\n");  //显示游戏地图
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (maze[i][j] == 2)
				{
					printf("▉");
				}

				else if (maze[i][j] == 1)
				{
					printf("鼠");
				}
				else if (maze[i][j] == 3)
				{
					printf("粮");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
		printf("  =============----修改地图------===================\n");
		printf(" |请选择：                                          |\n");
		printf(" |              1.修改为墙体；                      |\n");
		printf(" |              2.修改为通路；                      |\n");
		printf(" |              3.保存修改地图；                    |\n");
		printf(" |              0.退出修改功能；                    |\n");
		printf("  ===========（请输入相应数字执行其功能）===========\n");
		fflush(stdin);  //清除键入的缓存
		scanf("%d", &select);

		if (select<4 && select >= 0)
		{
			switch (select)
			{
			case 1:	printf("围墙内为修改范围，范围是%dx%d\n", M - 2, N - 2);
				printf("请输入坐标x,y(行,列)修改地图:\n");

				//清除来自键盘的30多个缓存字符，防止死循环bug
				for (i = 0; i<30; i++)
					fflush(stdin);

				scanf("%d,%d", &a, &b);
				if (a <= (M - 2) && b <= (N - 2) && a>0 && b>0 && maze[a][b] != 1 && maze[a][b] != 3)
					maze[a][b] = 2;
				else
				{
					printf("输入错误请重新输入，不能在围墙、粮仓和老鼠的位置修改!\n");
					system("pause");
				}
				break;
			case 2:	printf("围墙内为修改范围，范围是%dx%d\n", M - 2, N - 2);
				printf("请输入坐标x,y(行,列)修改地图:\n");
				//清除来自键盘的30多个缓存字符，防止死循环bug
				for (i = 0; i<30; i++)
					fflush(stdin);

				scanf("%d,%d", &a, &b);
				if (a <= (M - 2) && b <= (N - 2) && a>0 && b>0 && maze[a][b] != 1 && maze[a][b] != 3)
					maze[a][b] = 0;
				else
				{
					printf("输入错误请重新输入，不能在围墙、粮仓和老鼠的位置修改!\n");
					system("pause");
				}
				break;
			case 3:
			{			//文件形式保存修改后地图
				fp = fopen("plat.txt", "w");
				for (i = 0; i<M; i++)
				{
					for (j = 0; j<N; j++)
						fprintf(fp, "%d\t", maze[i][j]);
					fprintf(fp, "%c", '\n');
				}
				fprintf(fp, "%d\t", p);
				fprintf(fp, "%d\t", q);
				fprintf(fp, "%d\t", x);
				fprintf(fp, "%d\t", y);
				fclose(fp);

				printf("地图修改完成,并保存成功！\n");
				system("pause");
			}
			break;
			case 0: break;
			}
		}
		else
		{
			printf("请按规定输入!\n");
			system("pause");
		}

		if (select == 0)
			break;
	}
}

void read_plat()  //读取文件里的地图模块
{
	int i, j;
	FILE *fp;
	fp = fopen("plat.txt", "r");
	if (!fp)
	{
		printf("文件不存在，请重新打开!\n");
		system("pause");
	}
	else
	{
		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
				fscanf(fp, "%d\t", &maze[i][j]);
			fscanf(fp, "\n");
		}
		fscanf(fp, "%d\t", &p);
		fscanf(fp, "%d\t", &q);    //读取老鼠的位置
		fscanf(fp, "%d\t", &x);
		fscanf(fp, "%d\t", &y);   //读取粮仓的位置
		printf("读取成功，请查看新地图！\n");
		system("pause");
	}
	fclose(fp);
}

void path_result(int p, int q)  
       //统计地图的所有可能出现的路径结果，并把次数赋给全局变量answer
      //并在path_result函数中引用变量，作为递归终止和显示最优解的条件
{
	int i, j;
	maze[p][q] = 1;

	if (maze[p][q + 1] == 3 || maze[p][q - 1] == 3 || maze[p + 1][q] == 3 || maze[p - 1][q] == 3)  
		//判断当前位置上下左右是否有粮仓
	{
		++answer;    //统计一个地图的所有可能性的次数
		printf("已计算%d次,若超过1 h,请重启\r", answer);
	}
	// 递归部分，即寻找路径的部分
	if (maze[p][q + 1] == 0) path_result(p, q + 1);  //右
	if (maze[p + 1][q] == 0) path_result(p + 1, q);  //下
	if (maze[p][q - 1] == 0) path_result(p, q - 1);  //左
	if (maze[p - 1][q] == 0) path_result(p - 1, q);  //上
	maze[p][q] = 0;

}


void path_best(int p, int q, int l)     //显示最优路径的模块
{
	int i, j, c, k;

	maze[p][q] = 1;

	if (maze[p][q + 1] == 3 || maze[p][q - 1] == 3 || maze[p + 1][q] == 3 || maze[p - 1][q] == 3)   //判断当前位置上下左右是否有粮仓
	{
		if (Best.min>l)
		{
			Best.min = l;
			for (i = 0; i < M; i++)
				for (j = 0; j< N; j++)
					Best.b[i][j] = maze[i][j];
		}
		g++;
		k = ((double)g / answer) / 2 * 100 + 50;  //计算后面一半完成的百分比情况

		printf("已完成%d%%，请继续等待\r", k);

		c = g;

		if (c == answer)               //防止过度循环，比较answer条路径。
		{
			printf("已列举最优解！%d个方案中的最优解\n", answer);
			for (i = 0; i < M; i++)
			{
				for (j = 0; j< N; j++)
					if (Best.b[i][j] == 2)
					{
						printf("█");
					}
					else if (Best.b[i][j] == 1)
						printf("の");
					else if (Best.b[i][j] == 3)
						printf("粮");
					else
						printf("  ");
				printf("\n");
			}
			printf("已显示最优解，方案如上！\n");
			maze[p][q] = 0;
			return;
			exit(0);
		}

	}

	++l;

	if (g != answer)
	{
		if (maze[p][q + 1] == 0) path_best(p, q + 1, l);  //右
		if (maze[p + 1][q] == 0) path_best(p + 1, q, l);  //下
		if (maze[p][q - 1] == 0) path_best(p, q - 1, l);  //左
		if (maze[p - 1][q] == 0) path_best(p - 1, q, l);  //上
	}
	maze[p][q] = 0;
}

void path_find(int p, int q)  //寻找通关路径的模块
{
	int i, j, c;
	maze[p][q] = 1;

	c = g;
	if (c == 15)               //防止过度循环，暂时只能显示15条路径，可调节。
	{
		printf("已列举10种可行方案！！方案太多可能列举不完，所以最多列举15个\r");
		maze[p][q] = 0;
		return;
		//	exit(0);
	}

	if (maze[p][q + 1] == 3 || maze[p][q - 1] == 3 || maze[p + 1][q] == 3 || maze[p - 1][q] == 3)
		//判断当前位置上下左右是否有粮仓
	{
		printf("显示路径: \n");
		for (i = 0; i < M; i++)
		{
			for (j = 0; j< N; j++)
			{
				if (maze[i][j] == 2)
				{
					printf("█");
				}
				else if (maze[i][j] == 1)
					printf("の");
				else if (maze[i][j] == 3)
					printf("粮");
				else
					printf("  ");
			}
			printf("\n");
		}
		printf("已显示方案，如上！\n");
		g++;
	}

	if (g != 15)
	{
		if (maze[p][q + 1] == 0) path_find(p, q + 1);  //右
		if (maze[p + 1][q] == 0) path_find(p + 1, q);  //下
		if (maze[p][q - 1] == 0) path_find(p, q - 1);  //左
		if (maze[p - 1][q] == 0) path_find(p - 1, q);  //上
	}
	maze[p][q] = 0;
}

void main()   //主函数，菜单控制界面
{            //全局变量：m,n老鼠位置，p,q老鼠初始位置x,y粮仓的初始位置
			 //g统计所有有效路径的次数，最多十次，防止因为路径过多而死循环；
	int select, k;
	time_t start, end;
	int hour, minute, second, t;   //时间变量

	while (1)
	{
		system("cls");
		printf("  =============老鼠走迷宫游戏 n.0===================\n");
		printf(" |请选择：                                          |\n");
		printf(" |              1.开始游戏；                        |\n");
		printf(" |              2.新建地图；                        |\n");
		printf(" |              3.查看地图；                        |\n");
		printf(" |              4.修改地图；                        |\n");
		printf(" |              5.读取地图；                        |\n");
		printf(" |              6.显示最短路径；                    |\n");
		printf(" |              7.显示通关所有路径；                |\n");
		printf(" |              0.退出系统；                        |\n");
		printf("  ===========（请输入相应数字执行其功能）===========\n");
		printf(" 注意事项:\n 地图不要全空,否则不要执行6,7选项,会运算十亿次花费很长时间，尽量把通关所有路径设置在一亿种以内！\n");
		for (k = 0; k<30; k++)
			fflush(stdin);  //清除键盘输入的scanf缓存，防止死循环

		scanf("%d", &select);
		if (select >= 0 && select<8)    //键盘输入检错
		{
			switch (select)
			{
			case 0:  exit(0);
			case 1:	 system("cls");  //清除菜单 
				game();        //开始游戏
				break;
			case 2:  create_plat();  //新建地图
				break;
			case 3:  show_plat();   //显示地图
				break;
			case 4:  alter_plat();  //修改地图
				break;
			case 5:  read_plat();   //在文件里读取地图
				break;
			case 6:  g = 0; Best.min = 999; answer = 0;
				start = time(NULL);
				path_result(p, q);    //统计地图所有解的个数
				path_best(p, q, 1);   //寻找最短的路径
				end = time(NULL);
				t = difftime(end, start);
				second = t % 60;     //求出秒
				minute = t / 60;        //总分数
				hour = minute / 60;      //求出小时
				minute = minute % 60;   //求出分
				printf("花费时间：%dh %dm %ds", hour, minute, second);
				//显示寻找最短路径所花费的时间
				system("pause");
				break;
			case 7:  g = 0;
				path_find(p, q);   //寻找所有通关路径
				printf("已显示所有路径! \n");
				system("pause");
				break;
			default:
				break;
			}
		}
		else
		{
			printf("请按规定输入！\n");
			system("pause");
		}
	}
}
