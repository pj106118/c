#include <stdio.h>
#include <stdlib.h>
#define N 10
int init(int arr1[N])
{
	arr1[N] = { 1,2,3,4,5 }
	for (int i = 0; i <= 5; ++i)
	{
		arr1[i] = 0;
	}
	return 0;
}        //这个函数是为了对数组进行初始化

void empty(int arr1[N])
{
	int i;
	for (i = 0; i < N; ++i)
		arr1[i] = 0;
	printf("清空完成！");
}              //这个函数是为了对数组清零

void reverse(int arr1[N])
{
	int arr2[N], i, j;
	for (i = 0, j = N - 1; i < N, j >= 0; ++i, j--)
		arr2[i] = arr1[j];
	for (i = 0; i < N; ++i)
		arr1[i] = arr2[i];
	for (i = 0; i < N; ++i)
		printf("arr[%d]=%2d ", i + 1, arr1[i]);
}            //这个函数是为了对数组进行逆置

int main()
{
	int arr[N], a;
printf("**           1：初始化数组         **\n");
printf("**           2：清空数组           **\n");
printf("**           3：逆置数组           **\n");
printf("**           4：退出               **\n");
printf("*************************************\n\n");
printf("请选择：");
scanf("%d", &a);
switch (a)
{
case 1:
	init(arr);
	break;
case 2:
	empty(arr);
	break;
case 3:
	reverse(arr);
	break;
dautle:
	break;
}
system("pause");
return 0;
}
