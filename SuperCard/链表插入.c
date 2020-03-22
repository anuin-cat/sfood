#pragma once
#include"预处理定义.c"
#include <malloc.h>

stu* insert(stu* head, stu s) {
	stu *p=head, *q, *o;
	o = (stu*)malloc(sizeof(stu));
	*o = s;
	o->next = NULL;
	
	//空链表插入
	if (head == NULL) {
		return o;
	}
	//输入的学号最大
	if (s.num > head->num)
	{
		o->next = head, head = o;
		return head;
	}
	//链表中只有一个元素，输入学号较小
	if (head->next == NULL) 
	{
		head->next = o;
		return head;
	}


	//链表中多于一个元素

	//插入位置检测
	while (p != NULL && s.num <= p->num)
		q=p,p = p->next;
	//插入
	q->next = o;
	o->next = p;
	return head;
}