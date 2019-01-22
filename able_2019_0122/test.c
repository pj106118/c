#include <stdio.h>
#include <stdlib.h>

void print(int *p, int sz) 
{ 
	int i = 0; 
	for (i = 0; i<sz; i++) 
	{ 
		printf("%d\n", *(p + i));
	}
} 
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 }; 
	int *p = arr;  
	int sz = sizeof(arr) / sizeof(arr[0]);
	system("pause");
	return 0;
}