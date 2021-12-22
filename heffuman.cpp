#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#pragma warning(disable : 4996)
using namespace std;
int n = 0;
typedef struct Heffuman {
	char act;
	float weight;
	int parent;          //双亲		//权值
	int lt;              //左孩子
	int rt;              // 右孩子
}Hefumanshu;            //节点命名

Hefumanshu* HT;//指向储存树
char HC[100][100];//储存编码

void Select(int k, int* s1, int* s2) {
	//在固定范围内找到权值最小的两个数,第一个最小的数
	int min = 0;
	for (int i = 1; i <= k; i++) {
		if (HT[i].parent == 0) {
			min = i;
			break;
		}
	}
	for (int i = min + 1; i <= k; i++) {
		if (HT[i].parent == 0 && HT[i].weight <= HT[min].weight)
			min = i;
	}
	*s1 = min;
	//找第二个最小值 
	for (int i = 1; i <= k; i++) {
		if (HT[i].parent == 0 && i != *s1) {
			min = i;
			break;
		}
	}
	for (int i = min + 1; i <= k; i++) {
		if (HT[i].parent == 0 && HT[i].weight <= HT[min].weight && i != *s1)
			min = i;
	}
	*s2 = min;
}

void CreateHuff() {
	int m = 2 * n - 1;
	HT = (Hefumanshu*)malloc((m + 2) * sizeof(Hefumanshu));//开辟空间 
	if (!HT) exit(0);
	for (int i = 0; i <= m + 1; i++) {                    //进行初始化
		HT[i].parent = 0; HT[i].act = '#';
		HT[i].lt = 0; HT[i].weight = 0.0;
		HT[i].rt = 0;
	}
	HT[0].weight = INT_MAX;
	printf("请输入编码符号和权值\n");
	float a[100];
	char s[100];
	scanf("%s", s);
	for (int i = 1; i <= n; i++) {                        //输入权值到一个数组
		scanf("%f", &a[i]);
	}
	for (int j = 1; j <= n; j++) {                        //输入权值入树表
		HC[j][0] = s[j - 1];
		HT[j].act = s[j - 1];
		HT[j].weight = a[j];

	}

	for (int i = n + 1; i <= m; i++) {                    //计算哈夫曼树
		int s1 = 0, s2 = 0;
		Select(i - 1, &s1, &s2);
		HT[i].act = '#';
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lt = s1;
		HT[i].rt = s2;
	}
	printf("哈夫曼树\n");
	for (int i = 0; i <= m; i++) {
		printf("%c	%1.2lf	%d	%d	%d\n", HT[i].act, HT[i].weight, HT[i].parent, HT[i].lt, HT[i].rt);  //打印哈夫曼树
	}
	printf("\n");
}

void HuffCoding() {
	//HC = (char**)malloc(sizeof(char*) * (n + 3));                        错误，malloc使堆栈损坏
	//if(!HC) exit(0);
	//char* code = (char*)malloc(sizeof(char) *( n+1));
	//if(!code) exit(0);//开辟储存空间 
	char code[100];                                                       //使用数组储存编码
	//char HC[100][100];
	code[n - 1] = '\0';

	for (int i = 1; i <= n; i++) {                                       //进行编码操作
		int start = n - 1;
		int c = i;
		int p = HT[c].parent;
		while (p) {
			if (HT[p].lt == c)
				code[--start] = '0';
			else
				code[--start] = '1';
			c = p;
			p = HT[c].parent;
			
			for (int k = 1,s = start; code[s]!='\0';s++,k++) {

				HC[i][k]= code[s];
				HC[i][s+1] = '\0';
			}

			
		}
		
		

	}
	
}

char CodingHuff(char p[]) {                                            //反编码
	int k = 0;
	for (int i = 1; i<=n; i++) {
		for (int j = 1; p[j-1] != '\0'; j++) {
			if (HC[i][j] != p[j - 1])
				break;
			if (p[j] == '\0'&&HC[i][j+1]=='\0')
				k = i;

		}
	}
	if (k == 0)
		printf("查找失败");           
	else return HC[k][0];
}



int main() {
	char p[1000];
	char q;
	char w;                                
	printf("请输入字符集大小\n");
	scanf("%d", &n);
	CreateHuff();                              //构建树
	printf("成功构建哈夫曼树\n");
	HuffCoding();                               //编码
	printf("成功编码\n");
	for (int i = 1; i <= n; i++) {
		printf("数据");
		for (int k = 0;k<=n; k++)
		printf(" % c",HC[i][k]);
		printf("\n");
	}
	printf("是否需要反编译编码y/n");     //判断是否要反编码
	rewind(stdin);
	scanf("%c", &w);
	while(w!='n')
	{
		printf("请输入编码");
			scanf("%s", &p);
			q = CodingHuff(p);                  //反编码
			printf("%c", q);
			printf("是否需要反编译编码y/n");
			rewind(stdin);
			scanf("%c", &w);
		
	}
	
	free(HT);                                   //释放树
	HT = NULL;

}
