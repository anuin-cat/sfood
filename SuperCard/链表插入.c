#pragma once
#include"Ԥ������.c"
#include <malloc.h>

stu* insert(stu* head, stu s) {
	stu *p=head, *q, *o;
	o = (stu*)malloc(sizeof(stu));
	*o = s;
	o->next = NULL;
	
	//���������
	if (head == NULL) {
		return o;
	}
	//�����ѧ�����
	if (s.num > head->num)
	{
		o->next = head, head = o;
		return head;
	}
	//������ֻ��һ��Ԫ�أ�����ѧ�Ž�С
	if (head->next == NULL) 
	{
		head->next = o;
		return head;
	}


	//�����ж���һ��Ԫ��

	//����λ�ü��
	while (p != NULL && s.num <= p->num)
		q=p,p = p->next;
	//����
	q->next = o;
	o->next = p;
	return head;
}