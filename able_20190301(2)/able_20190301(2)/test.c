// µœ÷strcat
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char str[] = "hello";
	char str2[] = "world";
	strcat(str, str2);
	printf("%s\n", str);
	system("pause");
	return 0;
}