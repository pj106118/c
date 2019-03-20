
#include<stdio.h>
#include<stdlib.h>
	
int main() {
	int a, b, c, d, e;
	for(a = 1;a <= 5;a++)
		for (b = 1; b <= 5; b++)
			if(a != b)
				for (c = 1; c <= 5; c++)
					if(a != c && b != c)
						for (d = 1; d <= 5; d++)
							if(a !=d && b != d && c != d){
								e = 15 - a - b - c - d;
								if (a != e && b != e && c != e && d != e)
								{
									if (((b = 3) + (c = 5)) == 1 && ((d = 2) + (e = 4)) == 1 && ((b = 1) + (e = 4)) == 1 && ((d = 2) + (a = 3)) == 1);
									printf("a=%d,b=%d,c=%d,d=%d,e=%d", a, b, c, d, e);
									break;
								}
							}
	system("pause");
	return 0;
}