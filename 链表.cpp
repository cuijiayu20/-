#include<iostream>
#include<stdio.h>
#include<cstdlib>
typedef struct lnode {
	float data;
	struct lnode* next;
}lnode,*linklist;


void initlist(linklist &l,int n) {
	
	l = (linklist)malloc(sizeof(lnode));
	l->next = NULL;
	linklist p=l;
	if (!l) {
		printf("���ٿռ�ʧ��");
	}
	else {
		for (int i = 1; i <=n; i++) {
			p->next= (linklist)malloc(sizeof(lnode));
			p = p->next;
			if (i == n)
				p->next = NULL;

		}
	
	}
	return;
}

void input_lnode(linklist &l) {
	linklist p = NULL;
	p = l->next;
	
	printf("����������\n");
	while (p) {
		scanf_s("%f",&p->data);
		p = p->next;

	}
	return;
}

void destroylist(linklist &l) {
	linklist p=l,q=NULL;
	while (p->next) {
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free(p);
	printf("�ɹ�����");
}

void listempty(linklist &l) {
	linklist p=l->next;
	while (p->next) {
		if (!p->data) {
			printf("������");
			return;
		}
		else p = p->next;
	}
	printf("����ǿ�");
}

void listlength(linklist& l) {
	linklist p = l->next; int n = 0;
	while (p->next) {
		if (!p->data) {
			printf("������");
			return;
		}
		else p = p->next;
	}
	p = l->next;
	while (p) {
		n++;
		p = p->next;
		
	}
	printf("%d\n",n);
}

int main() {
	int n=0,m=2;
	linklist l=NULL;
	printf("������ڵ����\n");
	scanf_s("%d",&n);
	//�����б�
	initlist(l,n);
	//�������
	
	while (m){
		printf("\n---------��ѡ�����-----------\n");
		printf("1.��������\n");
		printf("2.��������\n");
		printf("3.�ж������Ƿ�Ϊ��\n");
		printf("4.����������Ԫ�ظ���\n");
		printf("5.���ص�i��Ԫ��ֵ\n");
		printf("6.�գ�������Ҫ��\n");
		printf("7.��i��Ԫ��֮ǰ����Ԫ��\n");
		printf("8.ɾ����i��Ԫ��\n");
		printf("9.����������\n");
		printf("0.�˳�\n");
		scanf_s("%d", &m);
		switch (m) {
		case 1:
			input_lnode(l);
			break;
		case 2:
			destroylist(l);
			break;
		case 3:
			listempty(l);
			break;
		case 4:
			listlength(l);
			break;
		/*case '5':
			getelem();
			break;
		case '6':
			break;
		case '7':
			listinsert();
			break;
		case '8':
			listdelete();
			break;*/
		case 9:
			printf("������ڵ����\n");
			scanf_s("%d", &n);
			initlist(l,n);
			break;
		default :
			printf("������Χ");
		}


	}
	return 0;
}



