#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}Lnode, * LinkList;

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