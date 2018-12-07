#include<iostream>
#include<string>
using namespace std;

#define HASH_LENGTH 50               //哈希表的长度         
#define M 47                         //随机数
#define NAME_NO 30                   //人名的个数        

typedef struct
{
	char *py;    //名字的拼音
	int k;       //拼音所对应的整数
}NAME;

NAME NameList[HASH_LENGTH];    //全局变量NAME       

typedef struct    //哈希表
{
	char *py;   //名字的拼音
	int k;      //拼音所对应的整数
	int si;     //查找长度
}HASH;

HASH HashList[HASH_LENGTH];        //全局变量HASH                     

void InitNameList() //姓名（结构体数组）初始化          
{
	char *f;
	int r, s0, i;
	for (i = 0; i < HASH_LENGTH; i++)
	{
		NameList[i].py = new char[64];
		NameList[i].py[0] = 0;
	}
	strcpy(NameList[0].py, "baojie");
	strcpy(NameList[1].py, "chengaoyang");
	strcpy(NameList[2].py, "chenguangzhong");
	strcpy(NameList[3].py, "chenliangliang");
	strcpy(NameList[4].py, "chenyongzhou");
	strcpy(NameList[5].py, "fengchao");
	strcpy(NameList[6].py, "gexiangfeng");
	strcpy(NameList[7].py, "huting");
	strcpy(NameList[8].py, "huangpinjin");
	strcpy(NameList[9].py, "jiangxiaojia");
	strcpy(NameList[10].py, "laidongjie");
	strcpy(NameList[11].py, "liyexiao");
	strcpy(NameList[12].py, "lidaohui");
	strcpy(NameList[13].py, "lijue");
	strcpy(NameList[14].py, "lizhuoqun");
	strcpy(NameList[15].py, "linfujun");
	strcpy(NameList[16].py, "luobin");
	strcpy(NameList[17].py, "luokeqing");
	strcpy(NameList[18].py, "nichao");
	strcpy(NameList[19].py, "panhuafeng");
	strcpy(NameList[20].py, "sijun");
	strcpy(NameList[21].py, "songzhanhui"); 
	strcpy(NameList[22].py, "sunzhengqing");
	strcpy(NameList[23].py, "wanghaofeng");
	strcpy(NameList[24].py, "wangjunshuai");
	strcpy(NameList[25].py, "wangqinde");
	strcpy(NameList[26].py, "wangzejun");
	strcpy(NameList[27].py, "wangkeke");
	strcpy(NameList[28].py, "weixing");
	strcpy(NameList[29].py, "wurenke");

	for (i = 0; i < NAME_NO; i++)
	{
		s0 = 0;
		f = NameList[i].py;
		for (r = 0; *(f + r) != '\0'; r++)//方法：将字符串的各个字符所对应的
			//ASCII码相加，所得的整数做为哈希表的关键字
			s0 = *(f + r) + s0;
		NameList[i].k = s0;
	}
}
void CreateHashList() //建立哈希表   
{
	int i;
	for (i = 0; i < HASH_LENGTH; i++)
	{
		HashList[i].py = new char[64];
		HashList[i].py[0] = 0; 
		HashList[i].k = 0;
		HashList[i].si = 0;
	}
	for (i = 0; i < HASH_LENGTH; i++)
	{
		int sum = 0;
		int adr = (NameList[i].k) % M;
		//哈希函数
		int d = adr;
		if (HashList[adr].si == 0)     //如果不冲突
		{
			HashList[adr].k = NameList[i].k;
			HashList[adr].py = NameList[i].py;
			HashList[adr].si = 1;
		}
		else   //冲突 
		{
			while (HashList[d].k != 0)
			{
				d = (d + NameList[i].k % 10 + 1) % M;   //伪随机探测再散列法处理冲突    
				sum = sum + 1;                    //查找次数加1    
			};
			HashList[d].k = NameList[i].k;
			HashList[d].py = NameList[i].py;
			HashList[d].si = sum + 1;
		}
	}
}
void FindList() //查找    
{
	string name;
	int s0 = 0, r, sum = 1, adr, d;
	cout << "请输入姓名的拼音:" << endl;
	cin >> name;;
	for (r = 0; r < 20; r++)   //求出姓名的拼音所对应的整数(关键字)
		s0 += name[r];
	adr = s0%M;   //使用哈希函数
	d = adr;
	if (HashList[adr].k == s0)          //分3种情况进行判断
		cout << "姓名:" << HashList[d].py << " " << "关键字:" << s0 << " " << "查找长度为: 1" << endl;
	else if (HashList[adr].k == 0)
		cout << "无此记录!" << endl;
	else
	{
		int g = 0;
		while (g == 0)
		{
			d = (d + s0 % 10 + 1) % M;       //伪随机探测再散列法处理冲突                     
			sum = sum + 1;
			if (HashList[d].k == 0)
			{
				cout << "无此记录!" << endl;
				g = 1;
			}
			if (HashList[d].k == s0)
			{
				cout << "姓名:" << HashList[d].py << " " << "关键字:" << s0 << " " << "查找长度为:" << sum << endl;
				g = 1;
			}
		};
	}
}
void   Display() // 显示哈希表       
{
	int i;
	float average = 0;

	cout << "\n地址\t关键字\t\t搜索长度\tH(key)\t 姓名\n"; //显示的格式
	for (i = 0; i < 50; i++)
	{
		cout << i << " ";
		cout << "\t" << HashList[i].k << " ";
		cout << "\t\t" << HashList[i].si << " ";
		cout << "\t\t" << (HashList[i].k%M) << " ";
		cout << "\t " << HashList[i].py << " ";
		cout << "\n";
	}
	for (i = 0; i < HASH_LENGTH; i++)
		average += HashList[i].si;
	average /= NAME_NO;
	cout << "平均查找长度：ASL(" << NAME_NO << ")=" << average << endl;

}
int main()
{
	char x;
	InitNameList();
	CreateHashList();
	cout << "d. 显示哈希表 f. 查找 任意键退出   请选择：" << endl;
	while (cin >> x)
	{
		if (x == 'd')
		{
			Display();
			cout << endl;
		}
		else if (x == 'f')
		{
			FindList();
			cout << endl;
		}
		else break;
	}
	for (int i = 0; i < HASH_LENGTH; i++)
	{
		free(NameList[i].py);
		free(HashList[i].py);
	}
	return 0;
}