#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define HASH_LEN 45
#define M 43
#define NAME_NO 30

//确定存储结构，并给出所用抽象数据类型的类型定义
typedef struct
{
	char name[20];
	int k;            //名字的ASCLL码值
	int s;            //标志                          
}HASH;               //哈希表的定义
HASH HashList[HASH_LEN];
void InitiltHash(HASH HashList[])
{
	int i;
	for (i = 0; i < HASH_LEN; i++)
	{
		strcpy(HashList[i].name, "");
		HashList[i].k = 0;
		HashList[i].s = 0;
	}
}
int hash(int k)
{
	return k%M;
}
int asc(char a[])
{
	int i = 0;
	int b = 0;
	while (a[i] != '\0')
	{
		b += (int)a[i];
		i++;
	}
	return b;
}


//给出所用抽象数据类型中主要操作的伪码算法
int Creathash(HASH HashList[])
{
	int j, f, m;
	char a[20];
	printf("请输入姓名:");
	scanf("%s", a);
	j = asc(a);
	f = hash(j);
	m = f;
	while (HashList[f].s != 0)
	{
		f = (f + 1) % M;
		if (f == m)
		{
			printf("哈希表已存满!\n");
			return 0;
		}
	}
	strcpy(HashList[f].name, a);
	HashList[f].k = j;
	HashList[f].s = 1;
	return 0;
}             // 创建哈希表


int Findname(HASH HashList[], char a[])
{
	int j, f, m;
	int q = 1;

	j = asc(a);
	f = hash(j);
	m = f;
	printf("\n");
	while (HashList[f].k != 0)
	{

		if (strcmp(HashList[f].name, a) == 0)
		{
			printf("姓名:%s,姓名的Asc为:%d,查找的长度为:1\t\n", HashList[f].name, HashList[f].k);
			return 0;
		}
		else
		{
			f = (f + 1) % M;
			if (strcmp(HashList[f].name, a) == 0)
			{
				q++;
				printf("姓名:%s,姓名的Asc为:%d,查找的长度为:%d\t\n", HashList[f].name, HashList[f].k, q);
				return 0;
			}
		}
	}
	printf("没有您所要查找的元素!\n");
	return -1;
}               //姓名查找

void print(HASH HashList[])
{
	int i;
	printf("序号  姓名     ASCLL码值  数组标志 \n");
	for (i = 0; i < HASH_LEN; i++)
	{
		if (HashList[i].s != 0)
		{
			printf("%d %s ", i, HashList[i].name);
			printf("%d ", HashList[i].k);
			printf("%d ", HashList[i].s);
			printf("\n");

		}
	}
}                 //打印哈希数组


void main()
{
	int j, i = 1;
	printf("*************哈希表的建立与查找!*************\n");
	InitiltHash(HashList);
	while (i)
	{
		printf("\n1.插入姓名  2.查找姓名   3.打印姓名表   4.退出操作\n");
		printf("  请输入对应的号码，选择您的操作!\n");
		scanf("%d", &j);
		switch (j)
		{
		case 1:  Creathash(HashList); break;
		case 2: {	printf("\n\n请输入您所要查找的姓名的拼音:");
			char a[20] = { 0 };
			scanf("%s", a);
			Findname(HashList, a);
			break;
		}
		case 3:  print(HashList); break;
		case 4:  i = 0; break;
		default:
			printf("  您的输入有误，请重新选择！\n");
			break;
		}
	}
}

