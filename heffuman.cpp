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
	int parent;          //˫��		//Ȩֵ
	int lt;              //����
	int rt;              // �Һ���
}Hefumanshu;            //�ڵ�����

Hefumanshu* HT;//ָ�򴢴���
char HC[100][100];//�������

void Select(int k, int* s1, int* s2) {
	//�ڹ̶���Χ���ҵ�Ȩֵ��С��������,��һ����С����
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
	//�ҵڶ�����Сֵ 
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
	HT = (Hefumanshu*)malloc((m + 2) * sizeof(Hefumanshu));//���ٿռ� 
	if (!HT) exit(0);
	for (int i = 0; i <= m + 1; i++) {                    //���г�ʼ��
		HT[i].parent = 0; HT[i].act = '#';
		HT[i].lt = 0; HT[i].weight = 0.0;
		HT[i].rt = 0;
	}
	HT[0].weight = INT_MAX;
	printf("�����������ź�Ȩֵ\n");
	float a[100];
	char s[100];
	scanf("%s", s);
	for (int i = 1; i <= n; i++) {                        //����Ȩֵ��һ������
		scanf("%f", &a[i]);
	}
	for (int j = 1; j <= n; j++) {                        //����Ȩֵ������
		HC[j][0] = s[j - 1];
		HT[j].act = s[j - 1];
		HT[j].weight = a[j];

	}

	for (int i = n + 1; i <= m; i++) {                    //�����������
		int s1 = 0, s2 = 0;
		Select(i - 1, &s1, &s2);
		HT[i].act = '#';
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lt = s1;
		HT[i].rt = s2;
	}
	printf("��������\n");
	for (int i = 0; i <= m; i++) {
		printf("%c	%1.2lf	%d	%d	%d\n", HT[i].act, HT[i].weight, HT[i].parent, HT[i].lt, HT[i].rt);  //��ӡ��������
	}
	printf("\n");
}

void HuffCoding() {
	//HC = (char**)malloc(sizeof(char*) * (n + 3));                        ����mallocʹ��ջ��
	//if(!HC) exit(0);
	//char* code = (char*)malloc(sizeof(char) *( n+1));
	//if(!code) exit(0);//���ٴ���ռ� 
	char code[100];                                                       //ʹ�����鴢�����
	//char HC[100][100];
	code[n - 1] = '\0';

	for (int i = 1; i <= n; i++) {                                       //���б������
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

char CodingHuff(char p[]) {                                            //������
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
		printf("����ʧ��");           
	else return HC[k][0];
}



int main() {
	char p[1000];
	char q;
	char w;                                
	printf("�������ַ�����С\n");
	scanf("%d", &n);
	CreateHuff();                              //������
	printf("�ɹ�������������\n");
	HuffCoding();                               //����
	printf("�ɹ�����\n");
	for (int i = 1; i <= n; i++) {
		printf("����");
		for (int k = 0;k<=n; k++)
		printf(" % c",HC[i][k]);
		printf("\n");
	}
	printf("�Ƿ���Ҫ���������y/n");     //�ж��Ƿ�Ҫ������
	rewind(stdin);
	scanf("%c", &w);
	while(w!='n')
	{
		printf("���������");
			scanf("%s", &p);
			q = CodingHuff(p);                  //������
			printf("%c", q);
			printf("�Ƿ���Ҫ���������y/n");
			rewind(stdin);
			scanf("%c", &w);
		
	}
	
	free(HT);                                   //�ͷ���
	HT = NULL;

}
