#include<stdio.h>
#include<stdlib.h>
int main(){
	int A[6] = { 0,3,7,9,12,13 }; 
	int B[6] = { 0,5,10,11,11,11 }; 
	int C[6] = { 0,4,6,11,12,12 };
	int AB[6][6];
	int temp[6];
	int abc[6];
	int max;
	int flag;
	int i, j;

	for (i = 0; i <= 5; i++){
		max = 0;
		for (j = 0; j <= i; j++){
			AB[i][j] = A[i - j] + B[j];
			if (AB[i][j]>max)
				max = AB[i][j];
		}
		temp[i] = max;
	}
	max = 0;
	for (i = 0; i <= 5; i++){
		abc[i] = temp[i] + C[5 - i];
		if (abc[i]>max){
			max = abc[i];
			flag = i;
		}
	}
	printf("max=%d\n", max); 
	printf("c=%d\n", 5 - flag); 
	max = max - C[5 - flag];
	for (i = 0; i <= flag; i++){
		if (AB[flag][i] == max)	{
			printf("b=%d\n", i);
			printf("a=%d\n", flag - i);
			break;
		}
	}
	system("pause");
	return 0;

}
