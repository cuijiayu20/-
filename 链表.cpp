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
		printf("开辟空间失败");
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

	printf("请输入数据\n");
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
	printf("成功销毁");
}

void listempty(linklist& l) {
	linklist p = l;
	if (!p->next) {
		printf("空链表");
		return;
	}
	printf("非空链表");
}

void listlength(linklist& l) {
	linklist p = l; int n = 0;
	if (!p->next) {
		printf("空链表");
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
		printf("空链表");
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
	printf("没有找到数据");
}

void listinsert(linklist& l, int i) {
	linklist p = l; int n = 0; linklist q;
	q = (linklist)malloc(sizeof(lnode));
	printf("请输入数据");
	scanf_s("%f", &q->data);
	while (p) {
		if (n == (i - 1)) {
			q->next = p->next;
			p->next = q;
			printf("成功插入\n");
			return;
		}
		else {
			p = p->next;
			n++;
		}

	}
	printf("没有找到i的位置");
}

void listdelete(linklist& l, int i) {
	linklist p = l; int n = 0; linklist q;
	while (p) {
		if (n == i - 1) {
			q = p->next;
			p->next = p->next->next;

			printf("删除成功");
			return;
		}
		else {
			p = p->next;
			n++;
		}

	}
	printf("没有找到i");
}

void output_data(linklist& l) {
	linklist p = l;
	if (!p->next) {
		printf("空链表");
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
	printf("请输入节点个数\n");
	scanf_s("%d", &n);
	//创建列表
	initlist(l, n);
	//操作面板

	while (m) {
		int i = 0;
		printf("\n---------请选择操作-----------\n");
		printf("1.输入数据\n");
		printf("2.销毁链表\n");
		printf("3.判断链表是否为空\n");
		printf("4.返回链表中元素个数\n");
		printf("5.返回第i个元素值\n");
		printf("6.输出所有值\n");
		printf("7.第i个元素之前插入一个元素\n");
		printf("8.删除第i个元素\n");
		printf("9.创建新链表\n");
		printf("0.退出\n");
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

			printf("请输入选取的第i个元素\n");
			scanf_s("%d", &i);
			getelem(l, i);
			break;
		case 6:
			output_data(l);
			break;
		case 7:

			printf("请输入选取的第i个元素\n");
			scanf_s("%d", &i);
			listinsert(l, i);
			break;
		case 8:

			printf("请输入需要删除的元素i\n");
			scanf_s("%d", &i);
			listdelete(l, i);
			break;
		case 9:
			printf("请输入节点个数\n");
			scanf_s("%d", &n);
			initlist(l, n);
			break;
		default:
			printf("超出范围\n");
		}


	}
	return 0;
}



