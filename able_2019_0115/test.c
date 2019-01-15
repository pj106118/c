#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num = 0;
	
	for (int sum = 5; sum > 0; --sum)
	{
		num += sum;
	}
	printf("%d\n",num);
	system("pause");
	return 0;
}