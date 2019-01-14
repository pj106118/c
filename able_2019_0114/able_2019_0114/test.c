#include <stdio.h>
#include <stdlib.h>
long int fun(int i) 
{ 
	return (5 * i + 4); 
}

int main()
{ 
	 long int s=0;
	 int i=0; 
	 while (fun(i)<=1001)
		 s+=fun(i++); 
	 printf("%d\n",s);
	system("pause");
	return 0;
}