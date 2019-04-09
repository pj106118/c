#include<stdlib.h>
#include<stdio.h>
int maxSub(int a[]);//求最大子序列和
int main(void){
	int a[5][3] = {
		{ -50,17,-42 },
		{ -47,-19,-3 },
		{ 36,-34,-43 },
		{ -30,-43,34 },
		{ -23,-8,-45 }
	};
	int i, j;
	int max, n;
	int maxRoute = 0;
	int route[10];//用来存放旅游街每一列的最大分值
	for (i = 0; i<5; i++){
		max = a[i][0];//max为第i行的最大分值
		n = 0;//最大分值列号
		for (j = 0; j<3; j++)//遍历每一行元素
		{
			if (a[i][j]>max){
				max = a[i][j];
				n = j;
			}
		}
		route[i] = max;
		printf("a[%d][%d]=%d\n", i, n, max);
	}
	printf("最佳路线长度为：%d\n", maxSub(route));
	system("pause");
	return 0;
}
int maxSub(int a[]){
	int maxSum = 0, headSum = 0;
	int i;
	for (i = 0; i<5; i++){
		headSum += a[i];
		if (headSum>maxSum)
			maxSum = headSum;
		else if (headSum<0)
			headSum = 0;
	}
	return maxSum;
}