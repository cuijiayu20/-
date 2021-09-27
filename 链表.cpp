#include<iostream>
#include<stdio.h>
#include<cstdlib>
typedef struct lnode {
	float data;
	struct lnode* next;
}lnode, * linklist;


void initlist(linklist& l, int n) {

	l = (linklist)malloc(sizeof(lnode));
	l->next = NULL;
	linklist p = l;
	if (!l) {
		printf("���ٿռ�ʧ��");
	}
	else {
		for (int i = 1; i <= n; i++) {
			p->next = (linklist)malloc(sizeof(lnode));
			p = p->next;
			if (i == n)
				p->next = NULL;

		}

	}
	return;
}

void input_lnode(linklist& l) {
	linklist p = NULL;
	p = l->next;

	printf("����������\n");
	while (p) {
		scanf_s("%f", &p->data);
		p = p->next;

	}
	return;
}

void destroylist(linklist& l) {
	/*linklist p=l,q=NULL;
	while (p->next) {
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free(p);*/
	l->next = NULL;
	printf("�ɹ�����");
}

void listempty(linklist& l) {
	linklist p = l;
	if (!p->next) {
		printf("������");
		return;
	}
	printf("�ǿ�����");
}

void listlength(linklist& l) {
	linklist p = l; int n = 0;
	if (!p->next) {
		printf("������");
		return;
	}
	p = l->next;
	while (p) {
		n++;
		p = p->next;

	}
	printf("%d\n", n);
}

void getelem(linklist& l, int i) {
	linklist p = l; int n = 1;
	if (!p->next) {
		printf("������");
		return;
	}
	p = p->next;
	while (p) {
		if (n == i) {
			printf("%.1f", p->data);
			return;
		}
		else { n++; p = p->next; }
	}
	printf("û���ҵ�����");
}

void listinsert(linklist& l, int i) {
	linklist p = l; int n = 0; linklist q;
	q = (linklist)malloc(sizeof(lnode));
	printf("����������");
	scanf_s("%f", &q->data);
	while (p) {
		if (n == (i - 1)) {
			q->next = p->next;
			p->next = q;
			printf("�ɹ�����\n");
			return;
		}
		else {
			p = p->next;
			n++;
		}

	}
	printf("û���ҵ�i��λ��");
}

void listdelete(linklist& l, int i) {
	linklist p = l; int n = 0; linklist q;
	while (p) {
		if (n == i - 1) {
			q = p->next;
			p->next = p->next->next;

			printf("ɾ���ɹ�");
			return;
		}
		else {
			p = p->next;
			n++;
		}

	}
	printf("û���ҵ�i");
}

void output_data(linklist& l) {
	linklist p = l;
	if (!p->next) {
		printf("������");
		return;
	}
	else {
		p = l->next;
		while (p) {
			printf("%.1f\t", p->data);
			p = p->next;
		}
	}
}



int main() {
	int n = 0, m = 2;
	linklist l = NULL;
	printf("������ڵ����\n");
	scanf_s("%d", &n);
	//�����б�
	initlist(l, n);
	//�������

	while (m) {
		int i = 0;
		printf("\n---------��ѡ�����-----------\n");
		printf("1.��������\n");
		printf("2.��������\n");
		printf("3.�ж������Ƿ�Ϊ��\n");
		printf("4.����������Ԫ�ظ���\n");
		printf("5.���ص�i��Ԫ��ֵ\n");
		printf("6.�������ֵ\n");
		printf("7.��i��Ԫ��֮ǰ����һ��Ԫ��\n");
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
		case 5:

			printf("������ѡȡ�ĵ�i��Ԫ��\n");
			scanf_s("%d", &i);
			getelem(l, i);
			break;
		case 6:
			output_data(l);
			break;
		case 7:

			printf("������ѡȡ�ĵ�i��Ԫ��\n");
			scanf_s("%d", &i);
			listinsert(l, i);
			break;
		case 8:

			printf("��������Ҫɾ����Ԫ��i\n");
			scanf_s("%d", &i);
			listdelete(l, i);
			break;
		case 9:
			printf("������ڵ����\n");
			scanf_s("%d", &n);
			initlist(l, n);
			break;
		default:
			printf("������Χ\n");
		}


	}
	return 0;
}



