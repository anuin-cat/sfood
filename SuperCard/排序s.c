#pragma once
#include"预处理定义.c"
#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
stu* insert(stu*, stu);		//插入
stu* fcreateline(int);		//文件加载 0.废除 1.目前
stu* store(stu*, int);		//链表储存：0.废弃 1.目前


stu* sort(stu* head,int n) {
	stu* sort00(stu * );
	stu* sort10(stu * );
	stu* sort20(stu * );
	stu* sort30(stu * );
	stu* sort40(stu * );

	stu* sort01(stu*);
	stu* sort11(stu*);
	stu* sort21(stu*);
	stu* sort31(stu*);
	stu* sort41(stu*);

	switch (n)
	{
	case 00:sort00(head); break;	//学号		从小到大
	case 10:sort10(head); break;	//日期
	case 20:sort20(head); break;	//金额
	case 30:sort30(head); break;	//次数
	case 40:sort40(head); break;	//类型

	case 01:sort01(head); break;	//学号		从大到小
	case 11:sort11(head); break;	//日期
	case 21:sort21(head); break;	//金额
	case 31:sort31(head); break;	//次数
	case 41:sort41(head); break;	//类型
	default:
		break;
	}
}

//学号排序0
stu* sort00(stu*head) {
	stu* p=head, * p1=head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;
	
	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->num < p->num) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}

//日期排序0
stu* sort10(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->dateDeal < p->dateDeal) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}

//金额排序0
stu* sort20(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->sumDeal < p->sumDeal) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}

//次数排序0
stu* sort30(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->numDeal < p->numDeal) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}

//类型排序0
stu* sort40(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->typeDeal < p->typeDeal) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}



//学号排序1
stu* sort01(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->num > p->num) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}

//日期排序1
stu* sort11(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->dateDeal > p->dateDeal) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}

//金额排序1
stu* sort21(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->sumDeal > p->sumDeal) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}

//次数排序1
stu* sort31(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->numDeal > p->numDeal) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}

//类型排序1
stu* sort41(stu* head) {
	stu* p = head, * p1 = head;
	stu* q, * q1;
	stu swap;
	while (head == NULL || head->next == NULL)
		return head;

	for (; p->next != NULL; p = p->next) {
		for (p1 = p; p1 != NULL; p1 = p1->next) {
			if (p1->typeDeal > p->typeDeal) {
				q = p->next;
				q1 = p1->next;
				swap = *p;
				*p = *p1;
				*p1 = swap;
				p->next = q;
				p1->next = q1;
			}
		}
	}
	return NULL;
}