//ÊµÏÖstrstr
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char str[] = "1234asd";
	char* str2 = strstr(str,"a");
	printf("%x\n%x\n", str, str2);
	system("pause");
	return 0;
}