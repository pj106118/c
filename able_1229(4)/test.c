//µİ¹éÊµÏÖstrlen
#include <stdio.h>
#include <assert.h>
int Mystrlen(const char *str)
{
	if (*str)
	{
		return 1 + Mystrlen(str + 1);
	}
	else
	{
		return 0;
	}
}
int main()
{
	char str[] = "abcefg";
	int len = Mystrlen(str);
	printf("%d\n", len);
	system("pause");
	return 0;
}