  //编写函数： 
  //unsigned int reverse_bit(unsigned int value);
  //这个函数的返回值value的二进制位模式从左到右翻转后的值。
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int unit;
unit reverse_bit(int value)
{
	int num = 0;
	for (int i = 0; i < 32; i++)

	{
		
		num += ((value >> i) & 1) * pow(2, 31 - i);  //翻转，求值，pow求2的31-i次幂

	}

	return num;
}

int main()
{
	int num , value;
	printf("请输入一个正数：\n");
	scanf("%d", &value);
	num = reverse_bit(value);
	printf("%u\n", num);               //以十进制形式输出
	system("pause");
	return 0;
}