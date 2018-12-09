#include <stdio.h>
#include <stdlib.h>
void main()
{
	int i, count=0;
	for (i=1;i<=100;i++)
	{
		if (i%10==9||i/10==9)
		count += 1;
	}
	printf("%d\n",count);
	system("pause");
}