#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

int ListInsert_L(LinkList head, int i, ElemType e) {
	LinkList p = head;
	LinkList s;
	int j;

	p = p->next;
	for (j = 1; j < i; j++) {
		if (p)
			p = p->next;
		else
			break;
	}
	if (!p || i < 1) {
		printf("error!!请输入正确的i值！！\n");

		return 0;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return 1;
}

LinkList CreateList_L(LinkList head) {
	ElemType temp;
	LinkList p;

	printf("请输入节点值（输入0结束）：");
	fflush(stdin);
	scanf_s("%c", &temp);
	while (temp != '0') {
		if (('A' <= temp && temp <= 'Z') || ('a' <= temp && temp <= 'z')) {
			p = (LinkList)malloc(sizeof(LNode));
			p->data = temp;
			p->next = head->next;
			head->next = p;
		}
		printf("请输入节点值（输入0结束）：");
		fflush(stdin);
		scanf_s("%c", &temp);
	}

	return head;
}

int ListDel_L(LinkList head, int i) {
	LinkList p, tmp;
	int j;
	p = head->next;
	tmp = head;

	for (j = 1; j < i; j++) {
		if (p) {
			p = p->next;
			tmp = tmp->next;
		}
		else
			break;
	}
	if (!p || i < 1) {
		printf("error!请输入正确的i值！！\n");

		return 0;
	}
	tmp->next = p->next;
	free(p);

	return 1;
}

void ListPint_L(LinkList head) {
	LinkList p;
	int i = 0;

	p = head->next;
	while (p != NULL) {
		i++;
		printf("第%d个元素是：", i);
		printf("%c\n", p->data);
		p = p->next;
	}
}

int main(void) {
	int i;
	char cmd, e;
	LinkList head;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	CreateList_L(head);
	ListPint_L(head);
	do {
		printf("i,I...插入\n");
		printf("d,D...删除\n");
		printf("q,Q...退出\n");
		do {
			fflush(stdin);
			scanf_s("%c", &cmd);
		} while ((cmd != 'd') && (cmd != 'D') && (cmd != 'q') && (cmd != 'Q') && (cmd != 'i') && (cmd != 'I'));
		switch (cmd) {
		case 'i':
		case 'I':
			printf("请输入你要插入的数据：");
			fflush(stdin);
			scanf_s("%c", &e);
			printf("请输入你要插入的位置：");
			scanf_s("%d", &i);
			ListInsert_L(head, i, e);
			ListPint_L(head);
			break;
		case 'd':
		case 'D':
			printf("请输入你要删除元素的位置：");
			fflush(stdin);
			scanf_s("%d", &i);
			ListDel_L(head, i);
			ListPint_L(head);
			break;
		}
	} while ((cmd != 'q') && (cmd != 'Q'));

	return 0;
}