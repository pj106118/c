//求字符串中字符的个数，输入一个字符串，计算该字符串含有多少个字符

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int length(char*p)

{

	int n = 0;

	while (*p != '\0')
	{
		n++;               //长度加1
		p++;               //指针后移一位
	}
	return n;
}

int main(void)
{
	int len;

	char a[100];

	memset(a, 0x00, 100);

	printf("请输入一个字符串:\n");
	gets(a);
	len = length(a);
	printf("字符串长度为：%d\n", len);
	system("pause");
	return 0;

}