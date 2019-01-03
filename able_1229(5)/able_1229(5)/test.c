//∑«µ›πÈ µœ÷strlen
#include <stdio.h>
#include <assert.h>
int Mystrlen(const char *str)
{
	int count = 0;
	assert(str!=NULL);
	while (*str++)
	{
		count++;
	}
	return count;
}
int main()
{
	char str[] = "abcefg";
	int len = Mystrlen(str);
	printf("%d\n", len);
	system("pause");
	return 0;
}