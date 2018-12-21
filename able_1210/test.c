#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void init(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] = i;
	}
	
}                 //这个函数是为了对数组进行初始化


void empty(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		arr[i] = 0;
		printf("%d\t", arr[i]);
	}
}                     //这个函数是为了对数组清零


void reverse(int arr[], int len)
{
	int i = 0;
	int left = 0;
	int right = len - 1;
	for (i = 0; i < len; ++i)
	{
		arr[i] = i;
	}
	for (i = 0; i < len; ++i)
	{
		while (left < right)
		{
			int num = arr[left];
			arr[left] = arr[right];
			arr[right] = num;
			left++;
			right--;
		}
		printf("%d\n", arr[i]);
	}
}            //这个函数是为了对数组进行逆置


int main()
{
	int a;
	printf("**           1：初始化数组         **\n");
	printf("**           2：清空数组           **\n");
	printf("**           3：逆置数组           **\n");
	printf("*************************************\n\n");
	printf("请选择：\n");
	scanf("%d", &a);
	int arr[5];
	int len = sizeof(arr) / sizeof(arr[0]);
	switch (a)
	{
	case 1:
		printf("初始化数组：\n");
		init(arr,len); 
		for (int i = 0; i < len; ++i)
			printf("%d\t", arr[i]);
		break;
	case 2:
		printf("清空数组：\n");
		empty(arr,len);
		break;
	case 3:
		printf("逆置数组：\n");
		reverse(arr,len); 
		break;
	default:
			break;
	}
	system("pause");
	return 0;
}