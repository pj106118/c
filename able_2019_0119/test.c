#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr);
	system("pause");
	return 0;
}