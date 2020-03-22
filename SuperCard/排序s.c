#pragma once
#include"Ԥ������.c"
#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
stu* insert(stu*, stu);		//����
stu* fcreateline(int);		//�ļ����� 0.�ϳ� 1.Ŀǰ
stu* store(stu*, int);		//�����棺0.���� 1.Ŀǰ


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
	case 00:sort00(head); break;	//ѧ��		��С����
	case 10:sort10(head); break;	//����
	case 20:sort20(head); break;	//���
	case 30:sort30(head); break;	//����
	case 40:sort40(head); break;	//����

	case 01:sort01(head); break;	//ѧ��		�Ӵ�С
	case 11:sort11(head); break;	//����
	case 21:sort21(head); break;	//���
	case 31:sort31(head); break;	//����
	case 41:sort41(head); break;	//����
	default:
		break;
	}
}

//ѧ������0
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

//��������0
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

//�������0
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

//��������0
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

//��������0
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



//ѧ������1
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

//��������1
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

//�������1
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

//��������1
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

//��������1
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