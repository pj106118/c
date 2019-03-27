#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	void hanoi(int n, char one, char two, char three);
	int m;

	printf("请输入汉诺塔盘数：\n");
	scanf("%d", &m);
	printf("移动盘数为%d 的步骤为：\n", m);
	hanoi(m, 'A', 'B', 'C');
	system("pause");
	return 0;
}

void hanoi(int n, char one, char two, char three) {
	void move(char x, char y);
	if (n == 1) {
		move(one, three);
	}
	else {
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}

void move(char x, char y)
{
	printf("%c-->%c\n", x, y);
}