//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数
#include<stdio.h>
#include<stdlib.h>
int str(char *string)
{
	int n = 0;
	while (*string)
	{
		n++;
		string++;
	}
	return n;
}
void reverse(char *string)
{
	int len = str(string);
	if (*string)
	{
		char temp = *string;
		*string = *(string + len - 1);
		*(string + len - 1) = '\0';
		reverse(string + 1);
		*(string + len - 1) = temp;
	}
	else
	{
		return;
	}
}
int main()
{
	char s[10] = "abcdef";
	reverse(s);
	printf(" %s\n", s);
	system("pause");
	return 0;
}