#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void main()
{
	int a, b, c, i, n;
	double sum;
	for (i = 0; i <=999; ++i)
	{
		if (i>=100)
		{
			n = 3;
		}                    //如果i>100，水仙花数就是每个数的三次方
		else if(a<10)
		{ 
			n = 1;
		}                   //如果i<10，水仙花数就是每个数的一次方
		else n = 2;         //如果i在10到100之间，水仙花数就是每个数的平方

		a = i / 100;           //a代表的是百位上的数字
		b = (i % 100) / 10;   //b代表的是十位上的数字
		c = i % 10;           //c代表的是个位上的数字
		sum = pow(a, n) + pow(b, n) + pow(c, n);//pow(a,n)代表的是a的n次方
		if(i==sum)
		printf("%d\n", i);
	}
	system("pause");
}