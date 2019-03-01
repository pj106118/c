//ÊµÏÖstrcpy
#include <stdio.h>
#include <stdlib.h>
int main() {
	char str[] = "hello!";
	char str2[20] = { 0 };
	int len = 0;
	len = strlen(strcpy(str2, str));
	printf("str = %s\nstr2 = %s\nlen = %d\n", str, str2, len);
	system("pause");
	return 0;
}